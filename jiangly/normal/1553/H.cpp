#include <bits/stdc++.h>

using i64 = long long;

void chkmin(int &a, int b) {
    a = std::min(a, b);
}
void chkmax(int &a, int b) {
    a = std::max(a, b);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::sort(a.begin(), a.end());
    
    std::vector<int> ans(1 << k, 1 << k);
    
    std::vector<int> mn(1 << k), mx(1 << k);
    for (int d = 0; d < k; d++) {
        std::vector<int> res(1 << (d + 1), 1 << k);
        std::vector<int> newmn(1 << k, 1 << k), newmx(1 << k);
        for (int h = 0, l = 0, r = 0; h < (1 << (k - d - 1)); h++, l = r) {
            while (r < n && h == (a[r] >> (d + 1))) {
                r++;
            }
            int m = l;
            while (m < r && (~a[m] >> d & 1)) {
                m++;
            }
            for (int x = 0; x < (1 << d); x++) {
                int mn0 = mn[(h << (d + 1)) + x];
                int mn1 = mn[(h << (d + 1)) + x + (1 << d)];
                int mx0 = mx[(h << (d + 1)) + x];
                int mx1 = mx[(h << (d + 1)) + x + (1 << d)];
                if (l < m && m < r) {
                    chkmin(res[x], (1 << d) + mn1 - mx0);
                    chkmin(res[x + (1 << d)], (1 << d) + mn0 - mx1);
                }
                if (l < m) {
                    chkmin(newmn[(h << (d + 1)) + x], mn0);
                    chkmin(newmn[(h << (d + 1)) + x + (1 << d)], (1 << d) + mn0);
                    chkmax(newmx[(h << (d + 1)) + x], mx0);
                    chkmax(newmx[(h << (d + 1)) + x + (1 << d)], (1 << d) + mx0);
                }
                if (m < r) {
                    chkmin(newmn[(h << (d + 1)) + x], (1 << d) + mn1);
                    chkmin(newmn[(h << (d + 1)) + x + (1 << d)], mn1);
                    chkmax(newmx[(h << (d + 1)) + x], (1 << d) + mx1);
                    chkmax(newmx[(h << (d + 1)) + x + (1 << d)], mx1);
                }
            }
        }
        mn = std::move(newmn);
        mx = std::move(newmx);
        for (int i = 0; i < (1 << k); i++) {
            ans[i] = std::min(ans[i], res[i & ((1 << (d + 1)) - 1)]);
        }
    }
    
    for (int i = 0; i < (1 << k); i++) {
        std::cout << ans[i] << " \n"[i == (1 << k) - 1];
    }
    
    return 0;
}