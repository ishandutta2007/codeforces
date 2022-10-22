#include <iostream>
#include <string>
#include <tuple>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
using namespace std;
typedef long long ll;

bool sortby2(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
    return (get<1>(a) < get<1>(b));
}

bool sortby3(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
    return (get<2>(a) < get<2>(b));
}

int main(void) {
    int n, m;
    cin >> n >> m;
    int sx, sy, fx, fy;
    cin >> sx >> sy >> fx >> fy;
    vector<vector<tuple<int, ll>>> graph(m + 2, vector<tuple<int, ll>>());
    vector<tuple<int, int, int>> pts(m);
    graph[0].push_back(make_tuple(m + 1, abs(sx - fx) + abs(sy - fy)));
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        pts[i] = make_tuple(i, x, y);
        graph[0].push_back(make_tuple(i + 1, min(abs(sx - x), abs(sy - y))));
        graph[i + 1].push_back(make_tuple(m + 1, abs(fx - x) + abs(fy - y)));
    }

    sort(pts.begin(), pts.end(), sortby2);
    for (int i = 0; i < m - 1; i++) {
        auto ixy1 = pts[i];
        auto ixy2 = pts[i + 1];
        int i1 = get<0>(ixy1), x1 = get<1>(ixy1), y1 = get<2>(ixy1);
        int i2 = get<0>(ixy2), x2 = get<1>(ixy2), y2 = get<2>(ixy2);
        graph[i1 + 1].push_back(make_tuple(i2 + 1, x2 - x1));
        graph[i2 + 1].push_back(make_tuple(i1 + 1, x2 - x1));
    }

    
    sort(pts.begin(), pts.end(), sortby3);
    for (int i = 0; i < m - 1; i++) {
        auto ixy1 = pts[i];
        auto ixy2 = pts[i + 1];
        auto i1 = get<0>(ixy1), x1 = get<1>(ixy1), y1 = get<2>(ixy1);
        auto i2 = get<0>(ixy2), x2 = get<1>(ixy2), y2 = get<2>(ixy2);
        graph[i1 + 1].push_back(make_tuple(i2 + 1, y2 - y1));
        graph[i2 + 1].push_back(make_tuple(i1 + 1, y2 - y1));
    }

    vector<ll> dist(m + 2, 3000000000);
    priority_queue<tuple<ll, int>, vector<tuple<ll, int>>, greater<tuple<ll, int>>> dijk;
    dijk.push(make_tuple(0, 0));
    while (!dijk.empty()) {
        auto di = dijk.top();
        dijk.pop();
        ll d = get<0>(di);
        int i = get<1>(di);
        if (dist[i] <= d) continue;
        dist[i] = d;
        for (auto ddii : graph[i]) {
            int ii = get<0>(ddii);
            ll dd  = get<1>(ddii);
            dijk.push(make_tuple(d + dd, ii));
        }
    }

    cout << dist[m + 1] << "\n";
}