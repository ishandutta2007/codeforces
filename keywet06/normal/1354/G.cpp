#include <bits/stdc++.h>

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

std::string query(const std::vector<int> &a, const std::vector<int> &b) {
    std::cout << "? " << a.size() << " " << b.size() << std::endl;
    for (int i = 0; i < a.size(); ++i) {
        std::cout << a[i] + 1 << " \n"[i == a.size() - 1];
    }
    for (int i = 0; i < b.size(); ++i) {
        std::cout << b[i] + 1 << " \n"[i == b.size() - 1];
    }
    std::string res;
    std::cin >> res;
    return res;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        std::vector<int> p(n);
        std::iota(p.begin(), p.end(), 0);
        std::random_shuffle(p.begin(), p.end(),
                            [&](int n) { return rnd() % n; });
        const int m = std::min(n, 30);
        int x = p[0];
        for (int i = 1; i < m; ++i) {
            if (query({x}, {p[i]}) == "SECOND") x = p[i];
        }
        std::vector<int> stones{x};
        std::iota(p.begin(), p.end(), 0);
        p.erase(p.begin() + x);
        p.insert(p.begin(), x);
        while (true) {
            int c = stones.size();
            if (2 * c >= n) break;
            std::vector<int> r(p.begin() + c, p.begin() + 2 * c);
            if (query(stones, r) == "FIRST") break;
            stones.insert(stones.end(), r.begin(), r.end());
        }
        int c = stones.size();
        for (int i = c / 2; i > 0; i /= 2) {
            std::vector<int> s(stones.begin(), stones.begin() + i),
                r(p.begin() + c, p.begin() + c + i);
            if (c + i < n && query(s, r) == "EQUAL") c += i;
        }
        std::cout << "! " << p[c] + 1 << std::endl;
    }
    return 0;
}