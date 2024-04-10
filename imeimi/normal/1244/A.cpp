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

void solve() {
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    for (int i = 0; i <= k; ++i) {
        int j = k - i;
        if (c * i >= a && d * j >= b) {
            printf("%d %d\n", i, j);
            return;
        }
    }
    printf("-1\n");
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}