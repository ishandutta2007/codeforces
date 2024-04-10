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
        int x, y, n;
        cin >> x >> y >> n;
        int s = 0, e = 1e9 + 5;
        while (s < e) {
            llong m = (s + e + 1) / 2;
            llong v = m * x + y;
            if (v <= n) s = m;
            else e = m - 1;
        }
        printf("%d\n", s * x + y);
    }
    return 0;
}