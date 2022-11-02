#include <bits/stdc++.h>

using int64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;
    std::cin >> n;
    std::vector<int64> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    std::vector<int> p(n);
    for (int i = 0; i < n; ++i) p[i] = __builtin_popcountll(a[i]);
    int64 ans = 0;
    std::vector<int> sm, sM, vm, vM;
    for (int c = 0; c <= 60; ++c) {
        sm = {-1}, sM = {-1}, vm = {0}, vM = {0};
        auto getPre = [&](const auto &s, const auto &v, int x) {
            if (x == 0) return 0;
            int j = std::lower_bound(s.begin(), s.end(), x - 1) - s.begin();
            return v[j - 1] + (x - 1 - s[j - 1]) * (p[s[j]] == c);
        };
        auto get = [&](const auto &s, const auto &v, int l, int r) {
            return getPre(s, v, r) - getPre(s, v, l);
        };
        int res = 0;
        for (int i = 0; i < n; ++i) {
            while (sm.size() > 1 && a[i] < a[sm.back()]) {
                int x = sm.back();
                sm.pop_back(), vm.pop_back();
                if (p[x] == c) res -= get(sM, vM, sm.back() + 1, x + 1);
            }
            if (p[i] == c) res += get(sM, vM, sm.back() + 1, i);
            vm.push_back(vm.back() + (i - sm.back()) * (p[i] == c));
            sm.push_back(i);
            while (sM.size() > 1 && a[i] > a[sM.back()]) {
                int x = sM.back();
                sM.pop_back(), vM.pop_back();
                if (p[x] == c) res -= get(sm, vm, sM.back() + 1, x + 1);
            }
            if (p[i] == c) res += get(sm, vm, sM.back() + 1, i + 1);
            vM.push_back(vM.back() + (i - sM.back()) * (p[i] == c));
            sM.push_back(i), ans += res;
        }
    }
    std::cout << ans << "\n";
    return 0;
}