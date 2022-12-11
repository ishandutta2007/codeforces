#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const int inf = 1e9;
const int nmax = 300500;

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int> > g(n);
    vector<pii> edges(m);
    set<pii> setik;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
        edges[i] = {u, v};
        setik.insert({u, v});
        setik.insert({v, u});
    }

    vector<int> dist(n, inf);
    vector<vector<int> > level;
    level.pb(vector<int>(0));
    vector<int> p(n, -1);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    int kmax = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : g[v]) {
            if (dist[to] == inf) {
                dist[to] = dist[v] + 1;
                p[to] = v;
                kmax = max(kmax, dist[to]);
                q.push(to);
                if (dist[to] >= sz(level)) {
                    level.pb(vector<int>());
                }
                level[dist[to]].pb(to);
            }
        }
    }

    vector<int> ans(n, inf);
    ans[0] = 0;

    for (int k = 2; k < sz(level); ++k) {
        int v = level[k][0];
        vector<int> lf, rg;
        lf.pb(v);
        for (int j = 1; j < sz(level[k]); ++j) {
            if (setik.count({v, level[k][j]})) {
                lf.pb(level[k][j]);
            } else {
                rg.pb(level[k][j]);
            }
        }
        for (int i = 0; i < sz(lf); ++i) {
            for (int j = i + 1; j < sz(lf); ++j) {
                if (!setik.count({lf[i], lf[j]})) {
                    cout << "NO\n";
                    return 0;
                }
            }
        }

        for (int i = 0; i < sz(rg); ++i) {
            for (int j = i + 1; j < sz(rg); ++j) {
                if (!setik.count({rg[i], rg[j]})) {
                    cout << "NO\n";
                    return 0;
                }
            }
        }

        if (k == 2) {
            for (int a : lf) {
                ans[a] = -2;
            }
            for (int b : rg) {
                ans[b] = 2;
            }
        } else {
            for (int a : lf) {
                if (ans[p[a]] < 0) {
                    ans[a] = -k;
                } else {
                    ans[a] = k;
                }
            }
            for (int b : rg) {
                if (ans[p[b]] < 0) {
                    ans[b] = -k;
                } else {
                    ans[b] = k;
                }
            }

            for (int i = 1; i < sz(lf); ++i) {
                if (ans[lf[i]] != ans[lf[0]]) {
                    cout << "NO\n";
                    return 0;
                }
            }
            for (int i = 1; i < sz(rg); ++i) {
                if (ans[rg[i]] != ans[rg[0]]) {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }

    if (sz(level) >= 2) {
        for (int v = 0; v < n; ++v) {
            if (ans[v] == -2) {
                for (int to : g[v]) {
                    if (ans[to] == inf) {
                        ans[to] = -1;
                    }
                }
                break;
            }
        }
        for (int v = 0; v < n; ++v) {
            if (ans[v] == 2) {
                for (int to : g[v]) {
                    if (ans[to] == inf) {
                        ans[to] = 1;
                    }
                }
            }
        }
    }

    set<int> root;
    root.insert(0);
    for (int to : g[0]) {
        root.insert(to);
    }

    for (int v = 0; v < n; ++v) {
        if (ans[v] == inf) {
            set<int> curr;
            curr.insert(v);
            for (int to : g[v]) {
                curr.insert(to);
            }
            if (curr == root) {
                ans[v] = 0;
            }
        }
    }

    int u = -1;
    for (int v = 0; v < n; ++v) {
        if (ans[v] == -1) {
            u = v;
        }
    }
    if (u == -1) {
        for (int v = 0; v < n; ++v) {
            if (ans[v] == inf) {
                u = v;
            }
        }
    }
    if (u != -1) {
        ans[u] = -1;
        for (int to : g[u]) {
            if (ans[to] == inf) {
                ans[to] = -1;
            }
        }
    }

    u = -1;
    for (int v = 0; v < n; ++v) {
        if (ans[v] == 1) {
            u = v;
        }
    }
    if (u == -1) {
        for (int v = 0; v < n; ++v) {
            if (ans[v] == inf) {
                u = v;
            }
        }
    }
    if (u != -1) {
        ans[u] = 1;
        for (int to : g[u]) {
            if (ans[to] == inf) {
                ans[to] = 1;
            }
        }
    }

    for (int v = 0; v < n; ++v) {
        if (ans[v] == inf) {
            cout << "NO\n";
            return 0;
        }
    }

    for (int i = 0; i < m; ++i) {
        if (abs(ans[edges[i].first] - ans[edges[i].second]) > 1) {
            cout << "NO\n";
            return 0;
        }
    }

    map<int, vector<int> > mapa;
    for (int v = 0; v < n; ++v) {
        mapa[ans[v]].pb(v);
    }

    for (int v = 0; v < n; ++v) {
        for (int x = ans[v] - 1; x <= ans[v] + 1; ++x) {
            for (int to : mapa[x]) {
                if (to == v) {
                    continue;
                }
                if (!setik.count({v, to})) {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << ans[i] + nmax << " ";
    }
    cout << "\n";

}