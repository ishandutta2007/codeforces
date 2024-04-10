#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

vector<vector<int> > g;
vector<ll> k;

void dfs(int v, int p) {
    if (sz(g[v]) == 1 && g[v][0] == p) {
        k[v] = 0;
        return;
    }
    k[v] = 0;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs(to, v);
        k[v] += max(ll(1), k[to]);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    ll s;
    cin >> s;

    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    k.resize(n);

    if (n == 2) {
        cout << s << "\n";
        return 0;
    }

    int root;
    for (int i = 0; i < n; ++i) {
        if (sz(g[i]) > 1) {
            root = i;
        }
    }

    dfs(root, root);

    ld ans = s * 2;
    ans /= k[root];

    cout << fixed;
    cout.precision(20);
    cout << ans << "\n";

}