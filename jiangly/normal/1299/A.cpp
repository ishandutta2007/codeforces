#include <iostream>
#include <vector>
int n, ans, pos;
std::vector<int> a, pre, suf;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    a.resize(n);
    pre.resize(n + 1);
    suf.resize(n + 1);
    pre[0] = suf[n] = std::numeric_limits<int>::max();
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    for (int i = 0; i < n; ++i)
        pre[i + 1] = pre[i] & ~a[i];
    for (int i = n - 1; i >= 0; --i)
        suf[i] = suf[i + 1] & ~a[i];
    ans = -1;
    for (int i = 0; i < n; ++i) {
        if ((a[i] & pre[i] & suf[i + 1]) > ans) {
            ans = a[i] & pre[i] & suf[i + 1];
            pos = i;
        }
    }
    std::swap(a[0], a[pos]);
    for (int i : a)
        std::cout << i << " ";
    std::cout << "\n";
    return 0;
}