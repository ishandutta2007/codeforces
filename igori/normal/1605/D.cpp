#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void dfs(int v, int p, vector<vector<int> > &g, vector<int> &color)
{
    if (v != p) color[v] = color[p] ^ 1;
    for (auto u : g[v]) if (u != p) dfs(u, v, g, color);
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int> > g(n);
    for (int i = 0; i < n - 1; i++)
    {
        int f, t;
        cin >> f >> t;
        f--, t--;
        g[f].push_back(t);
        g[t].push_back(f);
    }
    vector<int> color(n, -1);
    color[0] = 0;
    dfs(0, 0, g, color);
    int c0 = 0, c1 = 0;
    for (auto e : color) if (e) c1++; else c0++;
    if (c0 > c1)
    {
        for (int i = 0; i < n; i++) color[i] ^= 1;
        swap(c0, c1);
    }
    vector<pair<int, int> > sets;
    for (int L = 1; ; L <<= 1)
    {
        if (2 * L - 1 <= n)
            sets.push_back({L, 2 * L - 1});
        else break;
    }
    reverse(sets.begin(), sets.end());
    vector<int> ans(n), used(n + 1);
    for (int pnt = 0, i = 0; i < sets.size(); i++)
    {
        if (c0 - (sets[i].second - sets[i].first + 1) >= 0)
        {
            for (int x = sets[i].first; x <= sets[i].second; x++)
            {
                while (color[pnt] == 1) pnt++;
                ans[pnt] = x;
                used[x] = 1;
                pnt++;
            }
            c0 -= (sets[i].second - sets[i].first + 1);
        }
    }
    for (int i = 0, j = 1; i < n; i++)
    {
        if (ans[i] == 0)
        {
            while (used[j]) j++;
            ans[i] = j;
            used[j] = 1;
        }
    }
    for (auto e : ans) cout << e << " ";
    cout << "\n";
}

int main()
{
    const int N = 1e6;
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}