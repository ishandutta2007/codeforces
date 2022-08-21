#include <bits/stdc++.h>
using namespace std;

#define N 1511
char s[N];
int ans[26][N];
int main() {
    int n, q;
    scanf("%d%s%d", &n, s, &q);
    for (int i = 0; i < n; i++) s[i] -= 'a';
    for (int c = 0; c < 26; c++) {
        for (int i = 0; i <= n; i++) {
            ans[c][i] = i;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i, ct = 0, ln = 1; ln <= n; j++, ln++) {
            ct += j >= n || s[i] != s[j];
            ans[s[i]][ln] = min(ans[s[i]][ln], ct);
        }
    }

    while (q--) {
        int m;
        scanf("%d%s", &m, s);
        *s -= 'a';
        int L = 0, R = n + 1;
        while (R - L > 1) {
            int M = L + R >> 1;
            (ans[*s][M] <= m ? L : R) = M;
        }
        printf("%d\n", L);
    }
}