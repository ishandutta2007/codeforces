#include <bits/stdc++.h>

using i64 = long long;

constexpr long double eps = 1E-9;

struct Segment {
    long double x;
    long double y;
};

bool operator<(const Segment &a, const Segment &b) {
    return a.y / a.x > b.y / b.x;
}

void solve() {
    int n;
    std::cin >> n;
    
    int a, b;
    std::cin >> a >> b;
    
    std::vector<int> p(n), q(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> q[i];
    }
    
    if (a == 0 && b == 0) {
        for (int i = 0; i < n; i++) {
            std::cout << 0 << "\n";
        }
        return;
    }
    
    long double x0 = a, y0 = b, x1 = a, y1 = b;
    
    std::multiset<Segment> segs;
    for (int i = 0; i < n; i++) {
        segs.insert({2 * p[i], -2 * q[i]});
        x0 -= p[i];
        y0 += q[i];
        x1 += p[i];
        y1 -= q[i];
        
        while (x0 < 0) {
            assert(!segs.empty());
            auto [x, y] = *segs.begin();
            segs.erase(segs.begin());
            if (x0 + x < eps) {
                x0 += x;
                y0 += y;
            } else {
                segs.insert({x + x0, y + y / x * x0});
                y0 -= y / x * x0;
                x0 = 0;
            }
        }
        
        while (y1 < 0) {
            assert(!segs.empty());
            auto [x, y] = *segs.rbegin();
            segs.erase(std::prev(segs.end()));
            if (y1 - y < eps) {
                x1 -= x;
                y1 -= y;
            } else {
                segs.insert({x - x / y * y1, y - y1});
                x1 -= x / y * y1;
                y1 = 0;
            }
        }
        
        std::cout << x1 << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cout << std::fixed << std::setprecision(10);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}