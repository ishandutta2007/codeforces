#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<vector<int> > g;
vector<char> used;

void dfs(int v)
{
    used[v] = true;
    for (int to : g[v]) {
        if (!used[to]) {
            dfs(to);
        }
    }
}

int main()
{

    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    g.resize(n);
    vector<vector<char> > p(n, vector<char>(n, false));
    for (int i = 0; i < n * (n - 1) / 2 - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        p[u][v] = p[v][u] = true;
    }

    int x, y;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (!p[i][j]) {
                x = i, y = j;
            }
        }
    }

    used.assign(n, false);
    dfs(x);
    if (used[y]) {
        cout << x + 1 << " " << y + 1 << "\n";
        return 0;
    }

    cout << y + 1 << " " << x + 1 << "\n";

}