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
        vector<string> sv;
        set<string> s;
        for (int i : ra(0, n)) {
            string a;
            cin >> a;
            sv.push_back(a);
            s.insert(a);
        }

        for (auto a : sv) {
            int ok = 0;
            for (int i : ra(1, ssize(a))) {
                string p = a.substr(0, i);
                string q = a.substr(i);
                if (s.contains(p) && s.contains(q)) {
                    ok = 1;
                }
            }
            cout << ok;
        }

        cout << '\n';
    }    
}