// KingPonyHead
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, m, q, A[N], dp[N], SF[N], P[N];
set < int > S[3];
int main()
{
    int k[3];
    scanf("%d%d%d", &k[0], &k[1], &k[2]);
    n = k[0] + k[1] + k[2];
    for (int i = 0; i < 3; i ++)
        for (int j = 0, a; j < k[i]; j ++)
            scanf("%d", &a), S[i].insert(a);
    for (int i = 1; i <= n; i ++)
    {
        P[i] = P[i - 1] + S[0].count(i);
        dp[i] = max(dp[i - 1] + (int)S[1].count(i), P[i]);
    }
    int Mx = 0;
    for (int i = n; i; i --)
        SF[i] = SF[i + 1] + S[2].count(i);
    for (int i = 1; i <= n + 1; i ++)
        Mx = max(Mx, dp[i - 1] + SF[i]);
    printf("%d\n", n - Mx);
    return 0;
}