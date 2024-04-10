#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double
#define fi first
#define se second
#define all(a) a.begin(), a.end()

signed main() {
    int q;
    cin >> q;
    while (q--) {
        bool f = true;
        int n;
        cin >> n;
        vector<pair<int, int>> a(n + 1, {0, 0});
        for (int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;
        for (int i = 1; i <= n; i++) {
            int x = a[i].fi - a[i - 1].fi;
            int x2 = a[i].se - a[i - 1].se;
            if (x < 0 || x2 < 0 || x2 > x) f = false;
        }
        if (f) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}