#include <bits/stdc++.h>

using i64 = long long;

int lowbit(int x) {
    for (int i = 1; ; i *= 10) {
        if (x / i % 10 > 0) {
            return i;
        }
    }
}

void solve() {
    int s, n;
    std::cin >> s >> n;
    
    std::vector<int> res{s};
    
    while (int(res.size()) < n) {
        if (res[0] != lowbit(res[0])) {
            int x = lowbit(res[0]);
            res.push_back(x);
            res[0] -= x;
            continue;
        }
        std::sort(res.begin(), res.end());
        int i = 0;
        while (res[i] == 1) {
            i++;
        }
        std::swap(res[0], res[i]);
        res.push_back(res[0] / 10);
        res[0] -= res[0] / 10;
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << res[i] << " \n"[i == n - 1];
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