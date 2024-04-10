// KingPonyHead
#include<bits/stdc++.h>
using namespace std;
const int N = 3003, Mod = 998244353;
int n, m, q, A[N], dp[N][N], dp2[N][N];
string T, S;
inline void Add(int &a, int b)
{
    a += b;
    if (a >= Mod)
        a -= Mod;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> S >> T;
    n = (int)S.size();
    m = (int)T.size();
    T = "#" + T;
    S = "#" + S;
    for (int l = 0; l < m; l ++)
        dp[l][l + 1] = 1;
    int tot = 0;
    for (int i = 1; i <= n; i ++)
    {
        for (int l = 0; l <= m; l ++)
        {
            int r = min(l + i, m + 1);
            if (l > 0 && S[i] == T[l])
                Add(dp[l - 1][r], dp[l][r]);
            if (r <= m && S[i] == T[r])
                Add(dp[l][r + 1], dp[l][r]);
        }
        Add(tot, dp[0][m + 1]);
    }
    dp2[n + 1][0] = 1;
    for (int i = n; i; i --)
    {
        Add(dp2[i][0], 1);
        Add(dp2[i][m], dp2[i + 1][m]);
        for (int j = 0; j <= m; j ++)
            Add(dp2[i][j], dp2[i + 1][j]);
        for (int j = 1; j <= m; j ++)
            if (S[i] == T[j])
                Add(dp2[i][j], dp2[i + 1][j - 1]);
    }
    Add(tot, dp2[1][m]);
    printf("%d\n", tot);
    return 0;
}