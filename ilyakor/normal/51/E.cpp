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

const int maxn = 710;

int64 a[6][maxn][maxn];
int n;

vector<vi> vt;

int main()
{
    memset(a, 0, sizeof(a));
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x, --y;
        a[0][x][y] = a[0][y][x] = 1;
    }
    for (int t = 1; t < 5; ++t)
    {
        for (int i = 0; i < n; ++i)
            for (int j = i; j < n; ++j)
            {
                for (int k = 0; k < n; ++k)
                    a[t][i][j] += a[t - 1][i][k] * a[0][j][k];
                a[t][j][i] = a[t][i][j];
            }
    }
    int64 res = 0;
    for (int i = 0; i < n; ++i)
        res += a[4][i][i];
    res /= 5LL;
    for (int i = 0; i < 2; ++i)
        for (int t = 0; t < n; ++t)
            res -= a[i][t][t] * a[3 - i][t][t];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                if (a[0][i][j] && a[0][i][k] && a[0][j][k])
                    ++res;
    res /= 2LL;
    cout << res << "\n";
    return 0;
}