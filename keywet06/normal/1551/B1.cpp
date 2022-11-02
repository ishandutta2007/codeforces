#include <bits/stdc++.h>

#define mkp std::make_pair
#define fir first
#define sec second

using pair = std::pair<int, int>;

const int N = 200005;

int T, n, x, y, z, k, head;
int p[N], ans[N];

std::string a;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> a, n = a.size(), a = ' ' + a, k = 2;
        for (int i = 1; i <= n; ++i) p[i] = i, ans[i] = 0;
        std::sort(p + 1, p + n + 1, [](int x, int y) { return a[x] < a[y]; });
        x = 1, y = 0;
        for (int i = 2; i <= n; ++i) {
            if (a[p[i]] == a[p[i - 1]]) {
                ++x;
            } else {
                y += std::min(x, k), x = 1;
            }
        }
        y += std::min(x, k), x = 0, z = y / k;
        std::cout << z << '\n';
    }
    return 0;
}