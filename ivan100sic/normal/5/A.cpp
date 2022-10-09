// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    string s;
    ll p = 0, q = 0;
    while (getline(cin, s)) {
        if (s[0] == '+') {
            p++;
        } else if (s[0] == '-') {
            p--;
        } else {
            q += p * (s.size() - s.find(':') - 1);
        }
    }
    
    cout << q << '\n';
}