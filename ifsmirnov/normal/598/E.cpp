#include <functional>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
const int inf = 1e9+100500;

const int maxn = 55;

int d[maxn][maxn][maxn];

int go(int n, int m, int k) {
    int &res = d[n][m][k];
    if (res == -1) {
        if (n * m == k) {
            return res = 0;
        } else if (n * m < k) {
            return res = inf;
        } else if (k == 0) {
            return res = 0;
        }

        res = inf;
        for (int i = 1; i < n; ++i) {
            for (int rk = 0; rk <= k; ++rk) {
                res = min(res, go(i, m, rk) + go(n-i, m, k-rk) + m*m);
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int rk = 0; rk <= k; ++rk) {
                res = min(res, go(n, i, rk) + go(n, m-i, k-rk) + n*n);
            }
        }
    }
    return res;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif

    memset(d, -1, sizeof d);
    int t;
    cin >> t;
    forn(i, t) {
        int n, m, k;
        cin >> n >> m >> k;
        printf("%d\n", go(n, m, k));
    }


#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}