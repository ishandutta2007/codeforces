#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

typedef long long ll;

int main(void) {
    ll t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        ll x = a, y = b;
        ll k = 0, l = 0;
        while (x % 2 == 0) {
            k++; x /= 2;
        }
        while (y % 2 == 0) {
            l++; y /= 2;
        }
        if (x != y) {
            cout << "-1\n";
        } else {
            ll diff = abs(l - k);
            if (diff == 0) {
                cout << "0\n";
            } else {
                cout << (diff - 1) / 3 + 1 << "\n";
            }
        }
    }
}