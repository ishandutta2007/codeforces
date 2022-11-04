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
    int r, n;
    cin >> r >> n;
    vector<int> x(n), y(n), t(n);
    for(int i = 0; i < n; i++)
    {
        cin >> t[i] >> x[i] >> y[i];
        --x[i];
        --y[i];

    }
    vector<int> dp(n, 0);
    int ans = 0;
    int max1 = 0;
    int now = -1;
    for(int i = 0; i < n; i++)
    {
        if(x[i] + y[i] > t[i])
        {
            continue;
        }
        dp[i] = 1;
        int now1 = i - 1;
        while(now1 >= 0 && t[i] - t[now1] <= 1000)
        {
            if(abs(x[i] - x[now1]) + abs(y[i] - y[now1]) <= t[i] - t[now1])
            {
                dp[i] = max(dp[i], 1 + dp[now1]);
            }
            --now1;
        }
        for(int i = now + 1; i <= now1; i++)
        {
            max1 = max(max1, dp[i]);
        }
        now = now1;
        dp[i] = max(dp[i], max1 + 1);
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
}