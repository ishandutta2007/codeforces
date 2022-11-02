#include <bits/stdc++.h>

using int64 = long long;

template <typename Type>
struct Fenwick {
    const int n;
    std::vector<Type> a;
    Fenwick(int n) : n(n), a(n) {}
    void Add(int x, Type v) {
        for (int i = x + 1; i <= n; i += i & -i) a[i - 1] += v;
    }
    Type Sum(int x) {
        Type Ans = 0;
        for (int i = x; i; i &= i - 1) Ans += a[i - 1];
        return Ans;
    }
    Type rangeSum(int l, int r) { return Sum(r) - Sum(l); }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q;
    std::cin >> n >> q;
    std::vector<int> p(n), Pow(n + 1);
    for (int i = 0; i < n; ++i) std::cin >> p[i], Pow[p[i]] = i;
    std::vector<std::vector<int>> Div(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i) Div[j].push_back(i);
    }
    std::vector<int> L(n), R(n), s{-1};
    for (int i = 0; i < n; ++i) {
        while (s.size() > 1 && p[i] > p[s.back()]) s.pop_back();
        L[i] = s.back() + 1, s.push_back(i);
    }
    s = {n};
    for (int i = n - 1; i >= 0; --i) {
        while (s.size() > 1 && p[i] > p[s.back()]) s.pop_back();
        R[i] = s.back() - 1, s.push_back(i);
    }
    std::vector<std::array<int, 3>> c;
    std::vector<std::array<int, 2>> a, b;
    for (int i = 0; i < n; ++i) {
        a.clear(), b.clear();
        for (auto x : Div[p[i]]) {
            int u = Pow[x], v = Pow[p[i] / x];
            if (u >= v) continue;
            u = std::min(u, i), v = std::max(v, i);
            if (L[i] <= u && v <= R[i]) a.push_back({u, v});
        }
        std::sort(a.begin(), a.end());
        for (auto [x, y] : a) {
            while (!b.empty() && y <= b.back()[1]) b.pop_back();
            if (b.empty() || x > b.back()[0]) b.push_back({x, y});
        }
        if (!b.empty()) {
            for (int i = 0; i < int(b.size()); ++i) {
                c.push_back({b[i][0], b[i][1], 1});
                if (i > 0) c.push_back({b[i - 1][0], b[i][1], -1});
            }
            if (L[i] > 0) c.push_back({L[i] - 1, b[0][1], -1});
            if (R[i] + 1 < n) c.push_back({b.back()[0], R[i] + 1, -1});
            if (L[i] > 0 && R[i] + 1 < n) c.push_back({L[i] - 1, R[i] + 1, 1});
        }
    }
    std::sort(c.begin(), c.end(), std::greater());
    std::vector<std::array<int, 3>> qry(q);
    for (int i = 0, l, r; i < q; ++i) std::cin >> l >> r, --l, --r, qry[i] = {l, r, i};
    std::sort(qry.begin(), qry.end(), std::greater());
    std::vector Add(4, Fenwick<int64>(n));
    std::vector<int64> Ans(q);
    int j = 0;
    for (auto [l, r, i] : qry) {
        while (j < int(c.size()) && c[j][0] >= l) {
            auto [x, y, f] = c[j];
            Add[0].Add(y, f * (x + 1));
            Add[1].Add(y, 1LL * f * (x + 1) * (y - 1));
            Add[2].Add(y, f);
            Add[3].Add(y, f * (y - 1));
            ++j;
        }
        Ans[i] = Add[0].Sum(r + 1) * r - Add[1].Sum(r + 1) - Add[2].Sum(r + 1) * l * r + Add[3].Sum(r + 1) * l;
    }
    for (int i = 0; i < q; ++i) std::cout << Ans[i] << "\n";
    return 0;
}