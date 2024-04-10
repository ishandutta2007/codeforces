#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s;
    std::cin >> s;
    
    int n = s.length();
    
    std::vector<int> sum{0}, pre{-1};
    std::vector<int> lst(2 * n + 1, -1);
    lst[n] = 0;
    
    auto pop = [&]() {
        int x = sum.back();
        sum.pop_back();
        lst[x + n] = pre.back();
        pre.pop_back();
    };
    
    for (int i = n - 1; i >= 0; i--) {
        sum.push_back(sum.back() + (s[i] == '(' ? -1 : 1));
        pre.push_back(lst[sum.back() + n]);
        lst[sum.back() + n] = sum.size() - 1;
        if (s[i] == '(') {
            int j = pre.back();
            if (j < 0) {
                continue;
            } else if (j == 0) {
                for (int t = sum.size() - 1; t--; ) {
                    pop();
                }
            } else if (sum[j - 1] > sum[j]) {
                int a = sum.size() - 2, b = j - 1;
                while (b > 0 && sum[a] > sum.back() && sum[b] > sum.back() && sum[a] == sum[b]) {
                    a--;
                    b--;
                }
                if (sum[a] < sum[b] || b == 0) {
                    for (int t = sum.size() - 1 - j; t--; ) {
                        pop();
                    }
                }
            }
        }
    }
    std::string ans;
    for (int i = sum.size() - 1; i > 0; i--) {
        ans += sum[i] < sum[i - 1] ? '(' : ')';
    }
    
    std::cout << ans << '\n';
    
    return 0;
}