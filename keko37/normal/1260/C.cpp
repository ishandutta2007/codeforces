#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

int t, a, b, k;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> a >> b >> k;
        if (a > b) swap(a, b);
        if (k == 1) {
            cout << "REBEL\n";
            continue;
        } else if (a == b) {
            cout << "OBEY\n";
            continue;
        } else {
            int d = __gcd(a, b);
            a /= d, b /= d;
            int val = (b - 1 + a - 1) / a;
            if (val < k) cout << "OBEY\n"; else cout << "REBEL\n";
        }
    }
    return 0;
}