#include <iostream>
#include <vector>
int q, x, mex;
std::vector<int> cnt;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> q >> x;
    cnt.resize(x);
    for (int i = 0; i < q; ++i) {
        int y;
        std::cin >> y;
        ++cnt[y % x];
        while (cnt[mex % x] > mex / x)
            ++mex;
        std::cout << mex << "\n";
    }
    return 0;
}