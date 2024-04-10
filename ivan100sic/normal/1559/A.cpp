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
        int n;
        cin >> n;
        unsigned x = ~0u;
        while (n--) {
            unsigned y;
            cin >> y;
            x = x & y;
        }
        cout << x << '\n';
    }
}