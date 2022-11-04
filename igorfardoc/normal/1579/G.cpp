#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<vector<int>> dp(n, vector<int>(2001));
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = 0; j <= 2000; ++j)
            {
                if(i == n - 1)
                {
                    if(a[i] <= j)
                    {
                        dp[i][j] = 0;
                    }
                    else
                    {
                        dp[i][j] = a[i];
                    }
                    continue;
                }
                dp[i][j] = a[i] + dp[i + 1][min(j + a[i], 2000)];
                if(j >= a[i])
                {
                    dp[i][j] = min(dp[i][j], max(dp[i + 1][j - a[i]] - a[i], 0));
                }
            }
        }
        int ans = 100000;
        for(int i = 0; i <= 2000; i++)
        {
            ans = min(ans, i + dp[0][i]);
        }
        cout << ans << '\n';
    }
}