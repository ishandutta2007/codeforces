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
set<int> adj[MAXN];
set<int> radj[MAXN];
int deg[MAXN];
int rdeg[MAXN];

int memo[MAXN];
int dp(int curr) {
    //cout << curr << endl;
    if (memo[curr] != -1) return memo[curr];
    int out = 1;
    for (int nxt : adj[curr]) {
        out = max(out, 1+dp(nxt));
    }
    return memo[curr] = out;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].insert(v);
        radj[v].insert(u);
        deg[u]++;
        rdeg[v]++;
    }

    for (int i = 0; i < n; i++) {
        if (deg[i] == 1) {
            radj[*adj[i].begin()].erase(i);
            adj[i].clear();
        }
        if (rdeg[i] == 1) {
            adj[*radj[i].begin()].erase(i);
            radj[i].clear();
        }
    }

    memset(memo, -1, sizeof memo);
    int out = 1;
    for (int i = 0; i < n; i++) {
        out = max(out, dp(i));
    }
    cout << out << endl;
}