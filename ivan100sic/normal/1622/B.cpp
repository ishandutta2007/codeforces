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
        const auto N = ra(1, n+1);
        vector<int> p(n+1), q(n+1);
        for (int i : N) {
            cin >> p[i];
        }

        string s;
        cin >> s;
        s = string(" ") + s;

        int cz = R::count(s, '0');
        
        for (char c : {'0', '1'}) {
            int l;
            if (c == '0') l = 1;
            else l = cz + 1;

            vector<int> b;
            for (int i : N) {
                if (s[i] == c) {
                    b.push_back(i);
                }
            }

            R::sort(b, [&](int i, int j) { return p[i] < p[j]; });

            for (int j : ra(0, ssize(b))) {
                int i = b[j];
                q[i] = j + l;
            }
        }

        for (int i : N) cout << q[i] << ' ';
        cout << '\n';
    }
    
}