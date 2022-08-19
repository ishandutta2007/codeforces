#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;
    
    std::set<int> p;
    std::multiset<int> d;
    
    auto add = [&](int x) {
        auto it = p.insert(x).first;
        auto r = std::next(it);
        
        if (it != p.begin() && r != p.end())
            d.erase(d.find(*r - *std::prev(it)));
        
        if (it != p.begin())
            d.insert(x - *std::prev(it));
        
        if (r != p.end())
            d.insert(*r - x);
    };
    
    auto del = [&](int x) {
        auto it = p.erase(p.find(x));
        
        if (it != p.begin())
            d.erase(d.find(x - *std::prev(it)));
        
        if (it != p.end())
            d.erase(d.find(*it - x));
        
        if (it != p.begin() && it != p.end())
            d.insert(*it - *std::prev(it));
    };
    
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        add(x);
    }
    
    auto get = [&]() {
        if (p.size() <= 1)
            return 0;
        return *p.rbegin() - *p.begin() - *d.rbegin();
    };
    
    std::cout << get() << "\n";
    
    while (q--) {
        int t, x;
        std::cin >> t >> x;
        
        if (t == 0) {
            del(x);
        } else {
            add(x);
        }
        
        std::cout << get() << "\n";
    }
    
    return 0;
}