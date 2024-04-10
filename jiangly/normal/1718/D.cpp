#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E9;

void solve() {
    int n, q;
    std::cin >> n >> q;
    
    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    const int k = std::count(a.begin(), a.end(), 0);
    
    std::vector<int> b(k - 1);
    for (int i = 0; i < k - 1; i++) {
        std::cin >> b[i];
    }
    
    std::vector<int> d(q);
    for (int i = 0; i < q; i++) {
        std::cin >> d[i];
    }
    
    std::vector<int> l(n), r(n, inf);
    for (int i = 0; i < n; i++) {
        if (a[i]) {
            l[i] = r[i] = a[i];
        }
    }
    
    std::vector<int> lc(n, -1), rc(n, -1);
    std::vector<int> s;
    
    for (int i = 0; i < n; i++) {
        while (!s.empty() && p[i] > p[s.back()]) {
            int x = s.back();
            rc[x] = lc[i];
            lc[i] = x;
            s.pop_back();
        }
        s.push_back(i);
    }
    
    while (s.size() > 1) {
        int x = s.back();
        s.pop_back();
        rc[s.back()] = x;
    }
    
    std::function<void(int)> dfs = [&](int x) {
        for (auto y : {lc[x], rc[x]}) {
            if (y == -1) {
                continue;
            }
            r[y] = std::min(r[y], r[x]);
            dfs(y);
            l[x] = std::max(l[x], l[y]);
        }
    };
    dfs(s[0]);
    
    bool nice = true;
    std::vector<std::array<int, 2>> ranges;
    for (int i = 0; i < n; i++) {
        if (!a[i]) {
            ranges.push_back({l[i], r[i]});
        }
        if (l[i] > r[i]) {
            nice = false;
        }
    }
    
    std::sort(ranges.begin(), ranges.end(), [&](auto a, auto b) {
        return a[1] < b[1];
    });
    
    int L = -1, R = -1;
    std::set<int> S;
    for (int i = 0; i < k - 1; i++) {
        S.insert(b[i]);
    }
    for (auto [l, r] : ranges) {
        auto it = S.lower_bound(l);
        if (it == S.end() || *it > r) {
            if (R == -1) {
                R = r;
            } else {
                nice = false;
            }
        } else {
            S.erase(it);
        }
    }
    
    std::sort(ranges.begin(), ranges.end(), std::greater());
    
    S.clear();
    for (int i = 0; i < k - 1; i++) {
        S.insert(b[i]);
    }
    for (auto [l, r] : ranges) {
        auto it = S.upper_bound(r);
        if (it == S.begin() || *std::prev(it) < l) {
            if (L == -1) {
                L = l;
            } else {
                nice = false;
            }
        } else {
            S.erase(std::prev(it));
        }
    }
    
    for (int i = 0; i < q; i++) {
        if (nice && L <= d[i] && d[i] <= R) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}