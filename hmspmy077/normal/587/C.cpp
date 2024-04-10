#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <cassert>
#include <map>
#include <set>
#include <ctime>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(X) ((int)((X).size()))

const double eps = 1e-8;
const int inf = 1000000000;

const int N = 1000005;
const int mo = 1000000000 + 7;

vector<int> edge[N];
vector<pair<int, int> > query[N];
int v[N], a[N], f[N];
vector<int> Ans[N], backup[N], ans[N];

void merge(vector<int> &a, vector<int> b)
{
    for (int i = 0; i < sz(b); ++i)
        a.pb(b[i]);
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    while (sz(a) > 10) a.pop_back();
}

int find(int i)
{
    if (f[i] != i)
    {
        int j = f[i];
        f[i] = find(j);
        merge(Ans[i], Ans[j]);
    }
    return f[i];
}

void dfs(int a)
{
    v[a] = 1;
    f[a] = a;
    for (int i = 0; i < sz(edge[a]); ++i)
    {
        int j = edge[a][i];
        if (v[j]) continue;
        dfs(j);
        f[j] = a;
    }
    for (int i = 0; i < sz(query[a]); ++i)
    {
        int j = query[a][i].x, k = query[a][i].y;
        if (v[j])
        {
            find(j);
            merge(ans[k], Ans[j]);
        }
    }
}

void dfsdfs(int a)
{
    v[a] = 1;
    f[a] = a;
    for (int i = sz(edge[a]) - 1; i >= 0; --i)
    {
        int j = edge[a][i];
        if (v[j]) continue;
        dfsdfs(j);
        f[j] = a;
    }
    for (int i = 0; i < sz(query[a]); ++i)
    {
        int j = query[a][i].x, k = query[a][i].y;
        if (v[j])
        {
            find(j);
            merge(ans[k], Ans[j]);
        }
    }
}

void work()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        edge[u].pb(v);
        edge[v].pb(u);
    }
    for (int i = 1; i <= m; ++i)
    {
        int j;
        cin >> j;
        Ans[j].pb(i);
    }
    for (int i = 1; i <= n; ++i)
    {
        sort(Ans[i].begin(), Ans[i].end());
        while (sz(Ans[i]) > 10) Ans[i].pop_back();
        backup[i] = Ans[i];
    }
    for (int i = 0; i < q; ++i)
    {
        int u, v;
        cin >> u >> v >> a[i];
        query[u].pb(mp(v, i));
        query[v].pb(mp(u, i));
    }
    dfs(1);
    memset(v, 0, sizeof v);
    for (int i = 1; i <= n; ++i)
        Ans[i] = backup[i];
    dfsdfs(1);
    for (int i = 0; i < q; ++i)
    {
        a[i] = min(a[i], sz(ans[i]));
        cout << a[i];
        for (int j = 0; j < a[i]; ++j)
            cout << ' ' << ans[i][j];
        cout << endl;
    }
}

int main()
{
    #ifdef LOCAL_TEST
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    work();
    return 0;
}