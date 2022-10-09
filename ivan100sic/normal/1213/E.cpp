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

    int n;
    string a, b;
    cin >> n >> a >> b;

    for (bool spread : {true, false}) {
        string s = "abc";
        do {
            string t;
            if (spread) {
                for (char c : s) {
                    t += string(n, c);
                }
            } else {
                for (int i : ra(0, n)) {
                    t += s;
                }
            }

            if (t.find(a) == t.npos && t.find(b) == t.npos) {
                cout << "YES\n" << t << '\n';
                return 0;
            }
        } while (R::next_permutation(s).found);
    }
}