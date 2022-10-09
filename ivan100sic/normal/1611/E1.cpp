// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct tcase {

    int n, k;
    vector<int> a;
    vector<vector<int>> e;
    vector<int> dv, df;

    void bfs(vector<int>& d, const vector<int>& b) {
        d.resize(n+1, -1);
        queue<int> q;
        for (int x : b) {
            q.push(x);
            d[x] = 0;
        }
        while (q.size()) {
            int x = q.front(); q.pop();
            for (int y : e[x]) {
                if (d[y] == -1) {
                    d[y] = d[x] + 1;
                    q.push(y);
                }
            }
        }
    }

    tcase() {
        cin >> n >> k;
        a.resize(k);
        e.resize(n+1);
        for (int& x : a) cin >> x;

        for (int i : ra(0, n-1)) {
            int x, y;
            cin >> x >> y;
            e[x].push_back(y);
            e[y].push_back(x);
        }

        bfs(dv, {1});
        bfs(df, a);

        int sol = -1;

        for (int x : ra(2, n+1)) {
            if (e[x].size() == 1 && dv[x] < df[x]) {
                sol = x;
                break;
            }
        }

        cout << (sol != -1 ? "YES\n" : "NO\n");
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