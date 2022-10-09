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
        int n = ssize(s);
        map<char, int> last;
        for (int i : ra(0, n)) {
            last[s[i]] = i;
        }

        int j = 0;
        for (int i : ra(0, n)) {
            if (last[s[i]] == i) {
                j = i;
                break;
            }
        }

        cout << string_view(s).substr(j) << '\n';
    }
}