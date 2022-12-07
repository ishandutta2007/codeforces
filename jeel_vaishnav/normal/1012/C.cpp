#include <bits/stdc++.h>

using namespace std;

const int N = 50, M = 50;
#define pb push_back

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);

    int n;
    cin >> n;

    long long a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    if(n == 1) {
        cout << "0";
        return 0;
    }

    int k = (n - 1) / 2 + 1;

    long long dp[n + 1][k + 1][2];
    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= k; ++j)
            for(int l = 0; l < 2; ++l)
                dp[i][j][l] = (long long)1e18;

    long long reqCost = 0;
    if(a[1] >= a[0])
        reqCost += a[1] - a[0] + 1;
    dp[0][0][0] = 0;
    dp[1][0][0] = 0;
    dp[1][1][1] = reqCost;

    for(int i = 2; i <= n; ++i) {
        dp[i][0][0] = 0;
        for(int j = 1; j <= k; ++j) {
            dp[i][j][0] = min(dp[i - 1][j][0], dp[i - 1][j][1]);
            
            // not selected before
            if(dp[i - 2][j - 1][0] != (long long)1e18) {
                reqCost = 0;

                if(a[i - 2] >= a[i - 1])
                    reqCost += a[i - 2] - a[i - 1] + 1;

                if(i < n && a[i] >= a[i - 1])
                    reqCost += a[i] - a[i - 1] + 1;

                dp[i][j][1] = dp[i - 2][j - 1][0] + reqCost;
            }

            // selected before
            if(i >= 3 && dp[i - 2][j - 1][1] != (long long)1e18) {
                reqCost = 0;

                long long newEle = min(a[i - 2], a[i - 3] - 1L);
                if(newEle >= a[i - 1])
                    reqCost += newEle - a[i - 1] + 1;

                if(i < n && a[i] >= a[i - 1])
                    reqCost += a[i] - a[i - 1] + 1;

                dp[i][j][1] = min(dp[i][j][1], dp[i - 2][j - 1][1] + reqCost);
            }
        }
    }

    for(int j = 1; j <= k; ++j)
        cout << min(dp[n][j][0], dp[n][j][1]) << " ";


    return 0;
}