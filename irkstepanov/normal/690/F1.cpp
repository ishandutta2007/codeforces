#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pll;

const int rmax = 20;

vector<vector<int> > g;
vector<int> parent;

void dfs(int v, int p = -1)
{
    parent[v] = p;
    for (int to : g[v]) {
        if (to != p) {
            dfs(to, v);
        }
    }
}

int main()
{

    //freopen("input.txt", "r", stdin);

    //ifstream cin("input.txt");

    int n;
    cin >> n;

    g.resize(n);
    parent.resize(n);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(0);

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (parent[i] != -1 && parent[parent[i]] != -1) {
            ++ans;
        }
    }

    for (int i = 0; i < n; ++i) {
        int cnt = sz(g[i]);
        if (i) {
            --cnt;
        }
        ans += (ll)(cnt) * (ll)(cnt - 1) / 2;
    }

    cout << ans << "\n";

}