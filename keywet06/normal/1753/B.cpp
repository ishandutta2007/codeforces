#include <bits/stdc++.h>

const int N = 500005;

int n, x;
int a[N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n >> x;
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    a[++n] = x;
    std::sort(a + 1, a + n + 1);
    int now = 1, num = 0;
    for (int i = 1; i <= n; ++i) {
        while (a[i] > now) {
            if (num % (now + 1)) return std::cout << "No" << '\n', 0;
            num /= ++now;
        }
        ++num;
    }
    std::cout << "Yes" << '\n';
    return 0;
}