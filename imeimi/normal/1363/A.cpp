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
        int n, x;
        cin >> n >> x;
        int cnt[2] = {};
        for (int i = 1; i <= n; ++i) {
            int a;
            cin >> a;
            ++cnt[a & 1];
        }
        bool ans = 0;
        for (int o = 1; o <= x; o += 2) {
            if (x - o <= cnt[0] && o <= cnt[1]) ans = 1;
        }
        printf(ans ? "Yes\n" : "No\n");
    }
    return 0;
}