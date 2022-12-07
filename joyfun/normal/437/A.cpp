#include <stdio.h>
#include <string.h>

char str[4][105];

int main() {
    int i, j, flag = 0;
    char ans = 'C';
    for (i = 0; i < 4; i++)
        scanf("%s", str[i]);
    for (i = 0; i < 4; i++) {
        int s = 0, l = 0;
        for (j = 0; j < 4; j++) {
            if (i == j) continue;
            int a = strlen(str[i]) - 2;
            int b = strlen(str[j]) - 2;
            if (a * 2 <= b)
                s++;
            if (a >= b * 2)
                l++;                
        }
        if (s == 3 || l == 3) {
            ans = i + 'A';
            flag++;
        }
    }
    if (flag != 1) ans = 'C';
    printf("%c\n", ans);
    return 0;
}