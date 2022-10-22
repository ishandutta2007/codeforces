#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;
int P[MAXN + 1], Q[MAXN + 1], InvP[MAXN + 1];
int Vis[MAXN + 1];

int main() {
    int kase;
    scanf("%d", &kase);
    while (kase--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &P[i]);
        for (int i = 1; i <= n; i++)
            scanf("%d", &Q[i]);
        
        for (int i = 1; i <= n; i++)
            InvP[P[i]] = i;
        
        int np = 0;
        memset(Vis + 1, 0, sizeof(int[n]));
        for (int i = 1; i <= n; i++)
            if (!Vis[i]) {
                int t = i, len = 0;
                do {
                    Vis[t] = 1;
                    len++;
                    t = Q[InvP[t]];
                } while (t != i);
                np += len / 2;
            }
        
        long long ans = 0;
        for (int i = 0; i < np; i++) {
            ans += 2 * (n - i) - 2 * (i + 1);
        }

        printf("%lld\n", ans);
    }
    return 0;
}