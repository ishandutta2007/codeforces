#include <bits/stdc++.h>

using int64 = long long;

const int64 INF = 4e18;

char Ch;

int n, b, p, m, Tot;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n >> b >> p >> m;
    std::vector<int> x, Mul;
    std::vector<std::vector<int>> a;
    for (int i = 0, y; i < n; ++i) {
        std::cin >> Ch >> y;
        if (Ch == '+') {
            x.push_back(y), ++Tot;
        } else if (y > 1) {
            a.push_back(std::move(x)), Mul.push_back(y);
        }
    }
    a.push_back(std::move(x));
    int l = Mul.size();
    for (int i = 0; i <= l; ++i) std::sort(a[i].begin(), a[i].end());
    std::vector<std::vector<int64>> Suf(l + 1);
    for (int i = 0; i <= l; ++i) {
        Suf[i].resize(a[i].size() + 1);
        for (int j = int(a[i].size()) - 1; j >= 0; --j) Suf[i][j] = Suf[i][j + 1] + a[i][j];
    }
    int64 ans = 0;
    std::map<int, std::vector<int>> Mop;
    for (int i = 0; i < l; ++i) Mop[Mul[i]].push_back(i);
    std::vector<bool> move(l);
    auto Dfs = [&](auto Self, auto it) {
        if (it == Mop.end()) {
            std::vector<int64> Val(l + 1, 1);
            int64 cost = 0;
            for (int i = 0; i < l; ++i) {
                if (move[i]) {
                    Val[l] *= Mul[i], cost += m;
                } else {
                    Val[i] *= Mul[i];
                }
            }
            for (int i = l - 1; i >= 0; --i) Val[i] *= Val[i + 1];
            if (cost > b) return;
            const int rest = std::min((b - cost) / p, 1LL * Tot);
            int64 cur = Val[0];
            for (int i = 0; i <= l; ++i) cur += Val[i] * Suf[i][0];
            auto Get = [&](auto x) {
                int Cnt = 0;
                int64 Sum = 0;
                for (int i = 0; i <= l; ++i) {
                    if (Val[i] == Val[0]) continue;
                    int64 y = x / (Val[0] - Val[i]);
                    auto it = std::upper_bound(a[i].begin(), a[i].end(), y);
                    int k = it - a[i].begin();
                    Cnt += a[i].size() - k, Sum += Suf[i][k] * (Val[0] - Val[i]);
                }
                return std::pair(Cnt, Sum);
            };
            int64 Le = 0, Ri = INF, x;
            while (Le < Ri) x = Le + Ri >> 1, Get(x).first > rest ? Le = x + 1 : Ri = x;
            auto [c, s] = Get(Le);
            cur += s + 1LL * (rest - c) * Le, ans = std::max(ans, cur);
            return;
        }
        Self(Self, std::next(it));
        for (int i = 0; i < int(it->second.size()); ++i) move[it->second[i]] = true, Self(Self, std::next(it));
        for (auto i : it->second) move[i] = false;
    };
    Dfs(Dfs, Mop.begin());
    std::cout << ans << "\n";
    return 0;
}