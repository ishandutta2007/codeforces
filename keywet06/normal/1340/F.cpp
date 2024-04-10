#include <bits/stdc++.h>

constexpr long long P = 1000000000039;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

long long mul(long long a, long long b) { return __int128(a) * b % P; }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    const int BASE = rnd() % 1000000 + 3e6 + 3;
    int n, k, q;
    std::cin >> n >> k;
    std::vector<int> s(n);
    for (int i = 0; i < n; ++i) std::cin >> s[i];
    const int B = 2 * std::sqrt(n);
    const int cntB = (n + B - 1) / B;
    std::vector<std::vector<int>> rem(cntB), ins(cntB);
    std::vector<std::vector<long long>> hrem(cntB), hins(cntB);
    std::vector<bool> ok(cntB);
    std::vector<long long> pw(n + 1);
    pw[0] = 1;
    for (int i = 1; i <= n; ++i) pw[i] = pw[i - 1] * BASE % P;
    auto initHash = [&](auto v) {
        int n = v.size();
        std::vector<long long> h(n + 1);
        for (int i = 0; i < n; ++i) h[i + 1] = (h[i] * BASE + v[i]) % P;
        return h;
    };
    auto getHash = [&](auto &v, int l, int r) { return (v[r] + mul(P - v[l], pw[r - l])) % P; };
    auto build = [&](int l, int r, auto &rem, auto &ins, auto &hrem, auto &hins) {
        std::vector<int> stk;
        for (int i = l; i < r; ++i) {
            if (s[i] > 0) {
                stk.push_back(s[i]);
            } else if (!stk.empty() && stk.back() > 0 && stk.back() != -s[i]) {
                return false;
            } else if (stk.empty() || stk.back() < 0) {
                stk.push_back(s[i]);
            } else {
                stk.pop_back();
            }
        }
        rem.clear();
        ins.clear();
        for (auto i : stk) {
            if (i < 0) {
                rem.push_back(-i);
            } else {
                ins.push_back(i);
            }
        }
        std::reverse(rem.begin(), rem.end());
        hrem = initHash(rem);
        hins = initHash(ins);
        return true;
    };
    auto rebuild = [&](int b) { ok[b] = build(b * B, std::min(n, (b + 1) * B), rem[b], ins[b], hrem[b], hins[b]); };
    for (int i = 0; i < cntB; ++i) rebuild(i);
    auto query = [&](int l, int r) {
        int bl = l / B, br = (r - 1) / B;
        if (bl == br) {
            std::vector<int> stk;
            for (int i = l; i < r; ++i) {
                if (s[i] > 0) {
                    stk.push_back(s[i]);
                } else if (!stk.empty() && stk.back() > 0 && stk.back() != -s[i]) {
                    return false;
                } else if (stk.empty() || stk.back() < 0) {
                    stk.push_back(s[i]);
                } else {
                    stk.pop_back();
                }
            }
            return stk.empty();
        } else {
            std::vector<int> lrem, lins, rrem, rins;
            std::vector<long long> lhrem, lhins, rhrem, rhins;
            if (!build(l, (bl + 1) * B, lrem, lins, lhrem, lhins)) return false;
            if (!lrem.empty()) return false;
            if (!build(br * B, r, rrem, rins, rhrem, rhins)) return false;
            if (!rins.empty()) return false;
            std::vector<std::pair<std::vector<long long> &, int>> stk;
            if (!lins.empty()) stk.emplace_back(lhins, lins.size());
            for (int b = bl + 1; b < br; ++b) {
                if (!ok[b]) return false;
                int x = rem[b].size();
                while (x > 0) {
                    if (stk.empty()) return false;
                    if (x >= stk.back().second) {
                        if (getHash(hrem[b], x - stk.back().second, x) !=
                            getHash(stk.back().first, 0, stk.back().second))
                            return false;
                        x -= stk.back().second;
                        stk.pop_back();
                    } else if (getHash(hrem[b], 0, x) !=
                               getHash(stk.back().first, stk.back().second - x, stk.back().second)) {
                        return false;
                    } else {
                        stk.back().second -= x;
                        break;
                    }
                }
                if (!ins[b].empty()) stk.emplace_back(hins[b], ins[b].size());
            }
            int x = rrem.size();
            while (x > 0) {
                if (stk.empty()) return false;
                if (x >= stk.back().second) {
                    if (getHash(rhrem, x - stk.back().second, x) != getHash(stk.back().first, 0, stk.back().second))
                        return false;
                    x -= stk.back().second;
                    stk.pop_back();
                } else if (getHash(rhrem, 0, x) !=
                           getHash(stk.back().first, stk.back().second - x, stk.back().second)) {
                    return false;
                } else {
                    stk.back().second -= x;
                    break;
                }
            }
            return stk.empty();
        }
    };
    std::cin >> q;
    while (q--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int pos, t;
            std::cin >> pos >> t;
            --pos;
            s[pos] = t;
            rebuild(pos / B);
        } else {
            int l, r;
            std::cin >> l >> r;
            --l;
            if (query(l, r)) {
                std::cout << "Yes\n";
            } else {
                std::cout << "No\n";
            }
        }
    }
    return 0;
}