#include <bits/stdc++.h>

#define Deb std::cerr
#define Debug Deb << "Debug(" << __LINE__ << "): "
#define fi first
#define se second
#define mkp std::make_pair

using int32 = int;
using int64 = long long;
using i3 = int32;
using i4 = int64;
using pi33 = std::pair<i3, i3>;
using pi34 = std::pair<i3, i4>;
using pi43 = std::pair<i4, i3>;
using pi44 = std::pair<i4, i4>;

const int N = 1000005;

int T;

int64 n, m, k, x, y, z, ans;
int64 a[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        if (a[n] == 0) {
            for (int i = 1; i <= n + 1; ++i) std::cout << i << ' ';
            std::cout << std::endl;
            continue;
        }
        if (a[1] == 1) {
            std::cout << n + 1 << ' ';
            for (int i = 1; i <= n; ++i) std::cout << i << ' ';
            std::cout << std::endl;
            continue;
        }
        for (int i = 2; i <= n; ++i) {
            if (a[i] == 1) {
                for (int k = 1; k < i; ++k) std::cout << k << ' ';
                std::cout << n + 1 << ' ';
                for (int k = i; k <= n; ++k) std::cout << k << ' ';
                std::cout << std::endl;
                break;
            }
        }
    }
    return 0;
}