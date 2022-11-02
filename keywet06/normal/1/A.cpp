#include <bits/stdc++.h>

using int64 = long long;

namespace oct {

void sync();

inline void sync() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
}

} // namespace oct

int64 n, m, a;

int main() {
    oct::sync();
    std::cin >> n >> m >> a;
    std::cout << ((n + a - 1) / a) * ((m + a - 1) / a) << std::endl;
    return 0;
}