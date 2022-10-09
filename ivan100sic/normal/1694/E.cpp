// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n, m;
vector<int> ef[200005], eb[200005];
int d[200005], committed[200005];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> m;
    for (int i : ra(0, m)) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        ef[x].push_back(y);
        eb[y].push_back(x);
    }

    fill(d, d+n-1, 123123123);
    
    // uncommited values
    set<pair<int, int>> pq;
    pq.insert({0, n-1});

    while (pq.size()) {
        auto [dx, x] = *pq.begin();
        pq.erase(pq.begin());

        // commit x-dx
        for (int y : eb[x]) {
            int dy = dx + ssize(ef[y]) - committed[y];
            if (dy < d[y]) {
                pq.erase({d[y], y});
                d[y] = dy;
                pq.insert({d[y], y});
            }
            committed[y]++;
        }
    }

    cout << d[0] << '\n';
}