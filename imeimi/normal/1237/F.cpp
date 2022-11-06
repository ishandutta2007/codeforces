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
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

const int mod = 998244353;
void add(int &x, int y) {
    x = (x + y) % mod;
}

int mul(int x, int y) {
    return (llong)x * y % mod;
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

int fac[3602];
int rev[3602];
int nCr(int n, int r) {
    if (n < r || r < 0) return 0;
    return mul(fac[n], mul(rev[r], rev[n - r]));
}

int h, w, n;
int chR[3602], chC[3602];
int dpR[3602], dpC[3602];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    fac[0] = 1;
    for (int i = 1; i <= 3601; ++i) fac[i] = mul(fac[i - 1], i);
    rev[3601] = pw(fac[3601], mod - 2);
    for (int i = 3601; i--; ) rev[i] = mul(rev[i + 1], i + 1);
    cin >> h >> w >> n;
    for (int i = 0; i < n + n; ++i) {
        int r, c;
        cin >> r >> c;
        chR[r] = 1;
        chC[c] = 1;
    }
    chR[h + 1] = chC[w + 1] = 1;
    vector<int> R, C;
    int Rcnt = 0, Ccnt = 0;
    for (int i = 1, p = 0; i <= h + 1; ++i) {
        if (chR[i]) {
            if (p) R.push_back(p);
            p = 0;
        }
        else {
            ++p;
            ++Rcnt;
        }
    }
    for (int i = 1, p = 0; i <= w + 1; ++i) {
        if (chC[i]) {
            if (p) C.push_back(p);
            p = 0;
        }
        else {
            ++p;
            ++Ccnt;
        }
    }
    dpR[0] = 1;
    for (int x : R) {
        for (int i = 3602; i--; ) {
            if (dpR[i] == 0) continue;
            for (int j = 1; j + j <= x; ++j) {
                debug("nCr(%d, %d)=%d\n", x - j, j, nCr(x - j, j));
                add(dpR[i + j], mul(dpR[i], nCr(x - j, j)));
            }
        }
    }
    dpC[0] = 1;
    for (int x : C) {
        for (int i = 3602; i--; ) {
            if (dpC[i] == 0) continue;
            for (int j = 1; j + j <= x; ++j) {
                add(dpC[i + j], mul(dpC[i], nCr(x - j, j)));
            }
        }
    }
    for (int i = 0; i <= 3600; ++i) {
        if (dpR[i] != 0) debug("dpR[%d]=%d\n", i, dpR[i]);
    }
    for (int i = 0; i <= 3600; ++i) {
        if (dpC[i] != 0) debug("dpC[%d]=%d\n", i, dpC[i]);
    }
    int ans = 0;
    for (int i = 0; i <= 3600; ++i) {
        for (int j = 0; j <= 3600; ++j) {
            if (i + i + j > Rcnt) continue;
            if (i + j + j > Ccnt) continue;
            int val = mul(dpR[i], dpC[j]);
            val = mul(val, nCr(Rcnt - i - i, j));
            val = mul(val, nCr(Ccnt - j - j, i));
            add(ans, mul(val, mul(fac[i], fac[j])));
        }
    }
    printf("%d\n", ans);
    return 0;
}