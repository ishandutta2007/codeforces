#include <bits/stdc++.h>

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int j = 0; j < n; ++j) std::cin >> a[j];
        std::vector<int> p;
        for (int j = 0; j < n; ++j) {
            if (a[j] == 1) p.push_back(j);
        }
        int sz = p.size();
        if (sz % 2 == 1) {
            std::cout << "NO" << std::endl;
        } else {
            std::vector<int> b;
            for (int j = 0; j < sz; j += 2) {
                int d = p[j + 1] - p[j];
                if (d % 2 == 0) {
                    for (int k = p[j]; k < p[j + 1] - 2; k += 2) {
                        b.push_back(k);
                    }
                    b.push_back(p[j + 1] - 2);
                    for (int k = p[j + 1] - 4; k >= p[j]; k -= 2) {
                        b.push_back(k);
                    }
                    a[p[j]] = a[p[j + 1]] = 0;
                } else {
                    for (int k = p[j]; k <= p[j + 1] - 3; k += 2) {
                        b.push_back(k), a[k + 1] = a[k + 2] = 1;
                    }
                }
            }
            for (int j = 0; j < n - 2; ++j) {
                if (a[j] == 0 && a[j + 1] == 1 && a[j + 2] == 1) {
                    b.push_back(j);
                    a[j + 1] = a[j + 2] = 0;
                }
            }
            for (int j = n - 3; j >= 0; j--) {
                if (a[j] == 1 && a[j + 1] == 1 && a[j + 2] == 0) {
                    b.push_back(j);
                    a[j] = a[j + 1] = 0;
                }
            }
            bool ok = true;
            for (int j = 0; j < n; ++j) {
                if (a[j] == 1) ok = false;
            }
            if (!ok) {
                std::cout << "NO" << std::endl;
            } else {
                int k = b.size();
                std::cout << "YES" << std::endl;
                std::cout << k << std::endl;
                for (int j = 0; j < k; ++j) {
                    std::cout << b[j] + 1 << " \n"[j == k - 1];
                }
            }
        }
    }
}