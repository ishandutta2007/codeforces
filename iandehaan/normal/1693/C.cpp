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

#define MAXN 200'010

int n, m;
vector<int> adj[MAXN];
int deg[MAXN];
int numexp[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[v].pb(u);
        deg[u]++;
    }

    int out[n];
    rep(i, 0, n) out[i] = 1e9;
    out[n-1] = 0;
    
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push(mp(0, n-1));
    while (!q.empty()) {
        pii top = q.top(); q.pop();
        //cout << top.first << ' ' << top.second << endl;
        if (top.first > out[top.second]) continue;
        for (int nxt : adj[top.second]) {
            numexp[nxt]++;
            int dist = top.first + 1 + deg[nxt]-numexp[nxt];
            if (dist < out[nxt]) {
                out[nxt] = dist;
                q.push(mp(dist, nxt));
            }
        }
    }
    cout << out[0] << '\n';


}