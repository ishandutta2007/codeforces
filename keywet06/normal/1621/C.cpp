#include <bits/stdc++.h>

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        std::vector<int> Ans(n, -1);
        int C = 0;
        auto Query = [&](int i) {
            std::cout << "? " << i + 1 << std::endl, ++C;
            int x;
            std::cin >> x;
            return x - 1;
        };
        for (int i = 0; i < n; ++i) {
            if (Ans[i] >= 0) continue;
            int U = C;
            std::vector<int> r(1, Query(i));
            r.push_back(Query(i));
            while (r.back() != r.front()) r.push_back(Query(i));
            r.pop_back();
            int B = r.size();
            U %= B;
            std::vector<int> a;
            for (int j = B - U; j < B; ++j) a.push_back(r[j]);
            for (int j = 0; j < B - U; ++j) a.push_back(r[j]);
            for (int j = 0; j + 1 < B; ++j) Ans[r[j]] = r[j + 1];
            Ans[r.back()] = r.front();
        }
        std::cout << "! ";
        for (int x : Ans) std::cout << x + 1 << ' ';
        std::cout << '\n';
    }
    return 0;
}