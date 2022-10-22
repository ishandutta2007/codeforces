#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int x, y, x2, y2;
        cin >> x >> y >> x2 >> y2;
        bool f = false;
        if (x == x2 && y + y2 == x) f = true;
        if (x == y2 && y + x2 == x) f = true;
        if (y == x2 && x + y2 == y) f = true;
        if (y == y2 && x + x2 == y) f = true;
        if (f) cout << "YES\n";
        else cout << "NO\n";
    }
}