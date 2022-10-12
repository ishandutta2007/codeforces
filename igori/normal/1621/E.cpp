#include <bits/stdc++.h>
 
using namespace std;
 
int comp(pair<long long, int> a, pair<long long, int> b)
{
    if (a.first * b.second < b.first * a.second)
        return 1;
    return 0;
}
 
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int> > g(m);
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        g[i] = vector<int>(k);
        for (int j = 0; j < k; j++)
        {
            cin >> g[i][j];
        }
    }
    vector<pair<pair<long long, int>, int> > avg(m);
    for (int i = 0; i < m; i++)
    {
        avg[i] = {{accumulate(g[i].begin(), g[i].end(), 0LL), g[i].size()}, i};
    }
    sort(a.rbegin(), a.rend());
    sort(avg.rbegin(), avg.rend(), [&](pair<pair<long long, int>, int> A, pair<pair<long long, int>, int> B){
         return comp(A.first, B.first);
         });
    vector<int> pos(m);
    for (int i = 0; i < m; i++)
        pos[avg[i].second] = i;
 
    vector<int> assign_to_next(m);
    vector<int> assign_to_this(m);
    vector<int> assign_to_prev(m);
    for (int i = 0; i < m - 1; i++)
        assign_to_next[i] = comp({1ll * a[i + 1], 1}, avg[i].first);
    for (int i = 0; i < m; i++)
        assign_to_this[i] = comp({1ll * a[i], 1}, avg[i].first);
    for (int i = 1; i < m; i++)
        assign_to_prev[i] = comp({1ll * a[i - 1], 1}, avg[i].first);
    for (int i = 1; i < m; i++)
        assign_to_next[i] += assign_to_next[i - 1],
        assign_to_this[i] += assign_to_this[i - 1],
        assign_to_prev[i] += assign_to_prev[i - 1];
 
    for (int i = 0; i < m; i++)
    {
        int id = pos[i];
        pair<long long, int> cur = {accumulate(g[i].begin(), g[i].end(), 0LL), g[i].size() - 1};
        for (int j = 0; j < g[i].size(); j++)
        {
            cur.first -= g[i][j];
            int L = -1, R = m;
            while (L + 1 < R)
            {
                int M = (L + R) / 2;
                if (!comp(avg[M].first, cur))
                    L = M;
                else
                    R = M;
            }
            if (R > id) R--;
            int tr = 1;
            if (comp({1ll * a[R], 1}, cur) == 1) tr = 0;
            if (min(R, id) - 1 >= 0 && assign_to_this[min(R, id) - 1] != 0) tr = 0;
            if (assign_to_this[max(R, id)] != assign_to_this.back()) tr = 0;
            if (R < id && (R ? assign_to_next[R - 1] : 0) != assign_to_next[id - 1]) tr = 0;
            if (R > id && assign_to_prev[R] != assign_to_prev[id]) tr = 0;
            cout << tr;
            cur.first += g[i][j];
        }
    }
    cout << "\n";
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