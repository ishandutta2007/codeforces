#include <bits/stdc++.h>

using i64 = long long;

struct Min {
    int x;
    Min(int x = 1e9) : x(x) {}
};

Min operator+(const Min &a, const Min &b) {
    return std::min(a.x, b.x);
}

template<class Info,
    class Merge = std::plus<Info>>
struct SegmentTree {
    const int n;
    const Merge merge;
    std::vector<Info> info;
    SegmentTree(int n) : n(n), merge(Merge()), info(4 << std::__lg(n)) {}
    SegmentTree(std::vector<Info> init) : SegmentTree(init.size()) {
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = merge(info[2 * p], info[2 * p + 1]);
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        return merge(rangeQuery(2 * p, l, m, x, y), rangeQuery(2 * p + 1, m, r, x, y));
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
};

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> p(n), l(n), r(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
        l[i] = std::max(0, i - p[i]);
        r[i] = std::min(n, i + 1 + p[i]);
    }
    
    std::vector<int> dp(n + 1), g(n + 1, 1e9);
    
    SegmentTree<Min> seg(n + 1);
    
    std::vector<int> s;
    for (int i = 0; i < n; i++) {
        if (dp[i] > i) {
            dp[i + 1] = std::max(dp[i], r[i]);
        }
        
        if (i < g[dp[i]]) {
            seg.modify(dp[i], g[dp[i]] = i);
        }
        
        int j = seg.rangeQuery(l[i], n + 1).x;
        if (j < n) {
            dp[i + 1] = std::max(dp[i + 1], i);
            
            if (j < i) {
                dp[i + 1] = std::max(dp[i + 1], r[*std::lower_bound(s.begin(), s.end(), j)]);
            }
        }
        while (!s.empty() && r[i] >= r[s.back()]) {
            s.pop_back();
        }
        s.push_back(i);
    }
    
    if (dp[n] < n) {
        std::cout << "NO\n";
        return;
    }
    
    std::cout << "YES\n";
    
    int i = n;
    std::string ans(n, 'R');
    
    while (dp[i] > 0) {
        i--;
        if (dp[i] > i && dp[i + 1] == std::max(dp[i], r[i])) {
            continue;
        }
        ans[i] = 'L';
        int mx = 0;
        for (int j = i; ; j--) {
            if (j < i) {
                mx = std::max(mx, r[j]);
            }
            if (i - p[i] <= dp[j] && dp[i + 1] == std::max(mx, j)) {
                i = j;
                break;
            }
        }
    }
    std::cout << ans << "\n";
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