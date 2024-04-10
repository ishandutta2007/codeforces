#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int> > g(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        g[x].push_back(i);
    }
    if (g[0].size() > 1)
    {
        cout << -1;
        return 0;
    }
    if (k == 1 && n > 2)
    {
        cout << -1;
        return 0;
    }
    vector<pair<int, int> > edges;
    for (int i = 1; i < g.size(); i++)
    {
        if (g[i].size() > 1ll * (k - (i != 1)) * g[i - 1].size())
        {
            cout << -1;
            return 0;
        }
        for (int j = 0; j < g[i].size(); j++)
            edges.push_back({g[i][j], g[i - 1][j / (k - (i != 1))]});
    }
    cout << edges.size() << "\n";
    for (auto e : edges)
        cout << e.first + 1 << " " << e.second + 1 << "\n";
}