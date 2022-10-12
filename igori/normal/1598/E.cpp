#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

pair<int, int> next(int x, int y, int dir, int n, int m)
{
    if (dir == 1) x++;
    else y++;
    if (x > n || y > m)
        return {0, 0};
    return {x, y};
}

vector<pair<int, int> > ladder(int x, int y, int dir, int n, int m)
{
    vector<pair<int, int> > res = {{x, y}};
    pair<int, int> a;
    while ((a = next(x, y, dir, n, m)).first != 0)
    {
        res.push_back(a);
        x = a.first, y = a.second, dir ^= 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    long long ans = 0;
    int free = n * m;
    vector<vector<pair<int, int> > > ladders;
    vector<vector<int> > is_active;
    vector<vector<vector<int> > >  in_ladders(n + 1, vector<vector<int> >(m + 1));

    for (int i = n; i >= 2; i--)
    {
        vector<pair<int, int> > l1 = ladder(i, 1, 1, n, m);
        ans += (l1.size() - 1) * (l1.size()) / 2;
        for (auto e : l1) in_ladders[e.first][e.second].push_back(ladders.size());
        ladders.push_back(l1);
        is_active.push_back(vector<int>(l1.size(), 1));
    }
    vector<pair<int, int> > l1 = ladder(1, 1, 0, n, m);
    vector<pair<int, int> > l2 = ladder(1, 1, 1, n, m);
    ans += (l1.size() - 1) * l1.size() / 2;
    ans += (l2.size() - 1) * l2.size() / 2;
    for (auto e : l1) in_ladders[e.first][e.second].push_back(ladders.size());
    ladders.push_back(l1);
    is_active.push_back(vector<int>(l1.size(), 1));
    for (auto e : l2) in_ladders[e.first][e.second].push_back(ladders.size());
    ladders.push_back(l2);
    is_active.push_back(vector<int>(l2.size(), 1));
    for (int i = 2; i <= m; i++)
    {
        vector<pair<int, int> > l1 = ladder(1, i, 0, n, m);
        ans += (l1.size() - 1) * (l1.size()) / 2;
        for (auto e : l1) in_ladders[e.first][e.second].push_back(ladders.size());
        ladders.push_back(l1);
        is_active.push_back(vector<int>(l1.size(), 1));
    }
    ans += free;

    //cout << ans << "\n";

    vector<vector<int> > g(n + 1, vector<int>(m + 1, 1));
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (g[x][y] == 1) free--, ans--;
        else free++, ans++;
        g[x][y] ^= 1;
        for (auto id : in_ladders[x][y])
        {
            int pos = 0;
            pair<int, int> f = {x, y};
            for (int i = 0; i < ladders[id].size(); i++)
                if (ladders[id][i] == f)
                    pos = i;
            int L = pos;
            while (L - 1 >= 0 && is_active[id][L - 1])
                L--;
            int R = pos;
            while (R + 1 < is_active[id].size() && is_active[id][R + 1])
                R++;
            is_active[id][pos] ^= 1;
            if (g[x][y] == 0) ans -= (pos - L + 1) * (R - pos + 1) - 1;
            else ans += (pos - L + 1) * (R - pos + 1) - 1;
        }
        cout << ans << "\n";
    }
}