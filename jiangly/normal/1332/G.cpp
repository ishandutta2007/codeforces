// luogu
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    std::vector<int> smx, smn;
    auto binarySearch = [&](int l, int r, auto f) {
        while (l < r) {
            int m = (l + r) / 2;
            if (f(m)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    };
    std::vector<std::vector<int>> f4(n, {-1, -1, -1, -1}), f3(n, {-1, -1, -1});
    std::vector<int> cnt(n, 2);
    std::set<int> pos, mxs, mns;
    for (int i = 0; i < n; ++i) {
        while (!smx.empty() && a[i] > a[smx.back()]) {
            if (--cnt[smx.back()] == 0)
                pos.insert(smx.back());
            mxs.insert(smx.back());
            smx.pop_back();
        }
        while (!smn.empty() && a[i] < a[smn.back()]) {
            if (--cnt[smn.back()] == 0)
                pos.insert(smn.back());
            mns.insert(smn.back());
            smn.pop_back();
        }
        smx.push_back(i);
        smn.push_back(i);
        if (i > 0) {
            f3[i] = f3[i - 1];
            f4[i] = f4[i - 1];
        }
        int pmx = binarySearch(0, smx.size(), [&](int j) {return a[smx[j]] == a[i];}) - 1;
        int pmn = binarySearch(0, smn.size(), [&](int j) {return a[smn[j]] == a[i];}) - 1;
        if (pmx != -1) {
            auto it = mxs.lower_bound(smx[pmx]);
            if (it != mxs.begin()) {
                std::vector g{*std::prev(it), smx[pmx], i};
                if (g[0] > f3[i][0])
                    f3[i] = g;
            }
        }
        if (pmn != -1) {
            auto it = mns.lower_bound(smn[pmn]);
            if (it != mns.begin()) {
                std::vector g{*std::prev(it), smn[pmn], i};
                if (g[0] > f3[i][0])
                    f3[i] = g;
            }
        }
        if (pmx != -1 && pmn != -1) {
            auto it = pos.lower_bound(std::min(smx[pmx], smn[pmn]));
            if (it != pos.begin()) {
                int p0 = *std::prev(it);
                int p1 = binarySearch(0, smx.size(), [&](int j) {return smx[j] > p0;});
                int p2 = binarySearch(0, smn.size(), [&](int j) {return smn[j] > p0;});
                std::vector g{p0, smx[p1], smn[p2], i};
                if (g[1] > g[2])
                    std::swap(g[1], g[2]);
                if (g[0] > f4[i][0])
                    f4[i] = g;
            }
        }
    }
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        --l;
        --r;
        if (f4[r][0] >= l) {
            std::cout << 4 << "\n";
            for (int i = 0; i < 4; ++i)
                std::cout << f4[r][i] + 1 << " \n"[i == 3];
        } else if (f3[r][0] >= l) {
            std::cout << 3 << "\n";
            for (int i = 0; i < 3; ++i)
                std::cout << f3[r][i] + 1 << " \n"[i == 2];
        } else {
            std::cout << 0 << "\n\n";
        }
    }
    return 0;
}