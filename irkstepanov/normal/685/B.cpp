#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

#define fori for (int i = 0; i < n; ++i)
#define forj for (int j = 0; j < n; ++j)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pll;

vector<vector<int> > g;
vector<int> c;
vector<int> deg;
vector<int> deg_max_ch;
vector<int> parent;

void dfs(int v)
{
    deg[v] = 1;
    for (int to : g[v]) {
        dfs(to);
        deg[v] += deg[to];
        deg_max_ch[v] = max(deg_max_ch[v], deg[to]);
    }
    if (deg[v] == 1) {
        c[v] = v;
        return;
    }
    int t = deg[v] / 2;
    if (deg_max_ch[v] <= t) {
        c[v] = v;
        return;
    }
    for (int to : g[v]) {
        int u = c[to];
        bool ok = false;
        while (u != v) {
            if (deg[v] - deg[u] <= t) {
                ok = true;
                break;
            }
            u = parent[u];
        }
        if (ok) {
            c[v] = u;
            return;
        }
    }
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    //freopen("input", "r", stdin);

    ios_base::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    parent.resize(n);
    g.resize(n);
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        --p;
        parent[i] = p;
        g[p].pb(i);
    }

    c.resize(n);
    deg.resize(n);
    deg_max_ch.resize(n);

    dfs(0);

    while (q--) {
        int v;
        cin >> v;
        --v;
        cout << c[v] + 1 << "\n";
    }

}