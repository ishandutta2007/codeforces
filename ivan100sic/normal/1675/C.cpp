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
        string s;
        cin >> s;
        int n = s.size();
        vector<int> p0(n+1), s1(n+1);
        for (int i : ra(0, n)) {
            p0[i+1] = p0[i] + (s[i] == '0');
            s1[i+1] = s1[i] + (s[n-1-i] == '1');
        }

        int sol = 0;
        for (int i : ra(0, n)) {
            if (p0[i] == 0 && s1[n-1-i] == 0) {
                sol++;
            }
        }

        cout << sol << '\n';
    }
}