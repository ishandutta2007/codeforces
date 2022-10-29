#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll u, v;
    cin >> u >> v;
    ll a1 = 0;
    bool f = 1;
    if ((u & 1LL) != (v & 1LL)) f = 0;
    for (ll k = 1; k < 63 && f; k++) {
        if ((u & (1LL << k)) == (v & (1LL << k))) continue;
        a1 |= (1LL << (k - 1));
        v -= (1LL << k);
        if (v < 0) f = 0;
    }
    if (f == 0) {
        cout << -1;
    } else if (a1 == 0) {
        if (u == 0) {
            cout << 0;
            return 0;
        }
        cout << 1 << endl;
        cout << u;
    } else if ((u | a1) == u + a1) {
        cout << 2 << endl;
        cout << u + a1 << ' ' << a1;
    } else {
        cout << 3 << endl;
        cout << u << ' ' << a1 << ' ' << a1 << endl;
    }
}