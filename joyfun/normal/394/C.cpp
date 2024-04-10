#include <stdio.h>
#include <string.h>

int n, m, i, j;
int num10, num00, num11;
char str[10], ans[1005][1005][4];

int main() {
    num10 = num00 = num11 = 0;
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) {
            scanf("%s", str);
            if (strcmp(str, "00") == 0)
                num00++;
            if (strcmp(str, "01") == 0 || strcmp(str, "10") == 0)
                num10++;
            if (strcmp(str, "11") == 0)
                num11++;
        }
    
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            strcpy(ans[i][j], "00");
    i = 0; j = 0;
    while (num11) {
        strcpy(ans[i][j], "11");
        j++;
        if (j == m) {
            j = 0;
            i++;
        }
        num11--;
    }
    int jj = m - 1;
    while (num10) {
        strcpy(ans[i][jj], "10");
        num10--;
        if (jj == j) break;
        jj--;
    }
    i++;
    jj = m - 1;
    while (num10) {
        strcpy(ans[i][jj], "01");
        num10--;
        if (jj == j) break;
        jj--;
    }
    int flag = 0; j--;
    if (j == -1) {
        j = m - 1;
        i++;
    }
    while (num10) {
        if (flag == 0)
            strcpy(ans[i][j], "01");
        else
            strcpy(ans[i][j], "10");
        j--;
        if (j == -1) {
            j = m - 1;
            i++;
            flag = 1 - flag;
        }
        num10--;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m - 1; j++) {
            printf("%s ", ans[i][j]);
        }
        printf("%s\n", ans[i][j]);
    }
    return 0;
}