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

vector<vector<int> > g;
vector<int> depth;

void dfs(int v, int d = 0)
{
    depth[v] = d;
    for (int to : g[v]) {
        if (depth[to] == -1) {
            dfs(to, d + 1);
        }
    }
}

int main()
{

    //freopen("input.txt", "r", stdin);

    //ifstream cin("input.txt");

    int n, m;
    cin >> n >> m;

    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    depth.assign(n, -1);
    dfs(0);

    int v = 0;
    for (int i = 1; i < n; ++i) {
        if (depth[i] > depth[v]) {
            v = i;
        }
    }

    depth.assign(n, -1);
    dfs(v);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, depth[i]);
    }

    cout << ans << "\n";

}