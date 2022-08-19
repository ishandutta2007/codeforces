#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> suf(n + 1);
    std::vector<int> b, cnt(n + 1), pos(n + 1);
    int xyx = 0;
    int len = 0;
    auto check = [&](int l, int r) {
        for (auto x : suf[r])
            if (x == r - l)
                return true;
        return false;
    };
    while (n--) {
        int a;
        std::cin >> a;
        ++len;
        suf[len].clear();
        if (len >= 2 && a == b.back())
            suf[len].push_back(2);
        for (auto x : suf[len - 1])
            if (x < len - 1 && b[len - x - 2] == a)
                suf[len].push_back(x + 2);
        b.push_back(a);
        if (!suf[len].empty() && check(len - suf[len][0] * 3 / 2, len - suf[len][0] / 2)) {
            b.resize(len - suf[len][0]);
            len = b.size();
            xyx += 2;
        }
        pos[len] = pos[len - 1];
        cnt[len] = cnt[len - 1];
        if (check(pos[len], len)) {
            pos[len] = (pos[len] + len) / 2;
            ++cnt[len];
        }
        int ans = xyx + cnt[len];
        for (int x = len; x > pos[len]; ) {
            if (!suf[x].empty() && x - suf[x][0] >= pos[len]) {
                x -= suf[x][0] / 2;
                ++ans;
            } else {
                break;
            }
        }
        std::cout << ans << " \n"[!n];
    }
    return 0;
}