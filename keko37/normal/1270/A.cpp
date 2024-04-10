#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

int t, n, a, b, c, d;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        c = d = 0;
        for (int i = 0; i < a; i++) {
            int x; cin >> x;
            c = max(c, x);
        }
        for (int i = 0; i < b; i++) {
            int x; cin >> x;
            d = max(d, x);
        }
        if (c > d) cout << "YES\n"; else cout << "NO\n";
    }
    return 0;
}