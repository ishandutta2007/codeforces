#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

#define MAXN 200010
int par[MAXN];

int getPar(int x) {
    if (par[x] == x) return x;
    return par[x] = getPar(par[x]);
}

void Union(int x, int y) {
    par[getPar(x)] = getPar(y);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--;
            v--;
            if (u > v) swap(u, v);
            adj[u].pb(mp(v, w));
        }

        int out = 0;

        while (true) {
            // Build edges
            vector<pair<int, pair<int, int>>> edges;
            for (int i = 0; i < n; i++) {
                for (pair<int, int> e : adj[i]) {
                    edges.pb(mp(e.second, mp(i, e.first)));
                }
            }
            sort(all(edges));

            for (int i = 0; i < n; i++) par[i] = i;

            int ans = 0;

            for (auto e : edges) {
                int cost = e.first;
                int u = e.second.first;
                int v = e.second.second;

                if (getPar(u) != getPar(v)) {
                    Union(u, v);
                    ans |= cost;
                }
            }

            //cout << "mst |= cost " << ans << endl;

            if (ans == 0) break;

            

            for (int bit = 30; bit >= 0; bit--) {
                if (ans & (1 << bit)) {
                    //cout << "getting rid of " << bit << endl;
                    // set bit
                    out |= (1 << bit);

                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < sz(adj[i]); j++) {
                            if (adj[i][j].second & (1 << bit)) {
                                adj[i][j].second ^= (1 << bit);
                                //cout << "new weight " << adj[i][j].second << endl;
                            }
                        }
                    }

                    break;
                }
            }
        }

        cout << out << '\n';
    }
}