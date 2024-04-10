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
char in[1002];
int solve() {
    cin >> n >> in + 1;
    int mn = n + 1, mx = 0;
    for (int i = 1; i <= n; ++i) {
        if (in[i] == '1') {
            mn = min(mn, i);
            mx = max(mx, i);
        }
    }
    if (mx == 0) return n;
    int ans = max(mx << 1, n - mn + 1 << 1);
    ans = max(ans, (mx - mn + 1 << 1) + max(mn - 1, n - mx));
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) printf("%d\n", solve());
    return 0;
}