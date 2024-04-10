
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <time.h>
#include <iomanip>
#include <bitset>

using namespace std;
typedef long long ll;

const ll INF = 1e18;
ll n, k, x;
ll a[500];
ll dp[201][201];
ll ans = -1;

signed main()
{
    cin >> n >> k >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i <= 200; i++)
    {
        for (int j = 0; j <= 200; j++)
        {
            dp[i][j] = -INF;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < x; j++)
        {
            for (int l = max(i - k, 0LL); l < i; l++)
            {
                dp[i][j + 1] = max(dp[i][j + 1], dp[l][j] + a[i]);
                if (j + 1 == x && n - i < k)
                {
                    ans = max(ans, dp[i][j + 1]);
                }
            }
        }
    }
    cout << ans;
}