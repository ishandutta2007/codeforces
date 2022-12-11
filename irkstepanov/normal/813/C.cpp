#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

vector<vector<int> > g;
vector<int> depth, h;

void dfs(int v, int p, int x)
{
    h[v] = x;
    depth[v] = 0;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs(to, v, x + 1);
        depth[v] = max(depth[v], depth[to] + 1);
    }
}

vector<int> dist;

void dfs2(int v, int p, int x)
{
    dist[v] = x;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs2(to, v, x + 1);
    }
}

int main()
{

    //ifstream cin("input.txt");
	//ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin >> n >> x;
    --x;

    g.resize(n);
    depth.resize(n);
    h.resize(n);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(0, 0, 0);

    dist.resize(n);
    dfs2(x, x, 0);

    int ans = 0;
    for (int v = 0; v < n; ++v) {
        if (dist[v] < h[v]) {
            ans = max(ans, 2 * h[v]);
        }
    }

    cout << ans << "\n";

}