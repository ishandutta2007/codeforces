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

        const int n = ssize(s);

        vector<vector<pair<int, int>>> e(n+1);
        map<pair<int, int>, pair<int, int>> mp;

        int m;
        cin >> m;
        for (int sid : ra(1, m+1)) {
            string p;
            cin >> p;
            for (int i=0; i<=n-ssize(p); i++) {
                if (equal(begin(p), end(p), begin(s) + i)) {
                    e[i].emplace_back(i+ssize(p), 1);
                    mp[{i, i+ssize(p)}] = {sid, i+1}; 
                }
            }
        }

        for (int i : ra(0, n)) {
            e[i+1].emplace_back(i, 0);
        }

        vector<int> d(n+1, -1), p(n+1, -1);
        d[0] = 0;
        set<pair<int, int>> pq;
        pq.insert({0, 0});

        while (pq.size()) {
            auto [dx, x] = *pq.begin();
            pq.erase(pq.begin());
            for (auto [y, w] : e[x]) {
                if (d[y] == -1 || d[y] > dx + w) {
                    pq.erase({d[y], y});
                    d[y] = dx + w;
                    p[y] = x;
                    pq.insert({d[y], y});
                }
            }
        }

        if (d[n] == -1) {
            cout << "-1\n";
        } else {
            int x = n;
            cout << d[n] << '\n';
            while (x != 0) {
                int y = p[x];
                if (y < x) {
                    auto [ugly, problem] = mp[{y, x}];
                    cout << ugly << ' ' << problem << '\n';
                }
                x = y;
            }
        }
    }
}