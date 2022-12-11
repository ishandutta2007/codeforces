#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int inf = 1e9;

struct edge
{
    int to;
    int color;
};

vector<vector<edge> > g;

vector<int> a;
int visited, colored;
int color;

bool dfs(int v, int c, bool flag = false)
{
    a[v] = c;
    ++visited;
    if (c) {
        if (flag) {
            cout << v + 1 << " ";
        }
        ++colored;
    }
    for (edge& e : g[v]) {
        int val = color ^ a[v] ^ e.color;
        if (a[e.to] == -1) {
            if (!dfs(e.to, val, flag)) {
                return false;
            }
        } else if (a[e.to] != val) {
            return false;
        }
    }
    return true;
}

int main()
{

    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        --u, --v;
        if (c == 'R') {
            g[u].pb({v, 0});
            g[v].pb({u, 0});
        } else {
            g[u].pb({v, 1});
            g[v].pb({u, 1});
        }
    }

    int ops = inf;
    int bestcolor = -1;
    vector<pii> vct;

    for (color = 0; color < 2; ++color) {
        vector<pii> v;
        a.assign(n, -1);
        int my_ops = 0;
        bool norm = true;
        for (int i = 0; i < n; ++i) {
            if (a[i] == -1) {
                visited = 0;
                colored = 0;
                bool ok = dfs(i, 1);
                if (!ok) {
                    norm = false;
                    break;
                }
                v.pb(mp(visited, colored));
                my_ops += min(colored, visited - colored);
            }
        }
        if (!norm) {
            continue;
        }
        if (my_ops < ops) {
            ops = my_ops;
            bestcolor = color;
            vct = v;
        }
    }

    if (bestcolor == -1) {
        cout << "-1\n";
        return 0;
    }
    cout << ops << "\n";
    color = bestcolor;
    a.assign(n, -1);
    int pos = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == -1) {
            if (vct[pos].second < vct[pos].first - vct[pos].second) {
                dfs(i, 1, true);
            } else {
                dfs(i, 0, true);
            }
            ++pos;
        }
    }

}