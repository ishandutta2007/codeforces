// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct decrset {
    vector<int> cnt;
    int hi;

    decrset(int n) : cnt(n, 0), hi(0) {}

    void add(int x) {
        cnt[x]++;
        hi = max(hi, x);
    }

    void rem(int x) {
        cnt[x]--;
        while (hi >= 0 && cnt[hi] == 0) {
            hi--;
        }
    }

    int operator() () {
        return hi;
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string has(m+1, 0);

        for (int i : ra(0, n)) {
            int x;
            cin >> x;
            has[x] = 1;
        }

        int sol = m-1;

        vector<int> dp(m+1, 2*m);

        decrset eng(2*m+1);
        for (int i : ra(0, m+1)) {
            if (has[i]) {
                eng.add(2*m);
            }
        }

        auto go = [&](int x, int y) {
            if (dp[x] > y) {
                if (has[x]) eng.rem(dp[x]);
                dp[x] = y;
                if (has[x]) eng.add(dp[x]);
            }
        };

        for (int x=m; x>=1; x--) {
            go(x, x);
            for (int i=1; i*x<=m; i++) {
                go(x*i, max(dp[i], x));
            }
            sol = min(sol, eng() - x);            
        }

        cout << sol << '\n';
    }
}