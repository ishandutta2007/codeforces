#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pll;

const int rmax = 20;

vector<vector<int> > g;
vector<vector<int> > parent;
vector<int> t_in, t_out;
int timer;

void dfs(int v)
{
    t_in[v] = timer++;
    for (int to : g[v]) {
        dfs(to);
    }
    t_out[v] = timer++;
}

bool ancestor(int u, int v)
{
    return t_in[u] <= t_in[v] && t_out[u] >= t_out[v];
}

int help(int u, int w)
{
    if (u == w) {
        return 0;
    }
    int ans = 0;
    for (int r = rmax - 1; r >= 0; --r) {
        if (!ancestor(parent[u][r], w)) {
            ans += (1 << r);
            u = parent[u][r];
        }
    }
    return ans + 1;
}

int path_len(int u, int v)
{
    if (ancestor(u, v)) {
        return help(v, u);
    }
    int old_u = u;
    for (int r = rmax - 1; r >= 0; --r) {
        if (!ancestor(parent[u][r], v)) {
            u = parent[u][r];
        }
    }
    int w = parent[u][0];
    return help(old_u, w) + help(v, w);
}

int main()
{

    //freopen("input.txt", "r", stdin);

    //ifstream cin("input.txt");

    int n;
    cin >> n;

    g.resize(n);
    parent.resize(n);
    t_in.resize(n), t_out.resize(n);
    for (int i = 0; i < n; ++i) {
        parent[i].resize(rmax);
    }
    parent[0][0] = 0;

    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        --p;
        g[p].pb(i);
        parent[i][0] = p;
    }

    dfs(0);

    for (int r = 1; r < rmax; ++r) {
        for (int i = 0; i < n; ++i) {
            int t = parent[i][r - 1];
            parent[i][r] = parent[t][r - 1];
        }
    }

    int u = 0, v = 1;
    cout << "1 ";
    int diam = 1;

    for (int i = 2; i < n; ++i) {
        int x = path_len(i, u);
        int y = path_len(i, v);
        if (x > diam) {
            diam = x;
            v = i;
        }
        if (y > diam) {
            diam = y;
            u = i;
        }
        cout << diam << " ";
    }
    cout << "\n";

}