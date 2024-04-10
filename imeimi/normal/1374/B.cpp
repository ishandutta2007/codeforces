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
        int c2 = 0, c3 = 0, n;
        cin >> n;
        while (n % 3 == 0) ++c3, n /= 3;
        while (n % 2 == 0) ++c2, n /= 2;
        if (n == 1 && c2 <= c3) printf("%d\n", c3 + (c3 - c2));
        else printf("-1\n");
    }
    return 0;
}