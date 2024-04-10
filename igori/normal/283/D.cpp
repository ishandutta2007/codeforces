const int N = 5002;

#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

typedef long long ll;

int n, dp[N];
ll a[N];

signed main()
{
    //freopen("subrev.in", "r", stdin);
    //freopen("subrev.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = n - 1; i >= 0; i--) dp[i] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        ll x = a[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (x % 2 != 0)
            {
                if (a[j] % x == 0)
                    dp[j] = max(dp[j], dp[i] + 1);
            }
            else
            {
                if (a[j] % x != 0 && a[j] % (x / 2) == 0)
                    dp[j] = max(dp[j], dp[i] + 1);
            }
            if (x % 2 == 0)
                x /= 2;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dp[i]);
    }
    cout << n - ans;
}

/* Note:
Check constants at the beginning of the code.
    N is set to 4e5 but be careful in problems with large constant factor.
    Setting N in every problem is more effective.
Check corner cases.
    N = 1
No def int long long for now.
Add something here.
*/