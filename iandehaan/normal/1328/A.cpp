#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        if (a % b == 0) cout << 0 << endl;
        else {
            ll rem = a%b;
            cout << (b-rem) << endl;
        }
    }
}