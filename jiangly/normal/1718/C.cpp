#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, q;
    std::cin >> n >> q;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<int> ds;
    
    int x = n;
    for (int i = 2; i <= x; i++) {
        if (x % i == 0) {
            ds.push_back(n / i);
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    
    const int k = ds.size();
    std::vector<std::vector<i64>> sum;
    for (auto d : ds) {
        sum.emplace_back(d);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            sum[j][i % ds[j]] += a[i];
        }
    }
    std::multiset<i64> ms;
    for (int j = 0; j < k; j++) {
        for (int x = 0; x < ds[j]; x++) {
            ms.insert(1LL * ds[j] * sum[j][x]);
        }
    }
    
    std::cout << *ms.rbegin() << "\n";
    for (int i = 0; i < q; i++) {
        int p, x;
        std::cin >> p >> x;
        p--;
        
        for (int j = 0; j < k; j++) {
            int v = p % ds[j];
            ms.erase(ms.find(1LL * ds[j] * sum[j][v]));
            sum[j][v] += x - a[p];
            ms.insert(1LL * ds[j] * sum[j][v]);
        }
        a[p] = x;
        
        std::cout << *ms.rbegin() << "\n";
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