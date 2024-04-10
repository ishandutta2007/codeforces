#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k, s;
    cin >> n >> m >> k >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i], a[i]--;

    vector<vector<int> > g(n);
    for (int i = 0; i < m; i++)
    {
        int f, t;
        cin >> f >> t;
        f--, t--;
        g[f].push_back(t);
        g[t].push_back(f);
    }

    vector<vector<int> > dist(k, vector<int>(n, -1));

    for (int i = 0; i < k; i++)
    {
        vector<int> q;
        for (int j = 0; j < n; j++)
        {
            if (a[j] == i)
            {
                dist[i][j] = 0;
                q.push_back(j);
            }
        }
        for (int j = 0; j < q.size(); j++)
        {
            int v = q[j];
            for (auto u : g[v])
            {
                if (dist[i][u] == -1)
                {
                    dist[i][u] = dist[i][v] + 1;
                    q.push_back(u);
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        vector<int> b(k);
        for (int j = 0; j < k; j++)
            b[j] = dist[j][i];
        sort(b.begin(), b.end());
        cout << accumulate(b.begin(), b.begin() + s, 0) << " ";
    }
}