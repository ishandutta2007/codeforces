#include <bits/stdc++.h>

using int64 = long long;

const int N = 10005;

char la;

int n, m, d, flag, ms;
int a[N], b[N];

int64 u, cnt0, cnt1;

std::string s, t;

int main() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937_64 rand_num(seed);
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m, d;
    while (++d, m--) {
        std::cin >> s;
        if (!flag) {
            u = rand_num() % n, flag = 1;
            std::cout << (la = s[u]) << std::endl;
        } else {
            cnt0 = cnt1 = 0;
            for (int i = 0; i < n; ++i) {
                if (s[i] == '0') {
                    cnt0 += a[i] * 2, cnt1 += b[i] * 3;
                } else {
                    cnt1 += a[i] * 2, cnt0 += b[i] * 3;
                }
            }
            std::cout << (la = cnt0 > cnt1 ? '0' : '1') << std::endl;
        }
        std::cin >> t;
        ms += t[0] != la;
        for (int i = 0; i < n; ++i) ++(s[i] == t[0] ? a : b)[i];
        if (ms > 500 && d < 900) {
            while (m--) {
                std::cin >> s;
                std::cout << rand_num() % 2 << std::endl;
                std::cin >> t;
            }
            ++m;
        }
    }
    return 0;
}