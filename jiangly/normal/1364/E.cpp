#include <bits/stdc++.h>
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
int query(int i, int j) {
    std::cout << "? " << i + 1 << " " << j + 1 << std::endl;
    int res;
    std::cin >> res;
    return res;
}
int main() {
    int n;
    std::cin >> n;
    int u = -1;
    std::vector<int> p(n, -1), v(n, -1);
    while (true) {
        int a = rnd() % n, b = (rnd() % (n - 1) + a + 1) % n;
        int r = query(a, b);
        if (__builtin_popcount(r) <= 6) {
            u = a;
            v[b] = r;
            break;
        }
    }
    p[u] = 2047;
    for (int i = 0; i < n; ++i) {
        if (i != u) {
            if (v[i] == -1)
                v[i] = query(u, i);
            p[u] &= v[i];
        }
    }
    std::vector<int> sub;
    for (int i = 0; i < n; ++i)
        if (i != u && v[i] == p[u])
            sub.push_back(i);
    while (sub.size() >= 2) {
        v.assign(n, -1);
        int nu = sub[rnd() % sub.size()];
        p[nu] = p[u];
        for (auto i : sub) {
            if (nu != i) {
                v[i] = query(i, nu);
                p[nu] &= v[i];
            }
        }
        std::vector<int> nsub;
        for (auto i : sub)
            if (i != nu && v[i] == p[nu])
                nsub.push_back(i);
        u = nu;
        sub = nsub;
    }
    int pos0 = sub.empty() ? u : sub[0];
    p[pos0] = 0;
    for (int i = 0; i < n; ++i)
        if (p[i] == -1)
            p[i] = query(pos0, i);
    std::cout << "!";
    for (int i = 0; i < n; ++i)
        std::cout << " " << p[i];
    std::cout << std::endl;
    return 0;
}