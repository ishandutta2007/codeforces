#include <bits/stdc++.h>

int t;
int n, a, b;

bool judge(std::vector<int> ans) {
    int n = ans.size();
    for (int i = 1; i < n / 2; i++) {
        if (ans[i] < ans[0]) return false;
    }
    for (int i = n / 2; i < n - 1; i++) {
        if (ans[i] > ans[n-1]) return false;
    }
    return true;
}

int main() {
    std::cin >> t;
    while (t--) {
        std::cin >> n >> a >> b;
        std::vector<int> ans;
        std::vector<int> vis(101, 0);
        ans.push_back(a);
        for (int i = n; i >= 1; i--) {
            if (i == b || i == a) {
                continue;
            }
            ans.push_back(i);
            vis[i] = 1;
        }
        ans.push_back(b);
        if (!judge(ans)) {
            std::cout << -1 << std::endl;
        } else {
            for (int i = 0; i < ans.size(); i++) {
                std::cout << ans[i] << " ";
            }
            std::cout << std::endl;
        }
    }
    return 0;
}