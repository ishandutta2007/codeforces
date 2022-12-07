#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);

int main() {
    ll k; cin >> k;

    for (ll n = 3; n <= 2000; ++n) {
        ll rem = (n - 1) - (k % (n - 1));
        ll x = (k + rem * n) / (n - 1);
        if (x + rem < 1000000 && x - rem > 0 && rem) {
            cout << n << endl;
            cout << x << " ";
            if (n == 3) {
                cout << -x - rem << " ";
            } else {
                cout << -x << " ";
                for (int i = 1; i + 3 < n; ++i) cout << "0 ";
                cout << -rem << " ";
            }
            cout << x << endl;
            return 0;
        }
    }
    throw 1;

    return 0;
}