#include <bits/stdc++.h>

using namespace std;

void dfs_check(int v, vector<vector<int> > &g, vector<int> &vis)
{
    vis[v] = 1;
    for (auto e : g[v])
    {
        if (vis[e] == 1)
        {
            cout << -1 << "\n";
            exit(0);
        }
        if (vis[e] == 0)
            dfs_check(e, g, vis);
    }
    vis[v] = 2;
}

void dfs(int v, vector<vector<int> > &g, vector<int> &vis)
{
    if (vis[v]) return;
    vis[v] = 1;
    for (auto e : g[v])
    {
        dfs(e, g, vis);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int> > down(n);
    vector<vector<int> > up(n);
    for (int i = 0; i < m; i++)
    {
        int f, t;
        cin >> f >> t;
        f--, t--;
        down[f].push_back(t);
        up[t].push_back(f);
    }
    vector<int> ch(n);
    for (int i = 0; i < n; i++)
    {
        if (down[i].size() == 0)
        {
            dfs_check(i, up, ch);
        }
    }
    for (auto e : ch)
    {
        if (ch[e] == 0)
        {
            cout << -1 << "\n";
            return;
        }
    }

    vector<int> vis_up(n);
    vector<int> vis_down(n);
    string s(n, 'E');
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (vis_up[i] == 0 && vis_down[i] == 0)
            s[i] = 'A', ans++;
        dfs(i, up, vis_up);
        dfs(i, down, vis_down);
    }

    cout << ans << "\n" << s << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //cout << "\n";

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}