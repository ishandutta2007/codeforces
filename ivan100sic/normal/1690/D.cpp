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
        int n, k, a;
        string s;
        cin >> n >> k >> s;

        a = n;
        vector<int> z(n+1);
        for (int i : ra(0, n)) {
            z[i+1] = z[i] + (s[i] == 'W');
        }

        for (int i : ra(0, n-k+1)) {
            a = min(a, z[i+k] - z[i]);
        }

        cout << a << '\n';
    }
    
}