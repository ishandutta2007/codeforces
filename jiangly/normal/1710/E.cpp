#include <bits/stdc++.h>

using i64 = long long;

i64 get(int n, int m, std::vector<int> &vr, std::vector<int> &vc) {
    i64 cur = 0, ans = 1E18;
    // for (int i = 0; i < n; i++) {
    //     std::cerr << vr[i] << " \n"[i == n - 1];
    // }
    // for (int i = 0; i < m; i++) {
    //     std::cerr << vc[i] << " \n"[i == m - 1];
    // }
    for (int i = 1, j = 0; i <= n; i++) {
        cur += vr[i - 1];
        while (j < m && vc[j] < i) {
            cur += vc[j++];
        }
        ans = std::min(ans, cur - 1LL * i * j);
    }
    // std::cerr << ans << "\n";
    // std::cerr << "---\n";
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }
    std::vector<int> p(n), q(m);
    std::iota(p.begin(), p.end(), 0);
    std::iota(q.begin(), q.end(), 0);
    
    std::sort(p.begin(), p.end(), [&](int i, int j) {
        return a[i] < a[j];
    });
    std::sort(q.begin(), q.end(), [&](int i, int j) {
        return b[i] < b[j];
    });
    
    int l = 1, r = a[0] + b[0] + 1;
    while (r - l > 1) {
        int x = (l + r) / 2;
        
        std::vector<int> sumr(n), sumc(m);
        for (int i = 0, j = m; i < n; i++) {
            while (j > 0 && a[p[i]] + b[q[j - 1]] >= x) {
                j--;
            }
            sumr[p[i]] = m - j;
        }
        for (int j = 0, i = n; j < m; j++) {
            while (i > 0 && a[p[i - 1]] + b[q[j]] >= x) {
                i--;
            }
            sumc[q[j]] = n - i;
        }
        
        auto vr = sumr, vc = sumc;
        std::sort(vr.begin(), vr.end());
        std::sort(vc.begin(), vc.end());
        
        i64 min = std::min(0LL, get(n, m, vr, vc));
        vr = sumr;
        std::sort(vr.begin() + 1, vr.end());
        i64 min1 = get(n, m, vr, vc);
        vc = sumc;
        std::sort(vr.begin(), vr.end());
        std::sort(vc.begin() + 1, vc.end());
        min1 = std::min(min1, get(m, n, vc, vr));
        assert(min <= min1);
        if (min == min1) {
            r = x;
        } else {
            l = x;
        }
    }
    
    std::cout << l << "\n";
    
    return 0;
}