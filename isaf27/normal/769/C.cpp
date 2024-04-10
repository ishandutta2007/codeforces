#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <time.h>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stdlib.h>
#include <deque>
#include <iomanip>
#include <complex>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAX_N = 1001;
const int MAX_LOG = 18;
const int BIG = 1e9 + 239;
int c[4] = { 'D', 'L', 'R', 'U' };
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
const int dir = 4;

int n, m, k, x, y;
string a[MAX_N];

bool check(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool can_go(int x, int y)
{
    return check(x, y) && a[x][y] != '*';
}

int dist[MAX_N][MAX_N];

void bfs()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dist[i][j] = BIG;
    dist[x][y] = 0;
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    while (!q.empty())
    {
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();
        for (int i = 0; i < dir; i++)
        {
            int gx = nx + dx[i];
            int gy = ny + dy[i];
            if (can_go(gx, gy))
            {
                if (dist[gx][gy] > dist[nx][ny] + 1)
                {
                    dist[gx][gy] = dist[nx][ny] + 1;
                    q.push(make_pair(gx, gy));
                }
            }
        }
    }
}

int main()
{   /*
    #define fname "test"
    freopen(fname".in", "r", stdin);
    freopen(fname".out", "w", stdout);/**/
    cin.sync_with_stdio(0);
    cin >> n >> m >> k;
    getline(cin, a[0]);
    for (int i = 0; i < n; i++)
        getline(cin, a[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == 'X')
            {
                x = i;
                y = j;
            }
    bfs();
    string ans = "";
    for (int i = 0; i < k; i++)
    {
        bool go = false;
        for (int t = 0; t < dir; t++)
        {
            int nx = x + dx[t];
            int ny = y + dy[t];
            if (!can_go(nx, ny))
                continue;
            if (dist[nx][ny] + i + 1 > k)
                continue;
            ans += c[t];
            go = true;
            x = nx;
            y = ny;
            break;
        }
        if (!go)
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    cout << ans;
    return 0;
}