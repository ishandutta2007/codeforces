#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;

const int n = 10000;

struct edge
{
    int from, to;
    bool used;
};

vector<edge> edges;
vector<vector<int> > g;
vector<int> compId;

void dfs1(int v, int cc)
{
    compId[v] = cc;
    for (int e : g[v]) {
        if (compId[edges[e].to] == -1) {
            dfs1(edges[e].to, cc);
        }
    }
}

void dfs2(int v, vector<int>& ans)
{
    for (int i = sz(g[v]) - 1; i >= 0; --i) {
        int e = g[v][i];
        if (edges[e].used) {
            continue;
        }
        edges[e].used = edges[e ^ 1].used = true;
        dfs2(edges[e].to, ans);
        ans.pb(e / 2);
    }
}

vector<int> euler(int v)
{
    vector<int> ans;
    dfs2(v, ans);
    return ans;
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("triangles.out");

    //freopen("numpalindrome.in", "r", stdin);
    //freopen("numpalindrome.out", "w", stdout);

    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int m;
    cin >> m;

    if (m == 1) {
        cout << "-1\n";
        return 0;
    }

    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(sz(edges));
        edges.pb({u, v, false});
        g[v].pb(sz(edges));
        edges.pb({v, u, false});
    }

    compId.assign(n, -1);
    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        if (!g[i].empty() && compId[i] == -1) {
            dfs1(i, cnt);
            ++cnt;
        }
    }

    if (cnt > 2) {
        cout << "-1\n";
        return 0;
    }

    if (cnt == 1) {
        int odd = 0;
        for (int i = 0; i < n; ++i) {
            if (sz(g[i]) & 1) {
                ++odd;
            }
        }
        if (odd > 4) {
            cout << "-1\n";
            return 0;
        }
        if (odd == 0) {
            vector<int> ans;
            for (int i = 0; i < n; ++i) {
                if (compId[i] == 0) {
                    ans = euler(i);
                    break;
                }
            }
            cout << sz(ans) - 1 << "\n";
            for (int i = 0; i < sz(ans) - 1; ++i) {
                cout << ans[i] + 1 << " ";
            }
            cout << "\n";
            cout << "1\n";
            cout << ans.back() + 1 << "\n";
        } else if (odd == 2) {
            int x = -1, y = -1;
            for (int i = 0; i < n; ++i) {
                if (sz(g[i]) & 1) {
                    if (x == -1) {
                        x = i;
                    } else {
                        y = i;
                    }
                }
            }
            g[x].pb(sz(edges));
            edges.pb({x, y, false});
            g[y].pb(sz(edges));
            edges.pb({y, x, false});
            vector<int> ans = euler(x);
            ans.pop_back();
            cout << sz(ans) - 1 << "\n";
            for (int i = 0; i < sz(ans) - 1; ++i) {
                cout << ans[i] + 1 << " ";
            }
            cout << "\n";
            cout << "1\n";
            cout << ans.back() + 1 << "\n";
        } else if (odd == 4) {
            int x = -1, y = -1, z = -1, t = -1;
            for (int i = 0; i < n; ++i) {
                if (sz(g[i]) & 1) {
                    if (x == -1) {
                        x = i;
                    } else if (y == -1) {
                        y = i;
                    } else if (z == -1) {
                        z = i;
                    } else {
                        t = i;
                    }
                }
            }
            g[x].pb(sz(edges));
            edges.pb({x, y, false});
            g[y].pb(sz(edges));
            edges.pb({y, x, false});
            g[z].pb(sz(edges));
            edges.pb({z, t, false});
            g[t].pb(sz(edges));
            edges.pb({t, z, false});
            vector<int> ans = euler(x);
            ans.pop_back();
            int lf = 0;
            for (int i = 0; i < sz(ans); ++i) {
                if (ans[i] >= m) {
                    lf = i;
                    break;
                }
            }
            cout << lf << "\n";
            for (int i = 0; i < lf; ++i) {
                cout << ans[i] + 1 << " ";
            }
            cout << "\n";
            cout << sz(ans) - lf - 1 << "\n";
            for (int i = lf + 1; i < sz(ans); ++i) {
                cout << ans[i] + 1 << " ";
            }
            cout << "\n";
        }
    } else if (cnt == 2) {
        int odd0 = 0, odd1 = 0;
        for (int i = 0; i < n; ++i) {
            if (sz(g[i]) & 1) {
                if (compId[i] == 0) {
                    ++odd0;
                } else {
                    ++odd1;
                }
            }
        }
        if (odd0 > 2 || odd1 > 2) {
            cout << "-1\n";
            return 0;
        }
        int x = -1, y = -1, z = -1, t = -1;
        for (int i = 0; i < n; ++i) {
            if (sz(g[i]) & 1) {
                if (compId[i] == 0) {
                    if (x == -1) {
                        x = i;
                    } else {
                        y = i;
                    }
                } else {
                    if (z == -1) {
                        z = i;
                    } else {
                        t = i;
                    }
                }
            }
        }
        vector<int> ans1;
        if (x != -1) {
            g[x].pb(sz(edges));
            edges.pb({x, y, false});
            g[y].pb(sz(edges));
            edges.pb({y, x, false});
            ans1 = euler(x);
            ans1.pop_back();
        } else {
            for (int i = 0; i < n; ++i) {
                if (compId[i] == 0) {
                    x = i;
                    break;
                }
            }
            ans1 = euler(x);
        }
        vector<int> ans2;
        if (z != -1) {
            g[z].pb(sz(edges));
            edges.pb({z, t, false});
            g[t].pb(sz(edges));
            edges.pb({t, z, false});
            ans2 = euler(z);
            ans2.pop_back();
        } else {
            for (int i = 0; i < n; ++i) {
                if (compId[i] == 1) {
                    z = i;
                    break;
                }
            }
            ans2 = euler(z);
        }
        cout << sz(ans1) << "\n";
        for (int i = 0; i < sz(ans1); ++i) {
            cout << ans1[i] + 1 << " ";
        }
        cout << "\n";
        cout << sz(ans2) << "\n";
        for (int i = 0; i < sz(ans2); ++i) {
            cout << ans2[i] + 1 << " ";
        }
        cout << '\n';
    }

}