// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

struct pt {
    int x, y;

    bool operator< (const pt& o) const {
        return tie(x, y) < tie(o.x, o.y);  
    }
};

struct info {
    int dist;
    pt closest;
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n;
    cin >> n;

    vector<pt> a(n);
    for (auto& [x, y] : a) cin >> x >> y;

    set s(begin(a), end(a));

    map<pt, info> mp;
    queue<pt> q;
    for (auto [x, y] : a) {
        bool gap = 0;
        int gx=0, gy=0;
        for (int d : ra(0, 4)) {
            int xx = x + dx[d];
            int yy = y + dy[d];
            if (!s.contains({xx, yy})) {
                gx = xx;
                gy = yy;
                gap = 1;
            }
        }

        if (gap) {
            mp[{x, y}] = {1, {gx, gy}};
            q.push({x, y});
        }
    }

    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        auto [x, y] = p;
        auto pinfo = mp[p];
        for (int d : ra(0, 4)) {
            pt r = {x + dx[d], y + dy[d]};
            if (s.contains(r) && !mp.contains(r)) {
                mp[r] = {pinfo.dist + 1, pinfo.closest};
                q.push(r);
            }
        }
    }

    for (int i : ra(0, n)) {
        auto q = mp[a[i]].closest;
        cout << q.x << ' ' << q.y << '\n';
    }
}