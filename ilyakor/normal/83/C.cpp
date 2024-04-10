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

const int maxn = 57;

char ty[maxn][maxn];

bool allow[300];

int d[maxn][maxn];
int f[maxn][maxn];

int n, m, k;
int sx, sy, fx, fy;

int Q[maxn * maxn * 2];
int qs, qt;

const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

void bfs() {
    d[sx][sy] = 0;
    qs = 0, qt = 0;
    Q[qs++] = sx * maxn + sy;
    while (qs > qt) {
        int x = Q[qt] / maxn;
        int y = Q[qt] % maxn;
        if (x == fx && y == fy) break;
        ++qt;
        for (int dir = 0; dir < 4; ++dir) {
            int X = x + dx[dir], Y = y + dy[dir];
            if (X < 0 || Y < 0 || X >= n || Y >= m) continue;
            if (d[X][Y] != -1) continue;
            if (!allow[ty[X][Y]]) continue;
            d[X][Y] = d[x][y] + 1;
            f[X][Y] = x * maxn + y;
            Q[qs++] = X * maxn + Y;
        }
    }
}

string cur;

string rf[maxn][maxn];
bool uf[maxn][maxn];

void rest() {
    memset(uf, 0, sizeof(uf));
    rf[sx][sy] = "S";
    qs = 0, qt = 0;
    uf[sx][sy] = true;
    Q[qs++] = sx * maxn + sy;
    while (qs > qt) {
        int x = Q[qt] / maxn;
        int y = Q[qt] % maxn;
        if (x == fx && y == fy) break;
        ++qt;
        string& s = rf[x][y];       
        for (int dir = 0; dir < 4; ++dir) {
            int X = x + dx[dir], Y = y + dy[dir];
            if (X < 0 || Y < 0 || X >= n || Y >= m) continue;
            if (d[X][Y] != d[x][y] + 1) continue;
            if (!uf[X][Y]) {
                uf[X][Y] = true;
                rf[X][Y] = rf[x][y] + ty[X][Y];
                Q[qs++] = X * maxn + Y;
            } else {
                rf[X][Y] = min(rf[X][Y], rf[x][y] + ty[X][Y]);
            }
        }
    }
    cur = rf[fx][fy];
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            ty[i][j] = s[j];
            if (islower(s[j])) {
                continue;
            }
            if (s[j] == 'S')
                sx = i, sy = j;
            else
                fx = i, fy = j;
        }
    }
    int res = 100500100;
    string rs;
    bool rsf = false;
    set<int64> S;
    for (int i = 'a'; i <= 'z'; ++i)
        for (int j = 'a'; j <= i; ++j)
            for (int p = 'a'; p <= j; ++p)
                for (int q = 'a'; q <= p; ++q) {
                    int64 h = 123;                  
                    if (k >= 1) h = h * 2184057 + i;
                    if (k >= 2) h = h * 2184057 + j;
                    if (k >= 3) h = h * 2184057 + p;
                    if (k >= 4) h = h * 2184057 + q;
                    if (S.count(h)) continue;
                    S.insert(h);
                    memset(allow, 0, sizeof(allow));
                    if (k >= 1) allow[i] = true;
                    if (k >= 2) allow[j] = true;
                    if (k >= 3) allow[p] = true;
                    if (k >= 4) allow[q] = true;
                    allow['S'] = allow['T'] = true;
                    memset(d, -1, sizeof(d));
                    bfs();
                    if (d[fx][fy] == -1) continue;
                    if (d[fx][fy] > res) continue;                  
                    //rest();
                    if (res > d[fx][fy])
                        res = d[fx][fy];
                }

    S.clear();
    int bad = 1000000;
    for (int i = 'a'; i <= 'z'; ++i)
        for (int j = 'a'; j <= i; ++j)
            for (int p = 'a'; p <= j; ++p)
                for (int q = 'a'; q <= p; ++q) {
                    if (i >= bad && j >= bad && p >= bad && q >= bad) continue;
                    int64 h = 123;                  
                    if (k >= 1) h = h * 2184057 + i;
                    if (k >= 2) h = h * 2184057 + j;
                    if (k >= 3) h = h * 2184057 + p;
                    if (k >= 4) h = h * 2184057 + q;
                    if (S.count(h)) continue;
                    S.insert(h);
                    memset(allow, 0, sizeof(allow));
                    if (k >= 1) allow[i] = true;
                    if (k >= 2) allow[j] = true;
                    if (k >= 3) allow[p] = true;
                    if (k >= 4) allow[q] = true;
                    allow['S'] = allow['T'] = true;
                    memset(d, -1, sizeof(d));
                    bfs();
                    if (d[fx][fy] == -1) continue;
                    if (d[fx][fy] > res) continue;
                    rest();
                    if (!rsf || cur < rs) {
                        rsf = true, rs = cur;
                        bad = -1;
                        for (int t = 0; t < sz(cur); ++t)
                            bad = max(bad, (int) cur[t]);
                    }
                }

    if (res == 100500100)
        res = -1;
    if (res == -1) cout << res << "\n";
    else cout << rs.substr(1, sz(rs) - 2) << "\n";
    return 0;
}