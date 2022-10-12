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
#include <unordered_map>

using namespace std;

typedef long long ll;
#define pb push_back
#define sz size()

ll n;
ll a[100000];
ll dp[2][1000300];

signed main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        vector<int> d;
        for (int j = 1; j * j <= a[i]; j++)
        {
            if (a[i] % j == 0)
            {
                d.pb(j);
                if (j != a[i] / j)
                    d.pb(a[i] / j);
            }
        }
        for (auto j : d)
        {
            dp[1][j] = dp[0][j - 1] % 1000000007;
        }
        for (auto j : d)
        {
            dp[0][j] = (dp[1][j] + dp[0][j]) % 1000000007;
            dp[1][j] = 0;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= 1000000; i++)
        ans = (ans + dp[0][i]) % 1000000007;
    cout << ans;
}