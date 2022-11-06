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
typedef long long ll;
typedef long double lf;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<lf, lf> pff;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        ll ans = 0, mn = 1e18;
        for (int i = 1; i <= n + n; ++i) {
            for (int j = 1; j <= n + n; ++j) {
                ll c;
                cin >> c;
                if (i <= n && j <= n) continue;
                if (i > n && j > n) {
                    ans += c;
                    continue;
                }
                if ((i == 1 || i == n || i == n + 1 || i == n + n)
                 && (j == 1 || j == n || j == n + 1 || j == n + n))
                  mn = min(mn, c);
            }
        }
        printf("%lld\n", ans + mn);
    }
    return 0;
}