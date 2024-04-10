#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5000;
int P[MAXN + 1], C1[MAXN + 1];

int main() {
    int kase;
    scanf("%d", &kase);
    while (kase--) {
        int n;
        long long ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &P[i]);
        memset(C1 + 1, 0, sizeof(int[n]));
        for (int b = 1; b <= n; b++) {
            int c2 = 0;
            for (int c = n; c > b; c--) {
                ans += (long long)C1[P[c] - 1] * c2;
                if (P[c] < P[b])
                    c2++;
            }
            for (int x = P[b]; x <= n; x++)
                C1[x]++;
        }
        printf("%lld\n", ans);
    }
    return 0;
}