//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define TIME (clock() * 1.0 / CLOCKS_PER_SEC)
typedef long long ll;
typedef long double ld;

const int M = 1e5 + 239;

vector<int> v[M];
int n, sz[M];
ll ans;

void dfs(int p, int pr)
{
    sz[p] = 1;
    for (int i : v[p])
        if (i != pr)
        {
            dfs(i, p);
            sz[p] += sz[i];
        }
    if (pr != -1)
        ans += min(sz[p], n - sz[p]);
}

int centroid(int p, int pr)
{
    for (int i : v[p])
        if (i != pr)
            if (2 * sz[i] > n)
                return centroid(i, p);
    return p;
}

vector<vector<int>> al;
vector<int> now;

void dfs_now(int p, int pr)
{
    now.push_back(p);
    for (int i : v[p])
        if (i != pr)
            dfs_now(i, p);
}

int color[M], res[M];

int main()
{
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int s, f;
        cin >> s >> f;
        s--, f--;
        v[s].push_back(f);
        v[f].push_back(s);
    }
    ans = 0;
    dfs(0, -1);
    cout << 2LL * ans << "\n";
    int c = centroid(0, -1);
    al.push_back({c});
    for (int i : v[c])
    {
        now.clear();
        dfs_now(i, c);
        al.push_back(now);
    }
    for (int i = 0; i < (int)al.size(); i++)
        for (int j : al[i])
            color[j] = i;
    vector<int> order;
    set<pair<int, pair<int, int>>> cnt;
    for (int i = 0; i < (int)al.size(); i++)
        cnt.insert(make_pair(-(int)al[i].size(), make_pair(1, i)));
    for (int i = 0; i < n; i++)
    {
        int ban = -1;
        if (i != 0)
            ban = color[order[i - 1]];
        auto it = cnt.begin();
        while (it->second.second == ban) it++;
        int id = it->second.second;
        cnt.erase(it);
        order.push_back(al[id].back());
        al[id].pop_back();
        if (!al[id].empty())
            cnt.insert(make_pair(-(int)al[id].size(), make_pair(-i, id)));
    }
    /*for (int t : order)
        cerr << color[t] << " ";
    cerr << "\n";*/
    for (int i = 0; i < n; i++)
        res[order[i]] = order[(i + 1) % n];
    for (int i = 0; i < n; i++)
        cout << res[i] + 1 << " ";
    cout << "\n";
    return 0;
}