#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll si = accumulate(a.begin(), a.end(), 0LL);
    if (si % k != 0)
    {
        cout << "No\n";
        return;
    }
    ll x = si / k;
    vector<int> ans;
    int cur = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cur += a[i];
        cnt ++;
        if (cur > x)
        {
            cout << "No\n";
            return;
        }
        if (cur == x)
        {
            ans.push_back(cnt);
            cur = 0;
            cnt = 0;
        }
    }
    cout << "Yes\n";
    for (auto e : ans) cout << e << " ";
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