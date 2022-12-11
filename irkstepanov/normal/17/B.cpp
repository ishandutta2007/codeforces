#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, int> pll;

const int inf = 2e9;

struct edge
{
    int to, cost;
};

vector<char> used;
vector<vector<edge> > g;

void dfs(int v)
{
    used[v] = true;
    for (edge& e : g[v]) {
        if (!used[e.to]) {
            dfs(e.to);
        }
    }
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    vector<int> useless(n);
    for (int i = 0; i < n; ++i) {
        cin >> useless[i];
    }

    g.resize(n);
    vector<int> min_in(n, inf);
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        g[u].pb({v, c});
        min_in[v] = min(min_in[v], c);
    }

    int cnt = 0;
    int root = -1;
    for (int i = 0; i < n; ++i) {
        if (min_in[i] == inf) {
            ++cnt;
            root = i;
        }
    }

    if (cnt != 1) {
        cout << "-1\n";
        return 0;
    }

    used.assign(n, false);
    dfs(root);

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            cout << "-1\n";
            return 0;
        }
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (i != root) {
            sum += min_in[i];
        }
    }

    cout << sum << "\n";

}