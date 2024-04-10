#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000, INF = 0x3f3f3f3f;
int F[MAXN + 5][4];
char M[2][MAXN + 5];

int main() {
    int kase;
    scanf("%d", &kase);
    while (kase--) {
        int n;
        scanf("%d", &n);
        scanf("%s%s", M[0], M[1]);

        F[0][0] = 0;
        F[0][1] = F[0][2] = F[0][3] = INF;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int t = (M[0][i] == '*' ? 1 : 0) | (M[1][i] == '*' ? 2 : 0);
            memset(F[i + 1], INF, sizeof(int[4]));

            for (int j = 0; j < 4; j++)
                F[i + 1][j | t] = min(F[i + 1][j | t], F[i][j] + __builtin_popcount(j));

            F[i + 1][1] = min(F[i + 1][1], F[i + 1][3] + 1);
            F[i + 1][2] = min(F[i + 1][2], F[i + 1][3] + 1);
            if (t)
                ans = min(F[i + 1][1], F[i + 1][2]);
        }
        printf("%d\n", ans);

    }
    return 0;
}