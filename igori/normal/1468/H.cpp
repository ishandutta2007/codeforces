#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

#define all(x) (x).begin(), (x).end()

void solve()
{
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];
    if ((n - m) % (k - 1) != 0)
    {
        cout << "NO\n";
        return;
    }
    for (int i = 0; i < m; i++)
    {
        int L = b[i] - 1 - i;
        int U = n - b[i] - (m - 1 - i);
        if (L >= (k - 1) / 2 && U >= (k - 1) / 2)
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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