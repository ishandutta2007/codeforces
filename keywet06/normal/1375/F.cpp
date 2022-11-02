#include <bits/stdc++.h>

using int64 = long long;

const int N = 3;

int64 x, t, g, h;
int64 a[N], b[N], c[N];

int main() {
    std::cin >> a[0] >> a[1] >> a[2];
    b[0] = b[1] = b[2] = 1;
    if (a[0] < a[1] && a[0] < a[2]) b[0] = 0;
    if (a[1] < a[0] && a[1] < a[2]) b[1] = 0;
    if (a[2] < a[0] && a[2] < a[1]) b[2] = 0;
    if (a[0] > a[1] && a[0] > a[2]) b[0] = 2;
    if (a[1] > a[0] && a[1] > a[2]) b[1] = 2;
    if (a[2] > a[0] && a[2] > a[1]) b[2] = 2;
    c[b[0]] = 0, c[b[1]] = 1, c[b[2]] = 2;
    std::cout << "First" << std::endl;
    g = a[c[1]] - a[c[0]], h = a[c[2]] - a[c[1]];
    std::cout << g + 2 * h << std::endl;
    std::cin >> x, --x;
    if (b[x] == 0) return std::cout << h << std::endl, 0;
    if (b[x] == 1) return std::cout << g + h << std::endl, 0;
    std::cout << 3 * g + 6 * h << std::endl;
    std::cin >> x, --x;
    std::cout << (b[x] + 1) * g + 3 * h << std::endl;
    return 0;
}