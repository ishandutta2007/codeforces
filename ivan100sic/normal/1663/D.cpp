// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

// testcase 1: "ABC" 0 -> "YES"

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    string s;
    int x;
    cin >> s >> x;

    if (s == "ABC") {
        if (x <= 1999) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else if (s == "ARC") {
        if (x <= 2799) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else if (s == "AGC") {
        if (x >= 1200) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else {
        return 1;
    }
}