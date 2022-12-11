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

    //ifstream cin("input.txt");

    int n, m;
    cin >> n >> m;

    if (m != n - 1) {
        cout << "no\n";
        return 0;
    }

    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    used.assign(n, false);
    dfs(0);

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            cout << "no\n";
            return 0;
        }
    }

    cout << "yes\n";

}