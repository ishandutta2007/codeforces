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
        cin >> n;
        vector<int> b(n);
        for (int&x : b) cin >> x;

        for (int i : ra(0, n)) {
            int x;
            cin >> x;
            string s;
            cin >> s;
            int z = 0;
            for (char c : s) {
                z += c == 'U' ? 1 : -1;
            }
            b[i] -= z;
        }

        for (int x : b) {
            cout << (x%10+10)%10 << ' ';
        }
        cout << '\n';
    }
}