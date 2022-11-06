#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>
#include <string>
#include <cstring>
#include <functional>
#define fs first
#define se second

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

const int mod = 1e9 + 7;
int n;
int M[1001][1001];

int pw(int x, int p) {
    int r = 1;
    while (p) {
        if (p & 1) r = (llong)r * x % mod;
        x = (llong)x * x % mod;
        p >>= 1;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> M[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        int j = 1, k = 1;
        while (j == i) ++j;
        while (k == i || k == j) ++k;
        llong ans = (llong)M[i][j] * M[i][k] / M[j][k];
        llong s = 1, e = 1e9;
        while (s < e) {
            llong m = (s + e) / 2;
            if (ans <= m * m) e = m;
            else s = m + 1;
        }
        printf("%lld ", s);
    }
    return 0;
}