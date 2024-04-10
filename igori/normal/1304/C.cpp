#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
#define prev prev228
#define all(x) (x).begin(), (x).end()
#define int long long

int t[1000], l[1000], r[1000];

int inter(int l1, int r1, int l2, int r2)
{
    if (r1 < l2 || r2 < l1) return 0;
    return 1;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    t[0] = 0, r[0] = m, l[0] = m;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i] >> l[i] >> r[i];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (inter(l[i] - (t[j] - t[i]), r[i] + (t[j] - t[i]), l[j], r[j]) == 0)
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--)
    {
        solve();
    }
}