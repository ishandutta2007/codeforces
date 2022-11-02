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

std::string s;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        std::cin >> s;
        for (int i = 1; i < n; ++i) {
            if (s[i] == '?' && s[i - 1] != '?') {
                s[i] = 'B' + 'R' - s[i - 1];
            }
        }
        for (int i = n - 2; ~i; --i) {
            if (s[i] == '?' && s[i + 1] != '?') {
                s[i] = 'B' + 'R' - s[i + 1];
            }
        }
        if (s[0] == '?') s[0] = 'B';
        for (int i = 1; i < n; ++i) {
            if (s[i] == '?' && s[i - 1] != '?') {
                s[i] = 'B' + 'R' - s[i - 1];
            }
        }
        std::cout << s << std::endl;
    }
    return 0;
}