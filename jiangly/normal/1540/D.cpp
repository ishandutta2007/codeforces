#include <bits/stdc++.h>
constexpr int B = 1000;
struct Fenwick {
    const int n;
    std::vector<int> a;
    Fenwick(int n) : n(n), a(n) {}
    void add(int x, int v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    int sum(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    int find(int k) {
        int x = 0;
        for (int i = 1 << std::__lg(n); i > 0; i /= 2) {
            if (x + i <= n && a[x + i - 1] <= k) {
                x += i;
                k -= a[x - 1];
            }
        }
        return x;
    }
};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    int q;
    std::cin >> q;
    std::vector<int> op(q), pos(q), x(q);
    for (int i = 0; i < q; i++) {
        std::cin >> op[i] >> pos[i];
        pos[i]--;
        if (op[i] == 1) {
            std::cin >> x[i];
        }
    }
    Fenwick fen(n);
    for (int i = 0; i < n; i++) {
        fen.add(i, 1);
    }
    for (int t = 0; t < q; t += B) {
        int L = t, R = std::min(q, t + B);
        std::vector<int> p;
        for (int i = L; i < R; i++) {
            p.push_back(pos[i]);
        }
        p.push_back(-1);
        p.push_back(n);
        std::sort(p.begin(), p.end());
        p.erase(std::unique(p.begin(), p.end()), p.end());
        std::vector<int> a(n);
        for (int i = int(p.size()) - 2; i >= 0; i--) {
            for (int j = p[i] + 1; j < p[i + 1]; j++) {
                a[j] = fen.find(b[j]);
                fen.add(a[j], 1);
            }
            for (int j = p[i] + 1; j < p[i + 1]; j++) {
                fen.add(a[j], -1);
            }
            std::sort(a.begin() + p[i] + 1, a.begin() + p[i + 1]);
        }
        for (int i = L; i < R; i++) {
            if (op[i] == 1) {
                b[pos[i]] = x[i];
            } else {
                int x = pos[i];
                int v = b[pos[i]];
                for (int j = 0; j < int(p.size()) - 1; j++) {
                    if (p[j + 1] <= x) {
                        continue;
                    }
                    v += std::upper_bound(a.begin() + p[j] + 1, a.begin() + p[j + 1], v) - (a.begin() + p[j] + 1);
                    if (p[j + 1] != n) {
                        if (b[p[j + 1]] <= v) {
                            v++;
                        }
                    }
                }
                std::cout << n - v << "\n";
            }
        }
    }
    return 0;
}