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

    int n, m;
    cin >> n >> m;
    vector<string> pairs, pals;
    set<string> st;
    for (int i : ra(0, n)) {
        string s;
        cin >> s;
        string r = s;
        R::reverse(r);

        if (r == s) {
            pals.push_back(s);
        } else if (st.contains(r)) {
            pairs.push_back(s);
        }
        st.insert(s);
    }

    string sol;
    if (pals.size() > 0) sol = pals[0];
    for (auto s : pairs) {
        sol += s;
        sol.insert(sol.begin(), s.rbegin(), s.rend());
    }

    cout << sol.size() << '\n' << sol << '\n';
}