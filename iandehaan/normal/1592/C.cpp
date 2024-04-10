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

#define MAXN 100'010

int n, k;
vector<int> adj[MAXN];
int a[MAXN];
vector<int> children[MAXN];
int xroot[MAXN];
int par[MAXN];
int xorr;
void dfs(int curr) {
    xroot[curr] = a[curr];
    for (int nxt : adj[curr]) {
        if (xroot[nxt] != -1) continue;
        children[curr].pb(nxt);
        par[nxt] = curr;
        dfs(nxt);
        xroot[curr] ^= xroot[nxt];
    }
}

int getx(int curr, int prev) {
    if (prev == par[curr]) {
        return xroot[curr];
    }

    return xorr ^ xroot[prev];
}

map<pii, bool> memo;
bool hasx(int curr, int prev) {
    pii key = mp(curr, prev);
    if (memo.count(key)) return memo[key];
    if (getx(curr, prev) == xorr) return memo[key] = true;
    for (int nxt : adj[curr]) {
        if (nxt == prev) continue;
        if (hasx(nxt, curr)) {
            for (int nxt2 : adj[curr]) {
                if (nxt != nxt2) memo[mp(curr, nxt2)] = true;
            }
            return true;
        }
    }
    for (int nxt : adj[curr]) {
        memo[mp(curr, nxt)] = false;
    }
    return memo[key] = false;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        xorr = 0;
        par[0] = -1;
        memo.clear();
        rep(i, 0, n) {
            cin >> a[i];
            xorr ^= a[i];
            children[i].clear();
            adj[i].clear();
            xroot[i] = -1;
        }

        rep(i, 0, n-1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        dfs(0);

        if (xorr == 0) {
            cout << "YES\n";
            continue;
        }

        if (k == 2) {
            cout << "NO\n";
            continue;
        }

        bool ok = false;
        rep(i, 0, n) {
            for (int nxt : adj[i]) {
                if (hasx(i, nxt) && hasx(nxt, i)) ok = true;
            }
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";


    }
}