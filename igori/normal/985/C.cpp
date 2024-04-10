#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    int n, k, l;
    cin >> n >> k >> l;
    vector<int> a(n * k);
    for (int i = 0; i < n * k; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int mx = a[0] + l;
    ll ans = 0;
    int have = 0;
    for (int i = n * k - 1; i >= 0; i--)
    {
        have++;
        if (have >= k && a[i] <= mx)
        {
            have -= k;
            ans += a[i];
        }
    }
    if (have > 0) cout << 0 << "\n";
    else cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}