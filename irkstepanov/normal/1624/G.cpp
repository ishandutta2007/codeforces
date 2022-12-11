#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

struct edge {
    int from, to;
    int cost;
};

vector<bool> invalid;
vector<bool> attempt;
vector<edge> edges;
vector<vector<int> > g;

vector<bool> visited;

void dfs(int v) {
    visited[v] = true;
    for (int e : g[v]) {
        if (invalid[e] || !attempt[e]) {
            continue;
        }
        int to = edges[e].to + edges[e].from - v;
        if (!visited[to]) {
            dfs(to);
        }
    }
}

bool bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

const int rmax = 29;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int tt;
    cin >> tt;

    while (tt--) {
        int n, m;
        cin >> n >> m;
        g = vector<vector<int> >(n, vector<int>());
        edges.clear();
        invalid.assign(m, false);
        for (int i = 0; i < m; ++i) {
            int u, v, c;
            cin >> u >> v >> c;
            --u, --v;
            g[u].pb(sz(edges));
            g[v].pb(sz(edges));
            edges.pb({u, v, c});
        }
        int ans = 0;
        for (int r = rmax; r >= 0; --r) {
            attempt.assign(m, false);
            for (int i = 0; i < m; ++i) {
                if (!bit(edges[i].cost, r)) {
                    attempt[i] = true;
                }
            }
            visited.assign(n, false);
            dfs(0);
            bool ok = true;
            for (int i = 0; i < n; ++i) {
                if (!visited[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                for (int i = 0; i < m; ++i) {
                    if (bit(edges[i].cost, r)) {
                        invalid[i] = true;
                    }
                }
            }
            if (!ok) {
                ans |= (1 << r);
            }
        }
        cout << ans << "\n";
    }

}