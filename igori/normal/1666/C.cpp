#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define forn(i, n) for (int i = 0; (i) != (n); (i)++)
#define all(v) (v).begin(), (v).end()
#define uniq(x) sort(all(x)); x.resize(unique(all(x)) - (x).begin())

void dfs(int v, vector<int> &vis, vector<vector<int> > &g)
{
    vis[v] = 1;
    for (auto e : g[v]) if (vis[e] == 0) dfs(e, vis, g);
}

void solve()
{
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    vector<int> xs = {x1, x2, x3};
    vector<int> ys = {y1, y2, y3};

    uniq(xs);
    uniq(ys);

    struct edge{
        int to;
        ll len;
        int id;
    };

    vector<vector<edge> > g(9);
    int pnt = 0;
    for (int i = 0; i < xs.size(); i++)
    {
        for (int j = 0; j + 1 < ys.size(); j++)
        {
            g[i * 3 + j].push_back({i * 3 + j + 1, ys[j + 1] - ys[j], pnt});
            g[i * 3 + j + 1].push_back({i * 3 + j, ys[j + 1] - ys[j], pnt});
            pnt++;
        }
    }
    for (int j = 0; j < ys.size(); j++)
    {
        for (int i = 0; i + 1 < xs.size(); i++)
        {
            g[i * 3 + j].push_back({i * 3 + j + 3, xs[i + 1] - xs[i], pnt});
            g[i * 3 + j + 3].push_back({i * 3 + j, xs[i + 1] - xs[i], pnt});
            pnt++;
        }
    }

    vector<int> with_point(9);
    for (int i = 0; i < xs.size(); i++)
    {
        for (int j = 0; j < ys.size(); j++)
        {
            if (xs[i] == x1 && ys[j] == y1) with_point[i * 3 + j] = 1;
            if (xs[i] == x2 && ys[j] == y2) with_point[i * 3 + j] = 1;
            if (xs[i] == x3 && ys[j] == y3) with_point[i * 3 + j] = 1;
        }
    }

    ll ans = 1e18;
    vector<pair<int, int> > res;
    for (int mask = 0; mask < (1 << pnt); mask++)
    {
        vector<vector<int> > g2(9);

        ll cur = 0;
        vector<pair<int, int> > curres;

        for (int i = 0; i < 9; i++)
        {
            for (auto e : g[i])
            {
                if ((1 << e.id) & mask)
                {
                    g2[i].push_back(e.to);
                    cur += e.len;
                    if (i < e.to)
                        curres.push_back({i, e.to});
                }
            }
        }
        vector<int> vis(9);
        int cnt = 0;
        for (int i = 0; i < 9; i++)
        {
            if (with_point[i] && vis[i] == 0)
            {
                cnt++;
                dfs(i, vis, g2);
            }
        }
        if (cnt == 1 && cur < ans)
        {
            ans = cur;
            res = curres;
        }
    }
    cerr << ans << "\n";
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++)
    {
        int x1 = xs[res[i].first / 3];
        int y1 = ys[res[i].first % 3];
        int x2 = xs[res[i].second / 3];
        int y2 = ys[res[i].second % 3];
        cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}