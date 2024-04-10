#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<i64> s(n + 1);
    for (int i = 0; i < n; i++) {
        s[i + 1] = s[i] + a[i];
    }
    
    std::vector<int> lc(n, -1), rc(n, -1);
    std::vector<int> stack;
    for (int i = 0; i < n; i++) {
        while (!stack.empty() && a[i] > a[stack.back()]) {
            int x = stack.back();
            rc[x] = lc[i];
            lc[i] = x;
            stack.pop_back();
        }
        stack.push_back(i);
    }
    
    while (stack.size() > 1) {
        int x = stack.back();
        stack.pop_back();
        rc[stack.back()] = x;
    }
    
    bool nice = true;
    
    std::vector<i64> min(n), max(n);
    
    std::function<void(int, int, int)> dfs = [&](int x, int l, int r) {
        if (l > r) {
            return;
        }
        dfs(lc[x], l, x - 1);
        dfs(rc[x], x + 1, r);
        
        min[x] = s[x];
        max[x] = s[x + 1];
        if (lc[x] != -1) {
            min[x] = std::min(min[x], min[lc[x]]);
        }
        if (rc[x] != -1) {
            max[x] = std::max(max[x], max[rc[x]]);
        }
        if (max[x] - min[x] > a[x]) {
            nice = false;
        }
        if (rc[x] != -1) {
            min[x] = std::min(min[x], min[rc[x]]);
        }
        if (lc[x] != -1) {
            max[x] = std::max(max[x], max[lc[x]]);
        }
    };
    dfs(stack[0], 0, n - 1);
    
    if (nice) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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