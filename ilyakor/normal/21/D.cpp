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
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

const int maxn = 15;
const int inf = 100000000;

bool a[maxn][maxn];
vi vg[maxn][maxn];
int d[maxn][maxn];
int n;

int f[1 << maxn];

int go(int mask)
{
    int& res = f[mask];
    if (res != -1) return res;
    res = inf;
    for (int i = 0; i < n; i++)
    {
        if (!((mask >> i) & 1)) continue;
        for (int j = 0; j < n; j++)
        {
            if (i == j) continue;
            if (!((mask >> j) & 1)) continue;
            res = min(res, d[i][j] + go(mask ^ (1 << i) ^ (1 << j)));
        }
    }
    return res;
}

int main()
{
    int m;
    cin >> n >> m;
    int res = 0;
    for (int i = 0; i < n; i++)
        a[i][i] = true;
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        x--, y--;
        vg[x][y].pb(z);
        vg[y][x].pb(z);
        a[x][y] = a[y][x] = true;
        res += z;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                a[j][k] |= a[j][i] & a[i][k];
    int mask = 0;
    for (int i = 0; i < n; i++)
    {
        int s = 0;
        for (int j = 0; j < n; j++)
        {
            s += sz(vg[i][j]);
            int mi = 100000000;
            for (int k = 0; k < sz(vg[i][j]); k++)
                mi = min(mi, vg[i][j][k]);
            if (i == j) mi = 0;
            d[i][j] = mi;
        }
        if (s != 0 && !a[0][i])
        {
            printf("-1\n");
            return 0;
        }
        if (s % 2)
            mask |= (1 << i);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
    memset(f, -1, sizeof(f));
    f[0] = 0;
    cout << (res + go(mask)) << "\n";

    return 0;
}