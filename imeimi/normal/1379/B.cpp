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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        llong l, r, m;
        cin >> l >> r >> m;
        for (llong a = l; a <= r; ++a) {
            llong v = m % a;
            if (v < m && v <= r - l) {
                // na + v = m;
                llong b = l + v, c = l;
                printf("%lld %lld %lld\n", a, b, c);
                break;
            }
            if (a - v <= r - l) {
                // na + v = m;
                // (n + 1)a - (a - v) = m;
                llong b = l, c = l + a - v;
                printf("%lld %lld %lld\n", a, b, c);
                break;
            }
        }
    }
    return 0;
}