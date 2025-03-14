#include <stdio.h>

int main() {
    FILE *file;
    char content[255];

    // 1. Create and Write Data to a File
    file = fopen("example.txt", "w"); // "w" mode for creating and writing
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }
    fprintf(file, "This is a test file.\n");
    fprintf(file, "We are writing some data into this file.\n");
    printf("Data written to the file successfully.\n");
    fclose(file);  // Close the file after writing

    // 2. Read Data from the File
    file = fopen("example.txt", "r"); // "r" mode for reading
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }
    printf("\nData read from the file:\n");
    while (fgets(content, sizeof(content), file) != NULL) {
        printf("%s", content);
    }
    fclose(file);  // Close the file after reading

    // 3. Append Data to the File
    file = fopen("example.txt", "a"); // "a" mode for appending
    if (file == NULL) {
        printf("Error opening file for appending.\n");
        return 1;
    }
    fprintf(file, "Appending new data to the file.\n");
    printf("\nData appended to the file successfully.\n");
    fclose(file);  // Close the file after appending

    // 4. Read Data from the File Again After Appending
    file = fopen("example.txt", "r"); // "r" mode for reading
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }
    printf("\nData after appending:\n");
    while (fgets(content, sizeof(content), file) != NULL) {
        printf("%s", content);
    }
    fclose(file);  // Close the file after reading

    return 0;
}
