#include <iostream>
using namespace std;

typedef long long ll;
const ll BIG = 4000000000000000000;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll count = 0;
        ll k = 0;
        for (ll x = 2; x < BIG ; x *= 2) {
            k++;
            ll y = x / 2 - 1;
            if (n <= y) {
                break;
            }
            count += ((n - y - 1) / x + 1) * k;
        }
        cout << count << "\n";
    }
}