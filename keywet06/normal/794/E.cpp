#include <bits/stdc++.h>

template <typename Type>
inline bool Mad(Type &a, Type b) {
    return a < b ? a = b, 1 : 0;
}

int n;
int a[300000];

int Check(int l, int r) {
    if (l == r) return a[l];
    if ((r - l) & 1) {
        int t = (r - l) / 2;
        l += t, r -= t;
        return std::max(a[l], a[r]);
    } else {
        int t = (r - l) / 2 - 1;
        l += t, r -= t;
        return std::min(a[l + 1], std::max(a[l], a[r]));
    }
}

int ans[300000], mxx = 0, mx[2];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n;
    for (int i = 0; i < n; ++i) std::cin >> a[i], Mad(mxx, a[i]);
    for (int i = 0; i < n; ++i) {
        if (n - 1 >= i) Mad(mx[i & 1], Check(i, n - 1)), Mad(mx[i & 1], Check(0, n - 1 - i));
        ans[i] = i == n - 1 ? mxx : mx[i & 1];
        std::cout << ans[i] << " \n"[i == n - 1];
    }
    return 0;
}