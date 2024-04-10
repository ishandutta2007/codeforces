#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

#define all(x) (x).begin(), (x).end()

int Root(int x, vi &root)
{
    if (x == root[x]) return x;
    return root[x] = Root(root[x], root);
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    struct road{
        int x, y, s;
    };
    vector<road> E(m);
    for (int i = 0; i < m; i++)
    {
        cin >> E[i].x >> E[i].y >> E[i].s;
        E[i].x--, E[i].y--;
    }
    sort(all(E), [&](road A, road B){
         return A.s < B.s;
         });
    vector<int> root(n), sz(n);
    for (int i = 0; i < n; i++) root[i] = i;
    ll ans = 0;
    for (int i = 0; i < m; i++)
    {
        int f = E[i].x, t = E[i].y;
        f = Root(f, root);
        t = Root(t, root);
        if (f == t) continue;
        ans += max(0, E[i].s - k);
        if (sz[f] > sz[t]) swap(f, t);
        sz[t] += sz[f];
        root[f] = t;
    }
    if (ans == 0)
    {
        int z = 1e9;
        for (int i = 0; i < m; i++)
            z = min(z, abs(E[i].s - k));
        cout << z << "\n";
    }
    else
    {
        cout << ans << "\n";
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