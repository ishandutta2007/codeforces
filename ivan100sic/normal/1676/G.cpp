// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n;
vector<int> e[4005];
string s;

pair<int, int> dfs(int x, int p) {
    int c=0, z=0;
    for (int y : e[x]) {
        auto [u, v] = dfs(y, x);
        c += u;
        z += v; 
    }
    c += s[x] == 'W' ? 1 : -1;
    z += c == 0;
    return {c, z};
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        fill(e, e+n+1, vector<int>{});
        for (int i : ra(2, n+1)) {
            int p;
            cin >> p;
            e[p].push_back(i);
        }
        cin >> s;
        s = " " + s;

        cout << dfs(1, 1).second << '\n';
    }
}