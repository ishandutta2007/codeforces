#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2E5 + 100;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<int> c(N);
    std::set<int> z{-1}, o{-1}, no{-1};
    for (int i = 0; i < N; i++) {
        z.insert(i);
    }
    
    std::function<void(int, int)> add = [&](int x, int t) {
        z.erase(x);
        o.erase(x);
        no.erase(x);
        c[x] += t;
        if (c[x] == -2) {
            c[x] = 0;
            add(x + 1, -1);
        } else if (c[x] == 2) {
            c[x] = 0;
            add(x + 1, 1);
        }
        if (c[x] == 0) {
            z.insert(x);
        } else if (c[x] == 1) {
            o.insert(x);
        } else {
            no.insert(x);
        }
    };
    
    for (int i = 0; i < n; i++) {
        add(a[i], 1);
    }
    
    for (int i = 0; i < q; i++) {
        int x, v;
        std::cin >> x >> v;
        x--;
        add(a[x], -1);
        add(a[x] = v, 1);
        
        int m = *o.rbegin();
        m = std::max(*std::next(o.rbegin()), *std::prev(z.lower_bound(m))) + 1;
        
        if (*std::prev(o.lower_bound(m)) < *std::prev(no.lower_bound(m))) {
            m--;
        }
        
        std::cout << m << "\n";
    }
    
    return 0;
}