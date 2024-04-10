#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

int main()
{

    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<vector<int> > g(n);
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    ll ans = 1;
    int r = n - 1;
    vector<int> pos(n, -1);
    pos[p[n - 1]] = n - 1;
    for (int i = n - 2; i >= 0; --i) {
        for (int x : g[p[i]]) {
            if (pos[x] != -1) {
                r = min(r, pos[x] - 1);
            }
        }
        ans += (ll)(r - i + 1);
        pos[p[i]] = i;
    }

    cout << ans << "\n";

}