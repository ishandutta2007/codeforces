#include <bits/stdc++.h>

using i64 = long long;

struct Node {
    Node *ch[2];
    std::pair<int, int> v;
    Node() : ch{}, v(-1, -1) {}
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;
    
    std::vector<std::pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].first;
        a[i].second = i;
    }
    std::sort(a.begin(), a.end());
    
    Node *root = new Node();
    
    std::vector<std::pair<int, int>> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = {1, -1};
        auto t = root;
        for (int j = 29; j >= 0 && t != nullptr; j--) {
            int d = a[i].first >> j & 1;
            if (~k >> j & 1) {
                if (t->ch[!d] != nullptr) {
                    dp[i] = std::max(dp[i], t->ch[!d]->v);
                }
                t = t->ch[d];
            } else {
                t = t->ch[!d];
            }
        }
        if (t != nullptr) {
            dp[i] = std::max(dp[i], t->v);
        }
        auto v = std::pair(dp[i].first + 1, i);
        
        t = root;
        t->v = std::max(t->v, v);
        for (int j = 29; j >= 0; j--) {
            int d = a[i].first >> j & 1;
            if (t->ch[d] == nullptr) {
                t->ch[d] = new Node();
            }
            t = t->ch[d];
            t->v = std::max(t->v, v);
        }
    }
    
    int i = std::max_element(dp.begin(), dp.end()) - dp.begin();
    if (dp[i].first == 1) {
        std::cout << "-1\n";
    } else {
        std::cout << dp[i].first << "\n";
        while (i != -1) {
            std::cout << a[i].second + 1 << " \n"[dp[i].second == -1];
            i = dp[i].second;
        }
    }
    
    return 0;
}