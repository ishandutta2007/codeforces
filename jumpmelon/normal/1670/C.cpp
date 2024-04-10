#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000, P = 1000000007;
int A[MAXN + 5], B[MAXN + 5], D[MAXN + 5];
int InvB[MAXN + 1], Vis[MAXN + 1];

int main() {
    int kase;
    scanf("%d", &kase);
    while (kase--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &A[i]);
        for (int i = 1; i <= n; i++)
            scanf("%d", &B[i]);
        for (int i = 1; i <= n; i++)
            scanf("%d", &D[i]);
        for (int i = 1; i <= n; i++)
            InvB[B[i]] = i;

        int ans = 1;
        memset(Vis + 1, 0, sizeof(int[n]));
        for (int i = 1; i <= n; i++)
            if (!Vis[i]) {
                int t = i, flag = 1;
                do {
                    Vis[t] = 1;
                    if (D[t] || A[t] == B[t])
                        flag = 0;
                    t = InvB[A[t]];
                } while (t != i);
                if (flag)
                    ans = ans * 2 % P;
            }
        printf("%d\n", ans);
    }
    return 0;
}