#include <bits/stdc++.h>
int main() {
    std::vector<int64_t> a(3);
    for (int i = 0; i < 3; ++i)
        std::cin >> a[i];
    std::cout << "First" << std::endl;
    int lst = -1;
    while (true) {
        auto v = a;
        std::sort(v.begin(), v.end());
        if (lst != -1 && (a[lst] == v[0] || a[lst] == v[2]) && v[2] - v[1] == v[1] - v[0]) {
            int64_t x = v[2] - v[1];
            for (auto y : {x, 3 * x, x, x, 2 * x}) {
                std::cout << y << std::endl;
                int p;
                std::cin >> p;
                if (p <= 0)
                    return 0;
                a[--p] += y;
            }
            assert(false);
        }
        int64_t y;
        if (v[2] - v[1] < v[1] - v[0]) {
            y = (v[1] - v[0]) - (v[2] - v[1]);
        } else {
            y = v[1] - v[0];
        }
        std::cout << y << std::endl;
        int p;
        std::cin >> p;
        if (p <= 0)
            return 0;
        a[--p] += y;
        lst = p;
    }
    return 0;
}