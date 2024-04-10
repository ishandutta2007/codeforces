#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m, r, k;
    cin >> n >> m >> r >> k;
    
    auto compute = [n,m,r](long long i, long long j){
        return min({i + 1, n - i, r, n - r + 1}) * min({j + 1, m - j, r, m - r + 1});
    };

    set<pair<long long, long long>> seen;
    seen.insert({n/2, m/2});
    seen.insert({(n - 1)/2, m/2});
    seen.insert({n/2, (m - 1)/2});
    seen.insert({(n - 1)/2, (m - 1)/2});

    priority_queue<tuple<long long, int, int>> pq;
    for (auto p : seen) {
        pq.push({compute(p.first, p.second), p.first, p.second});
    }
    
    long long total = 0;
    while (k --> 0) {
        auto p = pq.top();
        pq.pop();
        total += get<0>(p);
        auto x = get<1>(p);
        auto y = get<2>(p);

        for (int dx = -1; dx < 2; dx++) {
            for (int dy = -1; dy < 2; dy++) {
                if (dx == 0 && dy == 0) continue;
                int X = x + dx;
                int Y = y + dy;
                if (X < 0 || X >= n || Y < 0 || Y >= m || seen.count({X, Y})) {
                    // nothing
                } else {
                    pq.push({compute(X, Y), X, Y});
                    seen.insert({X, Y});
                }
            }
        }
    }

    std::cout << std::fixed << std::setprecision(10);
    cout << total / (double)((n - r + 1)*(m - r + 1)) << endl;
}