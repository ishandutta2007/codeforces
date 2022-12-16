#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;

        ll sm = (n-1)*(n-2)/2;
        bool first = true;
        for (int i = 0; i < n; i++) {
            if (first) {
                if (k > sm) {
                    k -= sm;
                    cout << 'b';
                    first = false;
                } else {
                    cout << 'a';
                }
                sm -= (n-i-2);
            } else {
                if (k == (n-i)) {
                    cout << 'b';
                } else {
                    cout << 'a';
                }
            }
        }
        cout << endl;
    }
}