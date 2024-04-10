#include <bits/stdc++.h>

int n;
std::string s;

void Solve() {
    std::cin >> n >> s;
    std::vector<int> a(n << 1 | 1);
    for (int i = 0; i < 2 * n; ++i) a[i + 1] = a[i] + (s[i] == '(' ? 1 : -1);
    if (*std::min_element(a.begin(), a.end()) == 0) return void(std::cout << "0\n");
    int L = 0, R = 2 * n;
    while (a[L] >= 0) ++L;
    while (a[R] >= 0) --R;
    std::vector<int> lc(n << 1 | 1, -1), rc(n << 1 | 1, -1), Sta;
    for (int i = 0; i <= 2 * n; ++i) {
        while (!Sta.empty() && a[i] > a[Sta.back()]) {
            int x = Sta.back();
            rc[x] = lc[i], lc[i] = x, Sta.pop_back();
        }
        Sta.push_back(i);
    }
    while (Sta.size() > 1) {
        int x = Sta.back();
        Sta.pop_back(), rc[Sta.back()] = x;
    }
    int ansL = -1, ansR = -1;
    std::function<std::array<int, 2>(int, int, int)> Sol = [&](int x, int l, int r) -> std::array<int, 2> {
        if (x == -1) return {-1, -1};
        auto [l1, r1] = Sol(lc[x], l, x - 1);
        auto [l2, r2] = Sol(rc[x], x + 1, r);
        int xl = -1, xr = -1;
        for (auto l : {l1, l2, x}) {
            if (l != -1 && l < L && (xl == -1 || a[l] > a[xl])) xl = l;
        }
        for (auto r : {r1, r2, x}) {
            if (r != -1 && r > R && (xr == -1 || a[r] > a[xr])) xr = r;
        }
        if (xl != -1 && xr != -1 && a[xl] + a[xr] >= a[x]) ansL = xl, ansR = xr;
        return {xl, xr};
    };
    Sol(Sta[0], 0, n);
    if (ansL != -1) return void((std::cout << "1\n", std::cout << ansL + 1 << " " << ansR << "\n"));
    int j = std::max_element(a.begin(), a.end()) - a.begin();
    std::cout << "2\n";
    std::cout << "1 " << j << "\n";
    std::cout << j + 1 << " " << 2 * n << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) Solve();
    return 0;
}