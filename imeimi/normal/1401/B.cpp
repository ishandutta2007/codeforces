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
        int a0, a1, a2, b0, b1, b2;
        cin >> a0 >> a1 >> a2 >> b0 >> b1 >> b2;
        // a = 2 0 1
        // b = 1 2 0
        int c2 = min(a2, b1);
        int m2 = max(0, a1 + b2 - (a0 + a1 + a2 - c2));
        printf("%d\n", (c2 - m2) * 2);
    }
    return 0;
}