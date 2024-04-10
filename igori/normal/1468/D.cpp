#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

#define all(x) (x).begin(), (x).end()

void solve()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    a--, b--;
    if (a > b)
    {
        a = n - 1 - a;
        b = n - 1 - b;
    }
    int lim = b - a - 1;
    int sec = b;
    vector<int> s(m);
    for (int i = 0; i < m; i++) cin >> s[i];
    sort(all(s));
    int L = 0, R = min(lim, m) + 1;
    while (L + 1 < R)
    {
        int M = (L + R) / 2;
        int t = 1, tm = 0;
        for (int i = M - 1; i >= 0; i--)
        {
            int exp = tm + s[i];
            if (exp >= sec) t = 0;
            tm++;
        }
        if (t) L = M;
        else R = M;
    }
    cout << L << "\n";
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