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

int k, n, m;

const int dx[] = {-1, 1, 0, 0, 0, 0};
const int dy[] = {0, 0, -1, 1, 0, 0};
const int dz[] = {0, 0, 0, 0, -1, 1};

bool good(int x, int y, int z)
{
    return x >= 0 && x < k && y >= 0 && y < n && z >= 0 && z < m;
}

bool a[57][57][57];
bool u[57][57][57];
int res = 0;

void dfs(int x, int y, int z)
{
    if (a[x][y][z]) return;
    ++res;
    u[x][y][z] = true;
    for (int dir = 0; dir < 6; ++dir) {
        int xx = x + dx[dir];
        int yy = y + dy[dir];
        int zz = z + dz[dir];
        if (!good(xx, yy, zz)) continue;
        if (u[xx][yy][zz]) continue;
        if (a[xx][yy][zz]) continue;
        dfs(xx, yy, zz);
    }
}

int main()
{
    cin >> k >> n >> m;
    for (int i = 0; i < k; ++i)
        for (int j = 0; j < n; ++j) {
            string s;
            cin >> s;
            for (int t = 0; t < sz(s); ++t)
                a[i][j][t] = (s[t] == '#');
        }
    int X, Y;
    cin >> X >> Y;
    --X, --Y;
    dfs(0, X, Y);
    cout << res << "\n";
    return 0;
}