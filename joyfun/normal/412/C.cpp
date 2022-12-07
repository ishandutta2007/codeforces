#include <stdio.h>
#include <string.h>

const int N = 100005;

int n, vis[N], i, j;
char str[N];
char ans[N];

int main() {
    scanf("%d", &n);
    int len;
    for (i = 0; i < n; i++) {
        scanf("%s", str);
        len = strlen(str);
        if (i == 0) {
            for (j = 0; j < len; j++)
                ans[j] = '?';
        }
        for (j = 0; j < len; j++) {
            if (vis[j]) continue;
            if (ans[j] == '?') {
                ans[j] = str[j];
            }
            else {
                if (str[j] == '?')
                    continue;
                if (ans[j] != str[j])
                    vis[j] = 1;
            }
        }
    }
    for (i = 0; i < len; i++) {
        if (vis[i]) printf("?");
        else if (ans[i] == '?') printf("a");
        else printf("%c", ans[i]);
    }
    printf("\n");
    return 0;
}