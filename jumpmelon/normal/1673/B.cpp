#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000, K = 26;
char S[MAXN + 1];
int C[MAXN + 1][K];
int Prev[K], Exists[K];

int main() {
    int kase;
    scanf("%d", &kase);
    while (kase--) {
        int n;
        scanf("%s", S);
        n = (int)strlen(S);
        memset(C[0], 0, sizeof(int[K]));
        memset(Exists, 0, sizeof(int[K]));
        for (int i = 0; i < n; i++) {
            memcpy(C[i + 1], C[i], sizeof(int[K]));
            C[i + 1][S[i] - 'a']++;
            Exists[S[i] - 'a'] = 1;
        }
        memset(Prev, -1, sizeof(int[K]));
        for (int i = 0; i < n; i++) {
            if (Prev[S[i] - 'a'] != -1) {
                for (int j = 0; j < K; j++)
                    if (Exists[j] && C[i + 1][j] - C[Prev[S[i] - 'a']][j] < 1)
                        goto fail;
            }
            Prev[S[i] - 'a'] = i;
        }
        puts("YES");
        continue;
    fail:
        puts("NO");
    }
    return 0;
}