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

const int maxn = 1100;
const int maxk = 1100 * 1000;

const int64 mod = 1000 * 1000 * 1000 + 7;

int64 fact[maxk];
int64 rfact[maxk];

int64 pw(int64 x, int64 y) {
    int64 res = 1;
    while (y) {
        if (y % 2 == 1)
            res = (res * x) % mod, --y;
        else
            x = (x * x) % mod, y /= 2;
    }
    return res;
}

int64 inv(int64 x) {
    return pw(x, mod - 2);
}

int64 C(int n, int k) {
    if (k < 0 || k > n) return 0;
    int64 res = fact[n];
    res = (res * rfact[k]) % mod;
    res = (res * rfact[n - k]) % mod;
    return res;
}

int64 d[maxn][maxn];

int main()
{
    fact[0] = rfact[0] = 1;
    for (int i = 1; i < maxk; ++i) {
        fact[i] = (fact[i - 1] * (int64)i) % mod;
        rfact[i] = inv(fact[i]);
    }

    memset(d, 0, sizeof(d));
    d[0][0] = 1;
    for (int i = 1; i < maxn; ++i) {
        d[i][0] = 0;
        for (int j = 1; j < maxn; ++j) {
            d[i][j] = d[i - 1][j] * (int64) j;
            d[i][j] += d[i - 1][j - 1] * (int64) j;
            d[i][j] %= mod;
        }
    }

    int n, m, k;
    cin >> n >> m >> k;

    int64 res = 0;

    if (m == 1) {
        int64 res = pw(k, n);
        cout << res << "\n";
        return 0;
    }

    for (int kernel = 0; kernel <= n; ++kernel) {
        for (int side = 0; side + kernel <= n; ++side) {
            if (kernel + side == 0) continue;
            int64 coef = pw(kernel, (m - 2) * n);
            if (coef == 0) continue;
            coef *= C(k, kernel);
            coef %= mod;
            coef *= C(k - kernel, side);
            coef %= mod;
            coef *= C(k - kernel - side, side);
            coef %= mod;
            if (coef == 0) continue;
            coef *= d[n][kernel + side];
            coef %= mod;
            coef *= d[n][kernel + side];
            coef %= mod;
            res += coef;
            res %= mod;
        }
    }

    cout << res << "\n";
    return 0;
}