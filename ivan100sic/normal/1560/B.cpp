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
        int a, b, c;
        cin >> a >> b >> c;
        if (a > b) swap(a, b);
        if (2*a > b || c > 2*(b-a)) {
            cout << "-1\n";
        } else if (c > b-a) {
            cout << c-b+a << '\n';
        } else {
            cout << c+b-a << '\n';
        }
    }
}