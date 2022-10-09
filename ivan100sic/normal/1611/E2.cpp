// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct tcase {
    int n, k, bad;
    vector<int> a;
    vector<vector<int>> e;
    vector<int> st, has, gu;

    void dfs1(int x, int p, int d) {
        st.push_back(x);

        if (has[x]) {
            gu[st[d - d/2]] = 1;
        }

        for (int y : e[x]) {
            if (y == p) continue;
            dfs1(y, x, d+1);
        }

        st.pop_back();
    }

    int dfs2(int x, int p) {
        if (gu[x]) return 1;

        if (x != 1 && e[x].size() == 1) {
            bad = 1;
            return 0;
        }

        int z = 0;
        for (int y : e[x]) {
            if (y == p) continue;
            z += dfs2(y, x);
        }

        return z;
    }

    tcase() {
        cin >> n >> k;
        e.resize(n+1);
        has.resize(n+1);
        gu.resize(n+1);

        for (int i : ra(0, k)) {
            int x;
            cin >> x;
            has[x] = 1;
        }

        for (int i : ra(0, n-1)) {
            int x, y;
            cin >> x >> y;
            e[x].push_back(y);
            e[y].push_back(x);
        }

        dfs1(1, 1, 0);
        bad = 0;
        int z = dfs2(1, 1);
        if (bad) z = -1;
        cout << z << '\n';
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        tcase{};
    }
}