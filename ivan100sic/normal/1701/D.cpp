// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int ceildiv(int x, int y) {
    return (x+y-1) / y;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        const auto N = ra(1, n+1);
        vector<int> b(n+1), a(n+1);
        vector<array<int, 3>> cand;
        for (int i : N) {
            cin >> b[i];
            cand.push_back({ceildiv(i+1, b[i]+1), (b[i] ? i/b[i] : n), i});
        }

        R::sort(cand, [](auto x, auto y) {
            return x[0] < y[0];
        });

        set<array<int, 2>> pq;

        auto it = cand.begin();
        for (int i : N) {
            while (it != cand.end() && i >= it->at(0)) {
                pq.insert({it->at(1), it->at(2)});
                ++it;
            }

            auto [_, id] = *pq.begin();
            pq.erase(pq.begin());
            a[id] = i;
        }
        
        for (int i : N) {
            cout << a[i] << " \n"[i == n];
        }
    }
}