#include <bits/stdc++.h>

using int64 = long long;

int n;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n;
    std::vector<int> p(n), Pos(n);
    for (int i = 0; i < n; ++i) std::cin >> p[i], Pos[--p[i]] = i;
    auto get = [&](auto p) {
        std::deque<int> dec, inc;
        std::vector<std::array<int, 3>> l(n);
        for (int i = 0, j = 0; i < n; ++i) {
            if (i > 0) {
                do {
                    if (p[i] < p[i - 1]) {
                        if (inc.empty() || p[i] > inc.back()) {
                            dec.push_back(p[i - 1]);
                            break;
                        }
                    } else {
                        if (dec.empty() || p[i] < dec.back()) {
                            inc.push_back(p[i - 1]);
                            break;
                        }
                    }
                    if (!dec.empty() && dec[0] == p[j]) {
                        dec.pop_front();
                    } else {
                        inc.pop_front();
                    }
                    ++j;
                } while (true);
            }
            l[i] = {p[j], dec.empty() ? n : dec.back(), inc.empty() ? -1 : inc.back()};
        }
        return l;
    };
    auto l = get(p);
    std::reverse(p.begin(), p.end());
    auto r = get(p);
    std::reverse(p.begin(), p.end());
    std::reverse(r.begin(), r.end());
    std::vector<int> f(n);
    std::iota(f.begin(), f.end(), 0);
    for (int i = 0; i < n - 1; ++i) {
        int x = Pos[l[i][0]];
        int y = Pos[r[i + 1][0]];
        if (p[i] < p[i + 1]) {
            if (l[i][1] > r[i + 1][2]) {
                f[x] = std::max(f[x], y);
            } else {
                int u = Pos[l[i][1]], v = Pos[r[i + 1][2]];
                f[u + 1] = std::max(f[u + 1], y);
                f[x] = std::max(f[x], v - 1);
            }
        } else {
            if (l[i][2] < r[i + 1][1]) {
                f[x] = std::max(f[x], y);
            } else {
                int u = Pos[l[i][2]], v = Pos[r[i + 1][1]];
                f[u + 1] = std::max(f[u + 1], y);
                f[x] = std::max(f[x], v - 1);
            }
        }
    }
    for (int i = 1; i < n; ++i) f[i] = std::max(f[i], f[i - 1]);
    int64 Ans = 0;
    for (int i = 0; i < n; ++i) Ans += f[i] - i + 1;
    std::cout << Ans << "\n";
    return 0;
}