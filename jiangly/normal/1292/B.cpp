#include <bits/stdc++.h>
using namespace std;
constexpr int N = 100'000;
long long x0, y0, bx, by, t, xs, ys;
int ax, ay;
vector<pair<long long, long long>> p;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;
    while (x0 <= 5E16 && y0 <= 5E16) {
        p.emplace_back(x0, y0);
        x0 = ax * x0 + bx;
        y0 = ay * y0 + by;
    }
    int ans = 0;
    for (int i = 0; i < int(p.size()); ++i)
        for (int j = 0; j < int(p.size()); ++j)
            if (abs(xs - p[i].first) + abs(ys - p[i].second) + abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second) <= t)
                ans = max(ans, abs(i - j) + 1);
    cout << ans << endl;
    return 0;
}