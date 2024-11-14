#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LENGTH 100

void printHeader();
void addTask(char tasks[][MAX_LENGTH], int *taskCount);
void viewTasks(char tasks[][MAX_LENGTH], const int *completed, int taskCount);
void completeTask(int *completed, int taskCount);
void deleteTask(char tasks[][MAX_LENGTH], int *completed, int *taskCount);

int main(void) {
    char tasks[MAX_TASKS][MAX_LENGTH];
    int completed[MAX_TASKS]={0};
    int taskCount = 0;
    int choice;

    do {
        printHeader();
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Mark Task as Completed\n");
        printf("4. Delete Task\n");
        printf("5. Exit\n");

        scanf("%d", &choice);
        getchar();
        switch(choice) {
            case 1:
                addTask(tasks, &taskCount);
                break;
            case 2:
                viewTasks(tasks, completed, taskCount);
                break;
            case 3:
                completeTask(completed, taskCount);
                break;
            case 4:
                deleteTask(tasks, completed, &taskCount);
                break;
            case 5:
                printf("Exiting this program\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while(choice!=5);

    return 0;
}

void completeTask(int *completed, const int taskCount) {
    int taskNumber;
    // setColor(YELLOW);
    printf("Enter the task number to mark as completed: ");
    // setColor(RESET);
    scanf("%d", &taskNumber);

    if (taskNumber < 1 || taskNumber > taskCount) {
        // setColor(RED);
        printf("Invalid task number!\n");
        // setColor(RESET);
        return;
    }
    completed[taskNumber - 1] = 1;
    // setColor(GREEN);
    printf("Task marked as completed.\n");
    // setColor(RESET);
}

void deleteTask(char tasks[][MAX_LENGTH], int *completed, int *taskCount) {
    int taskNumber;
    // setColor(YELLOW);
    printf("Enter the task number to delete: ");
    // setColor(RESET);
    scanf("%d", &taskNumber);

    if (taskNumber < 1 || taskNumber > *taskCount) {
        // setColor(RED);
        printf("Invalid task number!\n");
        // setColor(RESET);
        return;
    }

    for (int i = taskNumber - 1; i < *taskCount - 1; i++) {
        strcpy(tasks[i], tasks[i + 1]);
        completed[i] = completed[i + 1];
    }
    (*taskCount)--;
    // setColor(GREEN);
    printf("Task deleted successfully.\n");
    // setColor(RESET);
}

void viewTasks(char tasks[][MAX_LENGTH], const int *completed, const int taskCount) {
    if (taskCount == 0) {
        // setColor(RED);
        printf("No tasks to display.\n");
        // setColor(RESET);
        return;
    }
    // setColor(BLUE);
    printf("\nTo-Do List:\n");
    // setColor(RESET);
    for (int i = 0; i < taskCount; i++) {

        printf("%d. %s [%s]\n", i + 1, tasks[i], completed[i] ? "Completed" : "Not Completed");

    }
}

void addTask(char tasks[][MAX_LENGTH], int *taskCount) {
    if(*taskCount>=MAX_LENGTH) {
        printf("Task list is full!\n");
        return;
    }
    printf("Enter the task: ");
    fgets(tasks[*taskCount], MAX_LENGTH, stdin);
    tasks[*taskCount][strcspn(tasks[*taskCount], "\n")] = '\0'; // Remove newline character
    (*taskCount)++;
    printf("Task added successfully.\n");
}


void printHeader() {
    printf("\n***************************************\n");
    printf("*        Stylish To-Do List Menu       *\n");
    printf("***************************************\n");
}