#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    while (n > 0)
    {
        ans += n % k + 1;
        n /= k;
    }
    cout << ans - 1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}