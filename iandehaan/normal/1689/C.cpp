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

#define MAXN 300'010

int n;
vector<int> adj[MAXN];
int depth[MAXN];
int cheapest;

void dfs(int curr) {
    int numc = 0;
    for (int nxt : adj[curr]) {
        if (depth[nxt] == -1) {
            depth[nxt] = depth[curr]+1;
            numc++;
            dfs(nxt);
        }
    }
    //cout << curr << ' ' << depth[curr] + depth[curr] 
    if (numc <= 1) cheapest = min(cheapest, depth[curr]+depth[curr]-1+numc);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        rep(i, 0, n) {
            adj[i].clear();
            depth[i] = -1;
            cheapest = n;
        }

        rep(i, 0, n-1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        depth[0] = 1;
        dfs(0);



        cout << n-cheapest << '\n';
    }
}