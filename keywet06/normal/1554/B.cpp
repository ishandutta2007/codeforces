#include <bits/stdc++.h>
 
using int64 = long long;
 
const int N = 1000005;
 
int64 ans;
 
int T, n, x, y, z, k;
int a[N];
 
int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n >> k;
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        ans = -10000000000000000ll;
        for (int i = n; i; --i) {
            for (int j = i - 1; j; --j) {
                if (int64(i) * j < ans) break;
                ans = std::max(ans, int64(i) * j - k * int64(a[i] | a[j]));
            }
        }
        std::cout << ans << '\n';
    }
    return 0;
}