#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, a, b;
    std::cin >> n >> a >> b;
    std::string s;
    std::cin >> s;
    
    std::vector<char> alpha(n);
    for (int i = 0; i < n; ++i) {
        alpha[i] = s[i];
    }
    std::sort(alpha.begin(), alpha.end());
    alpha.erase(std::unique(alpha.begin(), alpha.end()), alpha.end());
    
    int m = alpha.size();
    
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = std::lower_bound(alpha.begin(), alpha.end(), s[i]) - alpha.begin();
    }
    
    std::vector<int> l(m, n), r(m), cnt(m);
    for (int i = 0; i < n; ++i) {
        l[v[i]] = std::min(l[v[i]], i);
        r[v[i]] = i;
        cnt[v[i]]++;
    }
    
    std::vector<int> p(m);
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(), [&](int i, int j) {
        return l[i] < l[j];
    });
    
    std::vector<bool> f(1 << m);
    
    f[0] = true;
    
    for (int s = 1; s < (1 << m); ++s) {
        int R = -1, L = n, C = 0;
        bool ok = false;
        for (int i = 0; i < m; ++i) {
            if (s >> i & 1) {
                ok = ok || f[s ^ (1 << i)];
                R = std::max(R, r[i]);
                L = std::min(L, l[i]);
                C += cnt[i];
            }
        }
        if (ok && a * (R - L + 1) <= C * b) {
            f[s] = true;
        }
        int t = 0;
        for (int i = 0; i < m; ++i) {
            if (s >> p[i] & 1) {
                t |= 1 << p[i];
                f[s] = f[s] || (f[t] && f[s ^ t]);
            }
        }
    }
    
    std::vector<char> ans;
    for (int i = 0; i < m; ++i) {
        if (f[(1 << m) - 1 - (1 << i)]) {
            ans.push_back(alpha[i]);
        }
    }
    
    std::cout << ans.size();
    for (auto c : ans) {
        std::cout << " " << c;
    }
    
    std::cout << "\n";
    
    return 0;
}