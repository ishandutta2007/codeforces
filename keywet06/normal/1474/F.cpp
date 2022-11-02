#include <bits/stdc++.h>

using int32 = int;
using int64 = long long;
using i5 = int32;
using i6 = int64;
using veci5 = std::vector<i5>;
using veci6 = std::vector<i6>;

const int64 P = 998244353;

veci6 binpow(int len, int64 deg) {
    if (deg == 1) return veci6(len, 1);
    veci6 part = binpow(len, deg / 2), w(len);
    auto D = [&](int i, int j) {
        if (i % 2 == 0) return part[j - i];
        return j - i - 1 >= 0 ? part[j - i - 1] : 0;
    };
    for (int j = 0; j < len; ++j) {
        for (int i = 0; i <= j; ++i) w[j] = (w[j] + D(0, i) * D(i, j)) % P;
    }
    if (deg % 2 == 1) {
        veci6 w2(len);
        for (int j = 0; j < len; ++j) {
            for (int i = 0; i <= j; ++i) {
                w2[j] = (w2[j] + (i != j || j % 2 == 0 ? w[i] : 0)) % P;
            }
        }
        return w2;
    }
    return w;
}

void sitr(veci6 &dp, veci6 &L, veci6 &R, veci6 &fl, int64 z) {
    veci6 dp2(dp.size());
    for (int i = 0; i < dp.size(); ++i) {
        for (int j = 0; j < i + (fl[i] == 1); ++j) {
            if (L[i] <= z && z <= R[i] && L[j] <= z - 1 && z - 1 <= R[j]) {
                dp2[i] = (dp2[i] + dp[j]) % P;
            }
        }
    }
    dp = dp2;
}

int64 calls = 0;

int64 solve(veci6 b) {
    int sz = b.size() - 1;
    calls += sz;
    veci6 c = b, L(sz), R(sz), fl(sz, 1);
    std::sort(c.begin(), c.end());
    for (int i = 0; i + 1 < b.size(); ++i) {
        L[i] = b[i], R[i] = b[i + 1];
        if (i != 0) L[i] += L[i] < R[i] ? 1 : -1;
        if (L[i] > R[i]) std::swap(L[i], R[i]), fl[i] = -1;
    }
    veci6 dp(sz);
    int64 fr = c[0], to = c.back();
    for (int i = 0; i < sz; ++i) {
        if (L[i] <= fr && fr <= R[i]) dp[i] = 1;
    }
    int64 lst = fr;
    for (auto p : c) {
        int64 z = p - 2;
        if (lst < z) {
            int64 d = z - lst;
            veci5 act(sz);
            for (int i = 0; i < sz; ++i) {
                for (int j = 0; j < i + (fl[i] == 1); ++j) {
                    if (L[i] <= z && z <= R[i] && L[j] <= z && z <= R[j]) {
                        act[i] = act[j] = 1;
                    }
                }
            }
            int cnt = 0;
            veci5 link(sz);
            for (int i = 0; i < sz; ++i) {
                if (act[i]) link[i] = cnt++;
            }
            veci6 fast = binpow(cnt, d), dp2(sz);
            auto D = [&](int i, int j) {
                if (i % 2 == 0) return fast[j - i];
                return (j - i - 1 >= 0 ? fast[j - i - 1] : 0);
            };
            for (int i = 0; i < sz; ++i) {
                for (int j = 0; j <= i; ++j) {
                    dp2[i] = (dp2[i] + dp[j] * D(link[j], link[i])) % P;
                }
            }
            dp = dp2, lst = z;
        }
        if (lst < (z = p - 1)) sitr(dp, L, R, fl, z), lst = z;
        if (lst < (z = p)) sitr(dp, L, R, fl, z), lst = z;
        if ((z = p + 1) <= to && lst < z) sitr(dp, L, R, fl, z), lst = z;
    }
    int64 res = 0;
    for (int i = 0; i < sz; ++i) {
        if (L[i] <= to && to <= R[i]) res = (res + dp[i]) % P;
    }
    return res;
}

int sign(int64 x) { return (x > 0) - (x < 0); }

int main() {
    int n = 300;
    std::cin >> n;
    int64 x = 0;
    std::cin >> x;
    veci6 a;
    for (int i = 0; i < n; ++i) {
        x = i % 2 == 0 ? 1000000000 : x = -999000000 - i;
        std::cin >> x;
        if (x != 0) {
            a.size() && sign(a.back()) == sign(x) ? void(a[a.size() - 1] += x)
                                                  : a.push_back(x);
        }
    }
    veci6 ps;
    ps.push_back(1);
    n = a.size();
    for (int i = 0; i < n; ++i) ps.push_back(a[i] + ps.back());
    ++n;
    int64 max_len = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (ps[i] < ps[j]) {
                max_len = std::max(max_len, ps[j] - ps[i] + 1);
            }
        }
    }
    if (max_len == 1) {
        int64 ans = 1;
        std::cout << 1 << " ";
        for (int i = 0; i < a.size(); ++i) ans = (ans + abs(a[i])) % P;
        std::cout << ans << std::endl;
        return 0;
    }
    std::cout << max_len << " ";
    int64 ans = 0;
    int i = 0;
    while (i < n) {
        int id = -1;
        for (int j = i + 1; j < n; ++j) {
            if (ps[j] - ps[i] + 1 == max_len) id = j;
        }
        if (id == -1 && ++i) continue;
        veci6 b;
        for (int k = i; k <= id; k++) b.push_back(ps[k]);
        i = id, ans = (ans + solve(b)) % P;
    }
    std::cout << ans << std::endl;
    return 0;
}