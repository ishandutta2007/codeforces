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
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << (i & 1) * (1ll << i + j) << ' ';
        }
        cout << endl;
    }
    int q;
    cin >> q;
    while (q--) {
        llong k;
        cin >> k;
        int x = 1, y = 1;
        cout << "1 1\n";
        for (int i = 1; i <= n + n - 2; ++i) {
            int v = (k >> i) & 1;
            if ((x & 1) == v) ++x;
            else ++y;
            cout << x << ' ' << y << '\n';
        }
        cout.flush();
    }
    return 0;
}