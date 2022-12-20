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

#define MAXN 100010

vector<int> adj[MAXN];
int out[MAXN];

int dfs(int curr, int layer) {
    //int numchildren = 0;
    out[curr] = 0;
    int smchildren = 0;
    for (int nxt : adj[curr]) {
        if (out[nxt] == 1e9) {
            //numchildren++;
            smchildren += dfs(nxt, layer+1);
        }
    }

    if (layer != 0 && (layer % 2 == 0)) {
        // -1
        out[curr] = -1*smchildren - 1;
        return -1;
    } else if (layer != 0) {
        out[curr] = -1*smchildren + 1;
        return 1;
    }
    out[curr] = -1*smchildren;
    return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            adj[i].clear();
            out[i] = 1e9;
        }
        for (int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        dfs(0, 0);
        for (int i = 0; i < n; i++) cout << out[i] << ' ';
        cout << '\n';
    }
}