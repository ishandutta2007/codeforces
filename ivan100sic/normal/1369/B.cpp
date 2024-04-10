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

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int first_one = R::find(s, '1') - begin(s);
        if (first_one == n) {
            // 000...000
            cout << s << '\n';
            continue;
        }

        int last_zero = -1;
        for (int i : ra(first_one, n)) {
            if (s[i] == '0') {
                last_zero = i;
            }
        }

        if (last_zero == -1) {
            cout << s << '\n';
        } else {
            cout << string(first_one + 1, '0') << string(n - last_zero - 1, '1') << '\n';
        }
    }
}