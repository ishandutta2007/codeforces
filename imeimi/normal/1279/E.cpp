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

int n;
llong k;

const llong inf = 1e18 + 5;
llong cnt[51];
llong all[51];

llong mul(llong x, llong y) {
    if (y == 0) return 0;
    if (3 * inf / y < x) return inf;
    return min(x * y, inf);
}

int C[51];
int P[51];

bool count(int i, int mn, int mx, llong k) {
    debug("P[%d]=%d, (mn, mx) = (%d, %d), %lldth\n", i - 1, P[i - 1], mn, mx, k);
    if (i > n) {
        if (k > 1) return 0;
        for (int j = 1; j <= n; ++j) {
            printf("%d%c", P[j], "\n "[j < n]);
        }
        return 1;
    }
    if (mx < i) {
        for (int j = mx + 1; j <= n; ++j) {
            llong c = mul(cnt[j - mx], all[n - j]);
            if (c < k) {
                k -= c;
            }
            else {
                P[i] = j;
                ++C[j];
                count(i + 1, i, j, k);
                return 1;
            }
        }
    }
    else {
        for (int j = mn; j <= mx; ++j) {
            if (C[j]) continue;
            P[i] = j;
            if (i < mx) {
                int t = j;
                while (t < i) t = P[t];
                if (t == i) continue;
            }
            llong c = mul(cnt[mx - i + 1], all[n - mx]);
            debug("if P[%d]=%d, cnt = %lld\n", i, j, c);
            if (c < k) {
                k -= c;
            }
            else {
                ++C[j];
                count(i + 1, mn, mx, k);
                return 1;
            }
        }
    }
    return 0;
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) C[i] = 0;
    if (all[n] < k) {
        printf("-1\n");
    }
    else {
        count(1, 0, 0, k);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    for (int i = 0; i <= 50; ++i) {
        cnt[i] = 1;
        for (int j = i - 2; j > 0; --j) {
            cnt[i] = mul(j, cnt[i]);
        }
    }
    all[0] = 1;
    for (int i = 1; i <= 50; ++i) {
        for (int j = 0; j < i; ++j) {
            all[i] = min(all[i] + mul(all[j], cnt[i - j]), inf);
        }
    }
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}