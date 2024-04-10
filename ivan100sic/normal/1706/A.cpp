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
        int n, m;
        cin >> n >> m;
        vector<int> c(m);
        string s(m, 'B');
        for (int i : ra(0, n)) {
            int x;
            cin >> x;
            x--;
            x = min(x, m-1-x);
            c[x]++;
        }

        for (int i : ra(0, m)) {
            if (c[i] >= 2) {
                s[i] = s[m-1-i] = 'A';
            } else if (c[i] == 1) {
                s[i] = 'A';
            }
        }

        cout << s << '\n';
    }
    
}