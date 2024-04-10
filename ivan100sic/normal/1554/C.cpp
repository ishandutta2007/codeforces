// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        if (n > m) {
            cout << "0\n";
        } else {
            vector<ll> b;
            for (int i=30; i>=0; i--) {
                if (!(n & (1ll << i))) {
                    b.push_back(1ll << i);
                }
            }

            ll t = n;
            for (int i=0; i<(int)b.size(); i++) {
                ll z = t;
                for (int j=i+1; j<(int)b.size(); j++) z |= b[j];
                if (z <= m) {
                    t |= b[i];
                }
            }
            cout << (t ^ n) << '\n';
        }
    }
}