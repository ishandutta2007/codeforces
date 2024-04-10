#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 7;

int mid;

int dfs(int v, int p, vector<vector<int> > &g)
{
    int mn = 0;
    int mx = 0, mxcnt = 0;
    int calc = 0;
    for (auto u : g[v]) if (u != p)
    {
        int k = dfs(u, v, g);
        if (calc == 0)
        {
            mn = mx = k;
            calc = 1;
        }
        mn = min(mn, k);
        if (k > mx)
            mx = k, mxcnt = 0;
        if (k == mx)
            mxcnt++;
    }
    //cout << mid << " " << v << " " << mx << " " << mn << "\n";
    if (v == 0 && mxcnt <= 1)
        return mx;
    if (mx + 2 > mid)
        return inf;
    return mn + 1;
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int> > g(n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int L = 0, R = n + 1;
    while (L + 1 < R)
    {
        mid = (L + R) / 2;
        //cout << "! " << mid << " " << dfs(0, 0, g) << "\n";
        if (dfs(0, 0, g) <= mid)
            R = mid;
        else
            L = mid;
    }
    mid = R;
    cout << R - 1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}