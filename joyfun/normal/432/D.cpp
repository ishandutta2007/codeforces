#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f
const int N = 100005;

char s[N];
int next[N], n, ans[N], ansn = 0;


void get_next(char *seq, int m) {
    next[1] = 0;
    int j = next[1];
    for (int i = 2; i <= m; i++) {
        while (j && seq[i] != seq[j + 1]) j = next[j];
        if (seq[i] == seq[j + 1]) j++;
        next[i] = j;
    }
}

int vis[N];

int main() {
        int i = 0;
        scanf("%s", s + 1);
        n = strlen(s + 1);
        get_next(s, n);
        int t = next[n];
        while (t) {
            ans[ansn++] = t;
            t = next[t];
        }
        for (i = n; i > 0; i--)
            vis[next[i]]++;
        for (i = n; i > 0; i--)
            vis[next[i]] += vis[i];
        printf("%d\n", ansn + 1);
        for (i = ansn - 1; i >= 0; i--)
            printf("%d %d\n", ans[i], vis[ans[i]] + 1);
        printf("%d %d\n", n, vis[n] + 1);
    return 0;
}