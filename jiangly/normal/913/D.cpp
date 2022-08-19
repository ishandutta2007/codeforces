#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, T;
    std::cin >> n >> T;
    
    std::vector<int> a(n), t(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i] >> t[i];
    }
    
    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(), [&](int i, int j) { return a[i] > a[j]; });
    
    std::priority_queue<std::pair<int, int>> h;
    int tim = 0;
    for (int i = n, j = 0; i >= 0; i--) {
        while (j < n && a[p[j]] >= i) {
            h.emplace(t[p[j]], p[j]);
            tim += t[p[j]];
            j++;
        }
        
        while (int(h.size()) > i) {
            tim -= h.top().first;
            h.pop();
        }
        
        if (int(h.size()) == i && tim <= T) {
            std::cout << i << "\n";
            std::cout << i << "\n";
            while (!h.empty()) {
                std::cout << h.top().second + 1;
                h.pop();
                if (!h.empty()) {
                    std::cout << " ";
                }
            }
            std::cout << "\n";
            return 0;;
        }
    }
    assert(false);
    
    return 0;
}