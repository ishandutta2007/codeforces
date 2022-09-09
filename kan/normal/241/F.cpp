#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int maxn = 105;
const int maxm = 1005;
const int inf = 1e9;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int d[maxn][maxn], frx[maxn][maxn], fry[maxn][maxn];
bool can[maxn][maxn];
char p[maxn][maxn];
int ox[maxn * maxn], oy[maxn * maxn];
int x[maxm], y[maxm];
char route[maxm];
int xs, ys, xf, yf;
int n, m, k;
int bo, eo;

void donow(int w)
{
    int curx = x[w];
    int cury = y[w];
    memset(can, false, sizeof can);
    can[curx][cury] = true;
    while (frx[curx][cury] != -1)
    {
        int nx = frx[curx][cury];
        int ny = fry[curx][cury];
        curx = nx;
        cury = ny;
        can[nx][ny] = true;
    }
    int best = -1;
    int wx = 0, wy = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) if (can[i][j] && d[i][j] <= k && d[i][j] > best)
        {
            best = d[i][j];
            wx = i;
            wy = j;
        }
    }
    printf("%d %d\n", wx, wy);
    exit(0);
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) scanf("%s", p[i] + 1);
    for (int i = 0; i <= n + 1; i++)
    {
        p[i][0] = '#';
        p[i][m + 1] = '#';
    }
    for (int i = 0; i <= m + 1; i++)
    {
        p[0][i] = '#';
        p[n + 1][i] = '#';
    }
    scanf("%d%d%s%d%d", &xs, &ys, route, &xf, &yf);
    x[0] = xs;
    y[0] = ys;
    int len = strlen(route);
    x[len + 1] = xf;
    y[len + 1] = yf;
    for (int w = 0; w < len; w++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++) if (p[i][j] == route[w])
            {
                x[w + 1] = i;
                y[w + 1] = j;
            }
        }
    }
    len += 2;
    int curtime = 0;
    for (int w = 0; w < len - 1; w++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++) d[i][j] = inf;
        }
        bo = 0;
        eo = 1;
        d[x[w]][y[w]] = curtime;
        ox[0] = x[w];
        oy[0] = y[w];
        frx[x[w]][y[w]] = -1;
        while (eo > bo)
        {
            int curx = ox[bo];
            int cury = oy[bo];
            bo++;
            if (curx == x[w + 1] && cury == y[w + 1]) break;
            for (int cd = 0; cd < 4; cd++)
            {
                int nx = curx + dx[cd];
                int ny = cury + dy[cd];
                if (p[nx][ny] == '#') continue;
                int dist;
                if (p[curx][cury] >= '1' && p[curx][cury] <= '9') dist = p[curx][cury] - 48;
                else dist = 1;
                if (d[nx][ny] <= d[curx][cury] + dist) continue;
                d[nx][ny] = d[curx][cury] + dist;
                frx[nx][ny] = curx;
                fry[nx][ny] = cury;
                ox[eo] = nx;
                oy[eo] = ny;
                eo++;
            }
        }
        curtime = d[x[w + 1]][y[w + 1]];
        if (curtime >= k) donow(w + 1);
    }
    printf("%d %d\n", x[len - 1], y[len - 1]);
	return 0;
}