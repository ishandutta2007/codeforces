#include <stdio.h>
#include <string.h>

char c;

int main() {
    int num[3], s = 0; 
    memset(num, 0, sizeof(num));
    while ((c = getchar()) != EOF && c != '\n') {
        if (c == '+' || c == '=') s++;
        else num[s]++;
    }
    if (num[0] - 1 + num[1] == num[2] + 1) {
        if (num[0] == 1) num[1]--;
        else if (num[1] == 1) num[0]--;
        else if (num[0] != 1 && num[1] != 1) num[0]--;
        num[2]++;
    }
    else if (num[0] + num[1] == num[2]) {
    
    }
    else if (num[0] + 1 + num[1] == num[2] - 1) {
        if (num[2] == 1) {
            printf("Impossible\n");
            return 0;
        }
        num[2]--;
        num[0]++;
    }
    else {
        printf("Impossible\n");
        return 0;
    }
    int i;
    for (i = 0; i < num[0]; i++)
        printf("|");
    printf("+");
    for (i = 0;i < num[1]; i++)
        printf("|");
    printf("=");
    for (i = 0; i < num[2]; i++)
        printf("|");
    printf("\n");
    return 0;
}