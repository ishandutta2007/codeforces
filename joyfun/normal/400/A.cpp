#include <stdio.h>
#include <string.h>

int t, n;
char str[15];
char save[15][15];

bool judge(int a, int b) {
    int i, j;
    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++)
            save[i][j] = str[i * b + j];
    }
    for (i = 0; i < b; i++) {
        for (j = 0; j < a; j++) {
            if (save[j][i] != 'X') break;
        }
        if (j == a) return true;
    }
    return false;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%s", str);
        int ans = 0;
        if (judge(1, 12)) ans++;
        if (judge(2, 6)) ans++;
        if (judge(3, 4)) ans++;
        if (judge(4, 3)) ans++;
        if (judge(6, 2)) ans++;
        if (judge(12, 1)) ans++;
        printf("%d", ans);
        if (judge(1, 12)) printf(" 1x12");
        if (judge(2, 6)) printf(" 2x6");
        if (judge(3, 4)) printf(" 3x4");
        if (judge(4, 3)) printf(" 4x3");
        if (judge(6, 2)) printf(" 6x2");
        if (judge(12, 1)) printf(" 12x1");
        printf("\n");
    }
    return 0;
}