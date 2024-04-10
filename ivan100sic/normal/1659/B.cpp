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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        if (k % 2) {
            for (char& c : s) c ^= 1;
        }

        vector<int> sol(n);
        for (int i : ra(0, n)) {
            if (s[i] == '0' && k > 0) {
                s[i] = '1';
                sol[i]++;
                k--;
            }
        }

        if (k % 2) {
            s[n-1] ^= 1;
        }
        sol[n-1] += k;
        k = 0;

        cout << s << '\n';
        for (int x : sol) cout << x << ' ';
        cout << '\n';
    }
}