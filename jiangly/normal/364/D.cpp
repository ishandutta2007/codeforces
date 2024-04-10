#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    i64 ans = 0;
    
    auto start = std::chrono::steady_clock::now();
    std::mt19937 rnd(start.time_since_epoch().count());
    
    while ((std::chrono::steady_clock::now() - start).count() < 3e9) {
        int r = rnd() % n;
        
        std::vector<i64> p;
        std::vector<int> k;
        
        i64 v = a[r];
        for (i64 i = 2; i * i <= v; i++) {
            int t = 0;
            while (v % i == 0) {
                v /= i;
                t++;
            }
            if (t > 0) {
                p.push_back(i);
                k.push_back(t);
            }
        }
        
        if (v > 1) {
            p.push_back(v);
            k.push_back(1);
        }
        
        int m = p.size();
        std::vector<int> f(m + 1);
        f[0] = 1;
        for (int i = 0; i < m; i++) {
            f[i + 1] = f[i] * (k[i] + 1);
        }
        
        std::vector<i64> cnt(f[m]);
        
        for (int i = 0; i < n; i++) {
            i64 v = a[i];
            int mask = 0;
            for (int j = 0; j < m; j++) {
                for (int x = 0; x < k[j]; x++) {
                    if (v % p[j] == 0) {
                        v /= p[j];
                        mask += f[j];
                    }
                }
            }
            cnt[mask]++;
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = f[m] - 1; j >= 0; j--) {
                if (j / f[i] % (k[i] + 1) < k[i]) {
                    cnt[j] += cnt[j + f[i]];
                }
            }
        }
        
        for (int i = 0; i < f[m]; i++) {
            if (cnt[i] < (n + 1) / 2) {
                continue;
            }
            
            i64 v = 1;
            for (int j = 0; j < m; j++) {
                for (int x = 0; x < i / f[j] % (k[j] + 1); x++) {
                    v *= p[j];
                }
            }
            
            ans = std::max(ans, v);
        }
    }
    
    std::cout << ans << "\n";
    
    return 0;
}