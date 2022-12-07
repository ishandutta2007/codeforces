#include <stdio.h>
#include <string.h>

char str1[105], str2[105];
int l = 0, r = 0, vis[105];

int main() {
    int i;
    memset(vis, -1, sizeof(vis));
    scanf("%s%s", str1, str2);
    int len1 = strlen(str1);
    for (i = 0; i < len1; i++) {
        if (str1[i] == '|') break;
            vis[str1[i] - 'A'] = 0;
            l++;
    }
    i++;
    for (;i<len1;i++) {
        vis[str1[i] - 'A'] = 1; r++;
    }
    int len2 = strlen(str2);
    for (i = 0; i < len2; i++)
        if (l < r) {
            l ++;
            vis[str2[i] - 'A'] = 0;
        }
        else {
            r++;
            vis[str2[i] - 'A'] = 1;
        }
    if (l != r) printf("Impossible\n");
    else {
        for (i = 0; i < 26; i++)
            if (vis[i] == 0) {
                printf("%c", i + 'A');
            }
        printf("|");
        for (i = 0; i < 26; i++)
            if (vis[i] == 1) {
                printf("%c", i + 'A');
            }
        printf("\n");
    }
    return 0;
}