#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define forn(i, n) for (int i = 0; (i) != (n); (i)++)
#define all(v) (v).begin(), (v).end()
#define uniq(x) sort(all(x)); x.resize(unique(all(x)) - (x).begin())

void dfs(int v, int p, int c, vector<int> &vis, vector<int> &par, vector<vector<int> > &g)
{
    if (vis[v] == c)
        return;
    if (vis[v] != 0)
    {
        cout << "Possible\n";
        cerr << v + 1 << "\n";

        vector<int> p1, p2;
        p1.push_back(v);
        while (par[p1.back()] != -1)
        {
            p1.push_back(par[p1.back()]);
        }
        p2.push_back(v);
        p2.push_back(p);
        while (par[p2.back()] != -1)
        {
            p2.push_back(par[p2.back()]);
        }
        reverse(all(p1));
        reverse(all(p2));

        cout << p1.size() << "\n";
        for (auto e : p1) cout << e + 1 << " "; cout << "\n";
        cout << p2.size() << "\n";
        for (auto e : p2) cout << e + 1 << " "; cout << "\n";
        exit(0);
    }
    vis[v] = c;
    par[v] = p;
    for (auto e : g[v]) dfs(e, v, c, vis, par, g);
}

void solve()
{
    int n, m, s;
    cin >> n >> m >> s; s--;
    vector<vector<int> > g(n);
    forn(i, m)
    {
        int f, t;
        cin >> f >> t;
        f--, t--;
        if (t == s) continue;
        g[f].push_back(t);
    }
    vector<int> vis(n), par(n);
    par[s] = -1;
    int c = 1;
    for (auto go : g[s])
    {
        dfs(go, s, c, vis, par, g);
        c++;
    }
    cout << "Impossible\n";
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