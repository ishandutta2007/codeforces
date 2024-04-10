#include <bits/stdc++.h>

using int64 = long long;

int64 T, n, f, l1, l2, t, a;

std::string s;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> s, n = s.size();
        f = l1 = l2 = t = a = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '?') {
                t = !t, ++l1, ++l2;
            } else {
                if (!f) {
                    t = s[i] - '0';
                    l1 = 0, ++l2, f = 1;
                } else {
                    t = !t;
                    if (s[i] - '0' == t) {
                        l1 = 0, ++l2;
                    } else {
                        l2 = l1 + 1, l1 = 0;
                        t = s[i] - '0';
                    }
                }
            }
            a += l2;
        }
        std::cout << a << std::endl;
    }
    return 0;
}