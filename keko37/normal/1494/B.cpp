#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t, n, u, r, d, l;

bool ok (int x) {
    return 0 <= x && x <= n - 2;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> u >> r >> d >> l;
        bool naso = 0;
        for (int mask = 0; mask < 16; mask++) {
            int uu = !!(mask & (1 << 0)) + !!(mask & (1 << 1));
            int rr = !!(mask & (1 << 1)) + !!(mask & (1 << 2));
            int dd = !!(mask & (1 << 2)) + !!(mask & (1 << 3));
            int ll = !!(mask & (1 << 3)) + !!(mask & (1 << 0));
            if (ok(u - uu) && ok(r - rr) && ok(d - dd) && ok(l - ll)) naso = 1;
        }
        if (naso) cout << "YES\n"; else cout << "NO\n";
    }
    return 0;
}