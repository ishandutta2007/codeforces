#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

const int maxn = 500;

int d[maxn][maxn];

vector<ii> head, tail;
vector<ii> moves[maxn][maxn];
int deg[maxn][maxn];
int opt[maxn][maxn];

int main()
{
    memset(d, -1, sizeof(d));
    memset(opt, 0, sizeof(opt));
    int h, t, R;
    cin >> h >> t >> R;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        head.pb(ii(x, y));
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        tail.pb(ii(x, y));
    }
    queue<ii> q;
    for (int i = 0; i < maxn; ++i)
        for (int j = 0; j < maxn; ++j)
            if (i + j > R)
                d[i][j] = 0, q.push(ii(i, j));
    d[0][0] = 1;
    q.push(ii(0, 0));
    memset(deg, 0, sizeof(deg));
    for (int i = 0; i < maxn; ++i)
        for (int j = 0; j < maxn; ++j)
        {
            if (d[i][j] != -1) continue;
            for (int t = 0; t < sz(head); ++t)
            {
                if (i < t + 1) continue;
                int H = i - (t + 1) + head[t].first;
                int T = j + head[t].second;
                if (H >= 0 && T >= 0)
                    moves[H][T].pb(ii(i, j)), ++deg[i][j];
            }
            for (int t = 0; t < sz(tail); ++t)
            {
                if (j < t + 1) continue;
                int H = i + tail[t].first;
                int T = j - (t + 1) + tail[t].second;
                if (H >= 0 && T >= 0)
                    moves[H][T].pb(ii(i, j)), ++deg[i][j];
            }
        }
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (d[x][y] == 1)
        {
            for (int i = 0; i < sz(moves[x][y]); ++i)
            {
                int h = moves[x][y][i].first;
                int t = moves[x][y][i].second;
                if (d[h][t] != -1) continue;
                d[h][t] = 1;
                opt[h][t] = opt[x][y] + 1;
                q.push(ii(h, t));
            }
        }
        else
        {
            for (int i = 0; i < sz(moves[x][y]); ++i)
            {
                int h = moves[x][y][i].first;
                int t = moves[x][y][i].second;
                if (d[h][t] != -1) continue;
                --deg[h][t];
                if (deg[h][t] > 0) continue;
                d[h][t] = 0;
                opt[h][t] = opt[x][y] + 1;
                q.push(ii(h, t));
            }
        }
    }
    if (d[h][t] == -1)
        printf("Draw\n");
    else printf("%s\n%d\n", d[h][t] ? "Ivan" : "Zmey", opt[h][t]);
    return 0;
}