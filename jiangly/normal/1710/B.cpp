#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 inf = 1E18;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> x(n), p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> p[i];
    }
    
    auto v = x;
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    
    int c = v.size();
    
    std::vector<int> coef(n);
    std::vector<i64> val(n);
    
    for (int i = 0; i < n; i++) {
        int j = std::lower_bound(v.begin(), v.end(), x[i]) - v.begin();
        int l = std::lower_bound(v.begin(), v.end(), x[i] - p[i]) - v.begin();
        int r = std::lower_bound(v.begin(), v.end(), x[i] + p[i]) - v.begin();
        val[l] += p[i] - x[i];
        val[j] -= p[i] - x[i];
        val[j] += p[i] + x[i];
        if (r < c) {
            val[r] -= p[i] + x[i];
        }
        coef[l] += 1;
        coef[j] -= 1;
        coef[j] += -1;
        if (r < c) {
            coef[r] -= -1;
        }
    }
    for (int i = 1; i < c; i++) {
        coef[i] += coef[i - 1];
        val[i] += val[i - 1];
    }
    for (int i = 0; i < c; i++) {
        val[i] += 1LL * coef[i] * v[i];
    }
    bool nice = true;
    for (int i = 0; i < c; i++) {
        if (val[i] <= m) {
            val[i] = -inf;
        } else {
            val[i] -= m;
            nice = false;
        }
    }
    if (nice) {
        std::cout << std::string(n, '1') << "\n";
        return;
    }
    auto pre = val, suf = val;
    for (int i = 1; i < c; i++) {
        pre[i] = std::max(pre[i], pre[i - 1] + v[i] - v[i - 1]);
    }
    for (int i = c - 2; i >= 0; i--) {
        suf[i] = std::max(suf[i], suf[i + 1] + v[i + 1] - v[i]);
    }
    std::string ans;
    for (int i = 0; i < n; i++) {
        int j = std::lower_bound(v.begin(), v.end(), x[i]) - v.begin();
        ans += p[i] >= std::max(pre[j], suf[j]) ? '1' : '0';
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