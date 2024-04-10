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
        int a, b;
        cin >> a >> b;
        if ((a + b) % 2 == 0) {
            // svejedno ko krece
            int l = abs(a-b) / 2;
            int h = l + 2*min(a, b);
            cout << (h-l)/2 + 1 << '\n';
            for (int i=l; i<=h; i+=2) {
                cout << i << ' ';
            }
            cout << '\n';
        } else {
            // svejedno ko krece
            int l = abs(a-b) / 2;
            int h = l + 1 + 2*min(a, b);
            cout << (h-l) + 1 << '\n';
            for (int i=l; i<=h; i++) {
                cout << i << ' ';
            }
            cout << '\n';
        }
    }
}