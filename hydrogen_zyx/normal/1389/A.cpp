#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll a, b;
    ll t;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (2 * a > b) {
            cout << -1 << ' ' << -1 << endl;
        } else {
            cout << a << ' ' << 2 * a << endl;
        }
    }
}