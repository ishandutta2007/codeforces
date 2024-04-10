#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i)
            std::cin >> a[i];
        const int S = (1 << n) - 1;
        std::vector<int> sum(S + 1);
        for (int i = 1; i <= S; ++i) {
            if ((i & -i) == i) {
                sum[i] = a[__builtin_ctz(i)];
            } else {
                sum[i] = sum[i & -i] + sum[i & (i - 1)];
            }
        }
        std::vector<int> p(S);
        std::iota(p.begin(), p.end(), 1);
        std::sort(p.begin(), p.end(), [&](int i, int j) {return sum[i] < sum[j];});
        std::vector<std::vector<std::vector<std::pair<int, std::tuple<int, int, int>>>>> dp(S + 1);
        for (auto &v : dp)
            v.resize(n);
        dp[0][0].emplace_back(0, std::make_tuple(0, -1, -1));
        int last = 0;
        std::vector<std::vector<std::tuple<int, int, int>>> temp(S + 1, std::vector<std::tuple<int, int, int>>(n, std::make_tuple(-1, -1, -1)));
        std::vector<std::pair<int, int>> pos;
        auto addTrans = [&](int s, int i, auto val) {
            if (!dp[s][i].empty() && std::get<0>(val) <= std::get<0>(dp[s][i].back().second))
                return;
            if (std::get<0>(temp[s][i]) == -1)
                pos.emplace_back(s, i);
            temp[s][i] = std::max(temp[s][i], val);
        };
        auto doTrans = [&](int x) {
            for (auto [s, i] : pos) {
                dp[s][i].emplace_back(x, temp[s][i]);
                temp[s][i] = std::make_tuple(-1, -1, -1);
            }
            pos.clear();
        };
        for (auto s : p) {
            if (sum[s] > last)
                doTrans(last);
            last = sum[s];
            for (int t = S ^ s; ; t = (t - 1) & (S ^ s)) {
                std::pair<int, int> max{-1, -1};
                for (int i = 0; (1 << i) <= s; ++i) {
                    if (!dp[t][i].empty())
                        max = std::max(max, std::make_pair(std::get<0>(dp[t][i].back().second), i));
                    if ((s >> i & 1) && max.first != -1)
                        addTrans(s | t, i, std::make_tuple(max.first + 1, t, max.second));
                }
                if (t == 0)
                    break;
            }
        }
        doTrans(last);
        std::pair<int, int> max{-1, -1};
        for (int i = 0; i < n; ++i)
            max = std::max(max, std::make_pair(std::get<0>(dp[S][i].back().second), i));
        std::cout << n - max.first << "\n";
        int s = S, i = max.second;
        std::vector<int> ind(n);
        std::iota(ind.begin(), ind.end(), 0);
        auto operate = [&](int i, int j) {
            std::cout << ind[i] + 1 << " " << ind[j] + 1 << "\n";
            for (int k = i + 1; k < n; ++k)
                --ind[k];
        };
        last = 1e9;
        while (s != 0) {
            while (dp[s][i].back().first >= last)
                dp[s][i].pop_back();
            int t = std::get<1>(dp[s][i].back().second);
            int j = std::get<2>(dp[s][i].back().second);
            last = sum[s ^ t];
            for (int k = 0; k < n; ++k)
                if (((s ^ t) >> k & 1) && k != i)
                    operate(k, i);
            s = t;
            i = j;
        }
    }
    return 0;
}