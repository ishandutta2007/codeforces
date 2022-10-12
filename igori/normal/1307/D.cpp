#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int> > vvi;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i++) cin >> a[i], a[i]--;
    vector<vector<int> > g(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> d1(n, -1), d2(n, -1);
    d1[0] = 0, d2[n - 1] = 0;
    {
        vector<int> q = {0};
        for (int i = 0; i < q.size(); i++)
        {
            for (auto u : g[q[i]])
            {
                if (d1[u] == -1)
                {
                    d1[u] = d1[q[i]] + 1;
                    q.push_back(u);
                }
            }
        }
    }
    {
        vector<int> q = {n - 1};
        for (int i = 0; i < q.size(); i++)
        {
            for (auto u : g[q[i]])
            {
                if (d2[u] == -1)
                {
                    d2[u] = d2[q[i]] + 1;
                    q.push_back(u);
                }
            }
        }
    }
    vector<pair<int, int> > x(k);
    for (int i = 0; i < k; i++)
    {
        x[i] = {d1[a[i]], d2[a[i]]};
    }
    sort(x.begin(), x.end(), [&](pair<int, int> a, pair<int, int> b){
         return a.first - a.second < b.first - b.second;
         });
    int maxse = -1e9, maxans = 0;
    for (int i = k - 1; i >= 0; i--)
    {
        //cout << x[i].first << " " << x[i].second << endl;
        maxans = max(maxans, x[i].first + maxse);
        maxse = max(maxse, x[i].second);
        //cout << maxans << endl;
    }
    maxans++;
    cout << min(maxans, d1[n - 1]);
}