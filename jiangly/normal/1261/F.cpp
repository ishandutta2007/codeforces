#include <bits/stdc++.h>
using namespace std;
constexpr int P = 998244353;
int getsum(long long x, long long y) {return 1LL * (y - x) % P * ((x + y - 1) % P) % P;}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    set<pair<long long, long long>> a, b;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        long long l, r;
        cin >> l >> r;
        ++r;
        while (l + (l & -l) <= r) {
            a.emplace(l, l & -l);
            l += l & -l;
        }
        while (l < r) {
            a.emplace(r - (r & -r), r & -r);
            r -= r & -r;
        }
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        long long l, r;
        cin >> l >> r;
        ++r;
        while (l + (l & -l) <= r) {
            b.emplace(l, l & -l);
            l += l & -l;
        }
        while (l < r) {
            b.emplace(r - (r & -r), r & -r);
            r -= r & -r;
        }
    }
    vector<pair<long long, long long>> s;
    auto work = [&](const auto &a) {
        vector<vector<pair<long long, long long>>> b(60);
        for (int i = 0; i < 60; ++i) {
            auto len = 1ll << i;
            for (auto p : a) {
                if (p.second > len)
                    continue;
                auto l = p.first & ~(len - 1);
                b[i].emplace_back(l, len);
            }
            sort(b[i].begin(), b[i].end());
            b[i].erase(unique(b[i].begin(), b[i].end()), b[i].end());
        }
        return b;
    };
    auto solve = [&](const auto &a, const auto &b) {
        auto c = work(b);
        for (auto x : a) {
            for (auto y : c[__builtin_ctzll(x.second)]) {
                auto l = y.first & ~(x.second - 1);
                s.emplace_back(l ^ x.first, (l ^ x.first) + x.second);
            }
        }
    };
    solve(a, b);
    solve(b, a);
    sort(s.begin(), s.end());
    long long x = 0;
    int sum = 0;
    for (auto p : s) {
        if (p.second >= x)
            sum = (sum + getsum(max(p.first, x), p.second)) % P;
        x = max(x, p.second);
    }
    cout << 1LL * (P + 1) / 2 * sum % P << endl;
    return 0;
}