#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int inf = 100500;

vector<vector<int> > e;
vector<char> used;

int dfs(int v)
{
    used[v] = true;
    for (int to : e[v]) {
        if (used[to]) {
            continue;
        }
        return dfs(to);
    }
    return v;
}

int main()
{

    //ifstream cin("input.txt");

    int n, m;
    cin >> n >> m;
    vector<vector<char> > g(n, vector<char>(n, false));

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        if (u == v) {
            if (n == 1 && m == 1) {
                cout << "YES\n0\n";
            } else {
                cout << "NO\n";
            }
            return 0;
        }
        if (g[u][v]) {
            if (n == 2 && m == 2) {
                cout << "YES\n0\n";
            } else {
                cout << "NO\n";
            }
            return 0;
        }
        g[u][v] = g[v][u] = true;
    }

    e.resize(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (g[i][j]) {
                e[i].pb(j);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (sz(e[i]) > 2) {
            cout << "NO\n";
            return 0;
        }
    }

    used.assign(n, false);
    vector<pii> paths;
    for (int i = 0; i < n; ++i) {
        if (e[i].empty()) {
            used[i] = true;
            paths.pb(mp(i, i));
        } else if (!used[i] && sz(e[i]) == 1) {
            paths.pb(mp(i, dfs(i)));
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            ++cnt;
        }
    }
    if (cnt != 0 && cnt != n) {
        cout << "NO\n";
    }

    if (cnt == n) {
        cout << "YES\n0\n";
        return 0;
    }
    cout << "YES\n" << sz(paths) << "\n";

    while (sz(paths) > 1) {
        int val1 = inf;
        int a, b;
        for (int i = 0; i < sz(paths); ++i) {
            if (paths[i].first < val1 || paths[i].second < val1) {
                val1 = min(paths[i].first, paths[i].second);
                a = i;
            }
        }
        int val2 = inf;
        for (int i = 0; i < sz(paths); ++i) {
            if (i != a && (paths[i].first < val2 || paths[i].second < val2)) {
                val2 = min(paths[i].first, paths[i].second);
                b = i;
            }
        }
        cout << val1 + 1 << " " << val2 + 1 << "\n";
        if (paths[a].first == val1 && paths[b].first == val2) {
            paths[a].first = paths[b].second;
        } else if (paths[a].first == val1) {
            paths[a].first = paths[b].first;
        } else if (paths[b].first == val2) {
            paths[a].second = paths[b].second;
        } else {
            paths[a].second = paths[b].first;
        }
        for (int i = b; i < sz(paths) - 1; ++i) {
            paths[i] = paths[i + 1];
        }
        paths.pop_back();
    }

    cout << min(paths[0].first, paths[0].second) + 1 << " " << max(paths[0].first, paths[0].second) + 1 << "\n";

}