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

const int maxn = 57 * 1000;

vi g[maxn];

int d[maxn][570];

int k;

int64 dfs(int x, int p) {
    memset(d[x], 0, sizeof(d[x]));

    int64 res = 0;

    for (int i = 0; i < sz(g[x]); ++i) if (p != g[x][i]) {
        res += dfs(g[x][i], x);
        for (int j = 0; j < k; ++j)
            d[x][j + 1] += d[g[x][i]][j];
    }
    ++d[x][0];

    res += d[x][k];

    int64 tmp = 0;

    for (int i = 0; i < sz(g[x]); ++i) if (p != g[x][i]) {
        for (int j = 0; j < k - 1; ++j) {
            int64 p = d[g[x][i]][j];
            int64 q = d[x][k - j - 1];
            if (j < k - 1) q -= d[g[x][i]][k - j - 2];

            tmp += p * q;
        }
    }

    if (tmp % 2) cerr << "Botva\n";
    res += tmp / 2;

    return res;
}

int main()
{
    int n;
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x, --y;
        g[x].pb(y);
        g[y].pb(x);
    }

    cout << dfs(0, -1) << "\n";
    return 0;
}