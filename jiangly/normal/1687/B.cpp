#include <bits/stdc++.h>

using i64 = long long;

int query(std::string s) {
    std::cout << "? " << s << std::endl;
    int ans;
    std::cin >> ans;
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> l(m);
    for (int i = 0; i < m; i++) {
        std::string s(m, '0');
        s[i] = '1';
        l[i] = query(s);
    }
    
    std::vector<int> p(m);
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(), [&](int i, int j) {
        return l[i] < l[j];
    });
    
    int ans = 0;
    std::string s(m, '0');
    int last = 0;
    for (auto i : p) {
        s[i] = '1';
        int cur = query(s);
        if (cur == last + l[i]) {
            ans += l[i];
        }
        last = cur;
    }
    
    std::cout << "! " << ans << std::endl;
    
    return 0;
}