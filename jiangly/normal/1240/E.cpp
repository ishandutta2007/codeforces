#include <bits/stdc++.h>
using LL = int64_t;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int &i : a)
        std::cin >> i;
    std::sort(a.begin(), a.end());
    int maxa = a.back();
    std::vector<std::vector<int>> mx(maxa + 1);
    for (auto &i : mx)
       i.assign(2, -1);
    std::vector<int> cnt(maxa + 1);
    for (int i : a)
        ++cnt[i];
    for (int i = 1; i <= maxa; ++i) {
        if (cnt[i] >= 2)
            mx[i][0] = mx[i][1] = i;
        else if (cnt[i] == 1) {
            mx[i][0] = i;
            mx[i][1] = mx[i - 1][0];
        } else
            mx[i] = mx[i - 1];
        cnt[i] += cnt[i - 1];
    }
    LL ans = 0;
    for (int y = 2; y <= maxa; ++y) {
        int more[] = {-1, -1};
        LL cnty = 0;
        for (int k = 1; k <= maxa / y; ++k)
            cnty += (LL)k * (cnt[std::min((k + 1) * y - 1, maxa)] - cnt[k * y - 1]);
        for (int k = maxa / y; k >= 0; --k) {
            more[1] = std::max(more[1], mx[std::min((k + 1) * y - 1, maxa)][0] - k * y);
            if (more[0] < more[1])
                std::swap(more[0], more[1]);
            more[1] = std::max(more[1], mx[std::min((k + 1) * y - 1, maxa)][1] - k * y);
            int x = std::min((LL)(k * y + more[0]) / 2, cnty - k);
            if (x >= 2)
                ans = std::max(ans, LL(x) * y);
            if (more[1] != -1) {
                x = std::min((LL)k * y + more[1], cnty - 2 * k);
                if (x >= 2)
                    ans = std::max(ans, LL(x) * y);
            }
            if (n - cnt[std::max(0, k * y + more[0] - 1)] >= 2) {
                x = std::min((LL)k * y + more[0], cnty - 2 * k - 1);
                if (x >= 2)
                    ans = std::max(ans, LL(x) * y);
            }
        }
    }
    std::cout << ans << "\n";
    return 0;
}