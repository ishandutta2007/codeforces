#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

vector<vector<int> > g;
int n, m;

bool inside(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

void delete_edge(int u, int v)
{
    //cout << "DEL " << u << " " << v << "\n";
    for (int i = 0; i < sz(g[u]); ++i) {
        if (g[u][i] == v) {
            g[u].erase(g[u].begin() + i);
            break;
        }
    }
    for (int i = 0; i < sz(g[v]); ++i) {
        if (g[v][i] == u) {
            g[v].erase(g[v].begin() + i);
            break;
        }
     }
}

vector<char> used;

int dfs(int v)
{
    int ans = 1;
    used[v] = true;
    for (int to : g[v]) {
        if (!used[to]) {
            ans += dfs(to);
        }
    }
    return ans;
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int k;
    cin >> n >> m >> k;

    vector<vector<int> > num(n, vector<int>(m));
    int id = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            num[i][j] = id++;
        }
    }

    g.resize(n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (inside(i - 1, j)) {
                g[num[i][j]].pb(num[i - 1][j]);
            }
            if (inside(i + 1, j)) {
                g[num[i][j]].pb(num[i + 1][j]);
            }
            if (inside(i, j - 1)) {
                g[num[i][j]].pb(num[i][j - 1]);
            }
            if (inside(i, j + 1)) {
                g[num[i][j]].pb(num[i][j + 1]);
            }
        }
    }

    while (k--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a == c) {
            for (int y = b; y < d; ++y) {
                delete_edge(num[a][y], num[a - 1][y]);
            }
        } else {
            for (int x = a; x < c; ++x) {
                delete_edge(num[x][b], num[x][b - 1]);
            }
        }
    }

    used.assign(n * m, false);
    vector<int> ans;
    for (int i = 0; i < n * m; ++i) {
        if (!used[i]) {
            ans.pb(dfs(i));
        }
    }
    sort(all(ans));
    for (int x : ans) {
        cout << x << " ";
    }
    cout << "\n";

}