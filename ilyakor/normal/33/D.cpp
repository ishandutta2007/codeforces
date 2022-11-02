#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
//#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

const int maxn = 1100;

int64 Kx[maxn], Ky[maxn], Cx[maxn], Cy[maxn], R[maxn];

vi g[maxn];

int n, m, k;

bool a[maxn][maxn];

bool calc(int p, int q)
{
    if (p == q) return false;
    if (q == 0) return true;
    if (p == 0) return false;
    return sqr(Cx[p] - Cx[q]) + sqr(Cy[p] - Cy[q]) <= sqr(R[q]) && R[q] >= R[p];
}

int d[maxn];

int go(int x)
{
    if (d[x] != -1) return d[x];
    d[x] = 0;
    for (int i = 0; i <= m; ++i)
    {
        if (!a[x][i]) continue;
        d[x] = max(d[x], go(i) + 1);
    }
    return d[x];
}

int ind[maxn];
bool u[maxn];

int dist[maxn][maxn];

void dfs(int x, int Y, int cur)
{
    dist[Y][x] = cur;
    u[x] = true;
    for (int i = 0; i < sz(g[x]); ++i)
        if (!u[g[x][i]])
            dfs(g[x][i], Y, cur + 1);
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        cin >> Kx[i] >> Ky[i];
    for (int i = 1; i <= m; ++i)
        cin >> R[i] >> Cx[i] >> Cy[i];
    for (int i = 0; i <= m; ++i)
        for (int j = 0; j <= m; ++j)
            a[i][j] = calc(i, j);
    memset(d, -1, sizeof(d));
    d[0] = 0;
    for (int i = 1; i <= m; ++i)
        if (d[i] == -1)
            go(i);

    for (int i = 1; i <= m; ++i)
    {
        int opt = -1, ov = -1;
        for (int j = 0; j <= m; ++j)
            if (a[i][j] && d[j] > opt)
                opt = d[j], ov = j;
        g[i].pb(ov);
        g[ov].pb(i);
    }

    for (int i = 0; i <= m; ++i)
    {
        memset(u, 0, sizeof(u));
        dfs(i, i, 0);
    }

    for (int i = 0; i < n; ++i)
    {
        ind[i] = 0;
        for (int j = 0; j <= m; ++j)
        {
            if (sqr(Cx[j] - Kx[i]) + sqr(Cy[j] - Ky[i]) > sqr(R[j])) continue;
            if (d[j] > d[ind[i]])
                ind[i] = j;
        }
    }
    for (int i = 0; i < k; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        x--, y--;
        printf("%d\n", dist[ind[x]][ind[y]]);
    }
    return 0;
}