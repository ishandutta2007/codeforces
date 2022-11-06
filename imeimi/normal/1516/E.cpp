#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long llong;
typedef long double lf;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<lf, lf> pff;

const int mod = 1e9 + 7, N = 205;
void add(int &x, int y) {
    x += y;
    if (x >= mod) x -= mod;
}

int mul(int x, int y) {
    return 1ll * x * y % mod;
}

int pw(int x, int p) {
    int r = 1;
    while (p) {
        if (p & 1) r = mul(r, x);
        x = mul(x, x);
        p >>= 1;
    }
    return r;
}

int fac[405], rev[405], dp[205][205], pp[205][205], sum[205];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    fac[0] = 1;
    for (int i = 1; i < 405; ++i) fac[i] = 1ll * fac[i - 1] * i % mod;
    for (int i = 0; i < 405; ++i) rev[i] = pw(fac[i], mod - 2);
    int n, k;
    cin >> n >> k;
    dp[0][0] = 1;
    for (int sz = 2; sz <= k + 1; ++sz) {
        memcpy(pp, dp, sizeof(pp));
        memset(dp, 0, sizeof(dp));
        for (int w = 0; w <= k; ++w) {
            for (int g = 0; g <= w; ++g) {
                int m = mul(fac[sz - 1], rev[sz]);
                int r = 1;
                for (int c = 0; w + c * (sz - 1) <= k; ++c, r = mul(r, m)) {
                    add(dp[w + c * (sz - 1)][g + c], mul(pp[w][g], mul(r, rev[c])));
                }
            }
        }
    }
    for (int w = 0; w <= k; ++w) {
        for (int g = 0; g <= w; ++g) {
            for (int i = 0; i < w + g; ++i) {
                dp[w][g] = mul(dp[w][g], n - i);
            }
            //printf("dp[%d][%d] = %d\n", w, g, dp[w][g]);
            add(sum[w], dp[w][g]);
        }
    }
    printf("%d", sum[1]);
    for (int w = 2; w <= k; ++w) {
        add(sum[w], sum[w - 2]);
        printf(" %d", sum[w]);
    }
    printf("\n");
    return 0;
}