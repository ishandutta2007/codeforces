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
        ll x;
        int n;
        cin >> x >> n;
        for (int i=0; i<n-1; i++) {
            for (ll y=1'000'000'000; y; y/=10) {
                if (x-y >= n-1-i) {
                    cout << y << ' ';
                    x -= y;
                    break;
                }
            }
        }
        cout << x << '\n';
    }
}