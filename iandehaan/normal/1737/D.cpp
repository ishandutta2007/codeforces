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

#define MAXN 510

constexpr ll inf = ((ll) 1) << ((ll) 55); 

vector<pair<int, ll>> adj[MAXN];
int d[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //cout << "test " << inf << endl;

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        rep(i, 0, n) {
            adj[i].clear();
            rep(j, 0, n) {
                d[i][j] = 1e8;
            }
        }
        rep(i, 0, m) {
            int u, v;
            ll w;
            cin >> u >> v >> w;
            u--; v--;
            adj[u].pb(mp(v, w));
            adj[v].pb(mp(u, w));
        }

        d[0][n-1] = 0;
        d[n-1][0] = 0;
        queue<pair<pii, int>> q;
        q.push(mp(mp(0, n-1), 0));
        q.push(mp(mp(n-1, 0), 0));
        while (!q.empty()) {
            pair<pii, int> top = q.front(); q.pop();
            int x = top.first.first;
            int y = top.first.second;
            

            for (const pair<int, ll>& nxt : adj[x]) {
                int newx = nxt.first;
                int newy = y;
                if (d[newx][newy] != 1e8) continue;
                d[newx][newy] = top.second+1;
                q.push(mp(mp(newx, newy), top.second+1));
            }
            for (const pair<int, ll>& nxt : adj[y]) {
                int newx = x;
                int newy = nxt.first;
                if (d[newx][newy] != 1e8) continue;
                d[newx][newy] = top.second+1;
                q.push(mp(mp(newx, newy), top.second+1));
            }
            if (x == y) {
                rep(i, 0, n) {
                    int newx = x;
                    int newy = i;
                    if (d[newx][newy] != 1e8) continue;
                    d[newx][newy] = top.second+1;
                    q.push(mp(mp(newx, newy), top.second+1));
                }
                rep(i, 0, n) {
                    int newx = i;
                    int newy = y;
                    if (d[newx][newy] != 1e8) continue;
                    d[newx][newy] = top.second+1;
                    q.push(mp(mp(newx, newy), top.second+1));
                }
            }
        }

        ll out = inf;

        rep(i, 0, n) {
            for (const pair<int, ll>& nxt : adj[i]) {
                ll mydist = d[i][nxt.first];
                //cout << i << ' ' << nxt.first << ' ' << mydist << endl;
                out = min(out, (mydist+1)*nxt.second);
            }
        }
        cout << out << endl;
    }
}