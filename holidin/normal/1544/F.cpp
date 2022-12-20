#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <algorithm>
#include <set>
#include <math.h>
#include <random>
#include <bitset>
#include <map>
#include <unordered_map>
#include <queue>
#include <time.h>
#define fi first
#define se second
#define ll long long
#define ld double
#define mp make_pair
#define int unsigned int
using namespace std;
const int inf = 1e15;
const int N = 23;
mt19937 rnd;
int cnt[N];
const int MOD = 31607;
const int mn1 = MOD - 1;

int mod(int x) {
    x %= MOD;
    return x;
}

int bp(int x, int st) {
    if (st  == 0)
        return 1;
    else if (st % 2 == 0) {
        return bp(mod(x * x), st / 2);
    } else {
        return mod(bp(mod(x * x), st / 2) * x);
    }
}

int inv(int a) {
    return bp(a, MOD - 2);
}

int del(int a, int b) {
    return mod(a * inv(b));
}

int a[N][N];
const int LogN = 23;
int t[LogN];
bool use[N][N];
const int lN = 3e6;
int p[N][lN];
bool us[N];
int msk[N];
int ct[lN];
void solve(int num) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            a[i][j] = del(a[i][j], 10000);
        }
    }
    for (int j = 0; j < n; ++j)
        for (int mask = 0; mask < t[n]; ++mask) {
            p[j][mask] = 1;
            int pp = p[j][mask];
            for (int i = 0; i < n; ++i)
                if ((mask & t[i]) > 0) {
                    us[i] = 1;
                    pp = mod(pp * a[i][j]);
                }
            p[j][mask] = pp;
        }
    int ans = 0;
    for (int d1 = 0; d1 < 2; ++d1) {
        for (int d2 = 0; d2 < 2; ++d2) {
            for (int mask = 0; mask < t[n]; ++mask) {
                int cnt = d1 + d2;
                for (int i = 0; i < n; ++i)
                    msk[i] = mask;
                for (int i = 0; i < n; ++i)
                    if ((mask & t[i]) > 0) {
                        ++cnt;
                    }
                if (d1) {
                    for (int i = 0; i < n; ++i) {
                        msk[i] |= t[i];
                    }
                }
                if (d2) {
                    for (int i = 0; i < n; ++i) {
                        msk[i] |= t[n - i - 1];
                    }
                }
                int pp = 1;
                int ver = 1;
                for (int j = 0; j < n; ++j) {
                    int mask = 0;
                    mask = msk[j];
                    ver = mod(ver * p[j][mask]);
                    int ver1 = p[j][t[n] - 1 - mask];
                    pp = mod(pp * mod(1 - ver1 + MOD));
                }
                ans = mod(ans + mod(mod(bp(mod(mn1), cnt) * pp) * ver));
            }
        }
    }
    cout << mod(mod(mn1 * ans) + 1) << "\n";

}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // local
    t[0] = 1;
    for (int i = 1; i < LogN; ++i) {
        t[i] = t[i - 1] * 2;
    }
    int test = 1;
    //cin >> test;
    int cnt = 0;
    while (1) {
        ++cnt;
        solve(cnt);
        break;
    }

}