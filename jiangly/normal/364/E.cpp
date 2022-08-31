#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, k;
    std::cin >> n >> m >> k;
    
    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    
    auto merge = [&](const auto &a, const auto &b) {
        std::vector<int> c(k + 1);
        for (int i = 0, x = 0, y = 0; i <= k; i++) {
            if (a[x] < b[y]) {
                c[i] = a[x++];
            } else {
                c[i] = b[y++];
            }
        }
        
        return c;
    };
    
    std::vector<std::vector<int>> up, down;
    auto solve = [&](auto self, auto s) -> i64 {
        int n = s.size();
        int m = s[0].size();
        
        if (n == 1 && m == 1) {
            return s[0][0] - '0' == k;
        }
        
        if (n < m) {
            std::vector t(m, std::string(n, '0'));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    t[j][i] = s[i][j];
                }
            }
            s = std::move(t);
            std::swap(n, m);
        }
        
        i64 ans = 0;
        
        int mid = n / 2;
        
        up.assign(m, std::vector(k + 1, mid));
        down.assign(m, std::vector(k + 1, n - mid));
        for (int i = 0; i < m; i++) {
            for (int j = mid - 1, x = 0; j >= 0 && x <= k; j--) {
                if (s[j][i] == '1') {
                    up[i][x++] = mid - 1 - j;
                }
            }
            for (int j = mid, x = 0; j < n && x <= k; j++) {
                if (s[j][i] == '1') {
                    down[i][x++] = j - mid;
                }
            }
        }
        
        for (int l = 0; l < m; l++) {
            std::vector<int> a(k + 1, mid), b(k + 1, n - mid);
            for (int r = l; r < m; r++) {
                a = merge(a, up[r]);
                b = merge(b, down[r]);
                
                for (int i = 0; i <= k; i++) {
                    int u = a[i] - (i > 0 ? a[i - 1] : 0);
                    int v = b[k - i] - (k - i > 0 ? b[k - i - 1] : 0);
                    
                    ans += u * v;
                }
            }
        }
        
        ans += self(self, std::vector(s.begin(), s.begin() + mid));
        ans += self(self, std::vector(s.begin() + mid, s.end()));
        
        return ans;
    };
    
    std::cout << solve(solve, s) << "\n";
    
    return 0;
}