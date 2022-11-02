#include <bits/stdc++.h>
const int N = 300005;
int n, ca, cb;
int a[N], b[N], sa[N], sb[N];
int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i] >> b[i];
        if (a[i] < b[i]) {
            sa[ca++] = i;
        } else {
            sb[cb++] = i;
        }
    }
    std::sort(sa, sa + ca, [](int x, int y) { return a[x] > a[y]; });
    std::sort(sb, sb + cb, [](int x, int y) { return b[x] < b[y]; });
    std::cout << std::max(ca, cb) << std::endl;
    if (ca > cb) {
        for (int i = 0; i < ca; ++i) std::cout << sa[i] << " ";
    } else {
        for (int i = 0; i < cb; ++i) std::cout << sb[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}