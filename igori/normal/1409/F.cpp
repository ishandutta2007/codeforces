#include <bits/stdc++.h>

using namespace std;

const int INF = 88888888;
const int N = 203;

int dp[N][N][N];

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    string t;
    cin >> s >> t;
    if (t[0] == t[1])
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == t[0]) cnt++;
        }
        cnt += k;
        cnt = min(cnt, n);
        cout << cnt * (cnt - 1) / 2;
        return 0;
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == t[0]) b[i] = 0;
        else if (s[i] == t[1]) b[i] = 1;
        else b[i] = -1;
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int z = 0; z <= n; z++)
            {
                dp[i][j][z] = -INF;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            for (int z = 0; z <= k; z++)
            {
                if (b[i] == -1)
                {
                    dp[i + 1][j][z] = max(dp[i + 1][j][z], dp[i][j][z]);
                    dp[i + 1][j + 1][z + 1] = max(dp[i + 1][j + 1][z + 1], dp[i][j][z]);
                    dp[i + 1][j][z + 1] = max(dp[i + 1][j][z + 1], dp[i][j][z] + j);
                }
                if (b[i] == 0)
                {
                    dp[i + 1][j + 1][z] = max(dp[i + 1][j + 1][z], dp[i][j][z]);
                    dp[i + 1][j][z + 1] = max(dp[i + 1][j][z + 1], dp[i][j][z] + j);
                }
                if (b[i] == 1)
                {
                    dp[i + 1][j + 1][z + 1] = max(dp[i + 1][j + 1][z + 1], dp[i][j][z]);
                    dp[i + 1][j][z] = max(dp[i + 1][j][z], dp[i][j][z] + j);
                }
            }
        }
    }
    int ans = 0;
    for (int j = 0; j <= n; j++)
    {
        for (int z = 0; z <= k; z++)
        {
            ans = max(ans, dp[n][j][z]);
        }
    }
    cout << ans;
}