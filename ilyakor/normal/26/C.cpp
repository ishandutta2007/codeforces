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

void save()
{
    printf("IMPOSSIBLE\n");
    exit(0);
}

const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

int res[500][500];
int N, M;

bool u[30];

bool good(int x, int y)
{
    return x >= 0 && x < N && y >= 0 && y < M;
}

void go(int x, int y)
{
    for (int dir = 0; dir < 4; dir++)
        if (good(x + dx[dir], y + dy[dir]))
        {
            int t = res[x + dx[dir]][y + dy[dir]];
            if (t != -1)
                u[t] = true;
        }
}

void put(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    memset(u, 0, sizeof(u));
    go(x1, y1);
    go(x2, y2);
    go(x3, y3);
    go(x4, y4);
    int t = 0;
    while (u[t])
        t++;
    res[x1][y1] = t;
    res[x2][y2] = t;
    res[x3][y3] = t;
    res[x4][y4] = t;
}

int main()
{
    memset(res, -1, sizeof(res));
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    N = n, M = m;
    if ((n * m) % 2)
        save();
    if (n % 2 == 1)
    {
        if (m / 2 > a)
            save();
        for (int i = 0; i < m; i += 2)
            put(n - 1, i, n - 1, i + 1, n - 1, i, n - 1, i + 1);
        a -= m / 2;
        n--;
    }
    if (m % 2 == 1)
    {
        if (n / 2 > b)
            save();
        for (int i = 0; i < n; i += 2)
            put(i, m - 1, i + 1, m - 1, i, m - 1, i + 1, m - 1);
        b -= n / 2;
        m--;
    }
    int total = c + (a / 2) + (b / 2);
    if (total * 4 < n * m)
        save();
    for (int i = 0; i < n; i += 2)
        for (int j = 0; j < m; j += 2)
        {
            if (c)
            {
                put(i, j, i + 1, j, i, j + 1, i + 1, j + 1);
                c--;
            }
            else if (a >= 2)
            {
                put(i, j, i, j + 1, i, j, i, j + 1);
                put(i + 1, j, i + 1, j + 1, i + 1, j, i + 1, j + 1);
                a -= 2;
            }
            else
            {
                assert(b >= 2);
                put(i, j, i + 1, j, i, j, i + 1, j);
                put(i, j + 1, i + 1, j + 1, i, j + 1, i + 1, j + 1);
                b -= 2;
            }
        }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            printf("%c", 'a' + res[i][j]);
        printf("\n");
    }
    return 0;
}