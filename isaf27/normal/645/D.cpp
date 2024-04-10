#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <time.h>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;
#define pb push_back
#define mp make_pair

const int MAX_N = 100001;

int n, m;
vector<vector<int> > gr;
bool z, used[MAX_N];
int color[MAX_N];

void dfs(int p)
{
    color[p] = 1;
    used[p] = true;
    for (int i : gr[p])
    {
        if (color[i] == 1)
            z = true;
        if (!used[i])
            dfs(i);
    }
    color[p] = 2;
}

bool check(vector<pair<int, int> > g)
{
    vector<vector<int> > v(n);
    for (int i = 0; i < g.size(); i++)
        v[g[i].first].pb(g[i].second);
    gr = v;
    z = false;
    for (int i = 0; i < n; i++)
        used[i] = false;
    int t = -1;
    vector<int> deg(n);
    for (int i = 0; i < n; i++)
        deg[i] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j : v[i])
            deg[j]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (t != -1 && deg[i] == 0)
            return false;
        if (deg[i] == 0)
            t = i;
    }
    if (t == -1)
        return false;
    for (int i = 0; i < n; i++)
        color[i] = 0;
    dfs(t);
    if (z)
        return false;
    int go = t;
    int kol = 0;
    for (int i = 0; i < n; i++)
        used[i] = true;

    while (kol != n - 1)
    {
        //cerr << go << " ";
        for (int i : v[go])
            if (used[i])
                deg[i]--;
        for (int i : v[go])
            if (deg[i] < 0 && used[i])
                return false;
        int now = -1;
        for (int i : v[go])
        {
            if (now != -1 && used[i] && deg[i] == 0)
                return false;
            if (used[i] && deg[i] == 0)
                now = i;
        }
        if (now == -1)
            return false;
        used[go] = true;
        kol++;
        go = now;
    }
    return true;
}

int main()
{
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);/**/
    cin >> n >> m;
    vector<pair<int, int> > v;
    for (int i = 0; i < m; i++)
    {
        int s, f;
        cin >> s >> f;
        s--, f--;
        v.pb(mp(s, f));
    }
    int l = 0;
    int r = m;
    if (!check(v))
    {
        cout << -1;
        return 0;
    }
    while (r - l > 1)
    {
        int h = (l + r) / 2;
        vector<pair<int, int> > s;
        for (int i = 0; i < h; i++)
            s.pb(v[i]);
        if (check(s))
            r = h;
        else
            l = h;
    }
    cout << r;
    return 0;
}