#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

#define all(x) (x).begin(), (x).end()

void solve()
{
    vector<int> c(3);
    vector<int> a(5);
    for (int i = 0; i < 3; i++) cin >> c[i];
    for (int i = 0; i < 5; i++) cin >> a[i];
    for (int i = 0; i < 3; i++) c[i] -= a[i];
    for (int i = 0; i < 3; i++) if (c[i] < 0)
    {
        cout << "NO\n";
        return;
    }
    a[3] -= min(a[3], c[0]);
    a[4] -= min(a[4], c[1]);
    if (a[3] + a[4] <= c[2])
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}