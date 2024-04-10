#include <bits/stdc++.h>

#define templ template <typename Type1, typename Type2>
templ inline Type1 &Mid(Type1 &x, Type2 y) { return x < y ? x : x = y; }
templ inline Type1 &Mad(Type1 &x, Type2 y) { return x > y ? x : x = y; }
#undef templ
#define templ template <typename Type1, typename Type2, typename... Args>
templ inline Type1 &Mid(Type1 &x, Type2 y, Args... args) { return Mid(Mid(x, y), args...); }
templ inline Type1 &Mad(Type1 &x, Type2 y, Args... args) { return Mad(Mad(x, y), args...); }
#undef templ

int Main() {
    int n, k;
    std::cin >> n >> k, --k;
    std::vector<std::vector<int> > f(n + 1, std::vector<int>(n + 1)), a(f);
    for (int i = 1; i <= n; ++i) {
        std::string s;
        std::cin >> s;
        for (int j = 1; j <= n; ++j) Mad(f[i][j] = s[j - 1] == '0' ? f[i - 1][j - 1] + 1 : 0, f[i - 1][j], f[i][j - 1]);
    }
    if (f[n][n] > k) return std::cout << "No\n", 0;
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= k - i + 1; ++j) a[i][n - j + 1] = a[n - i + 1][j] = 1;
    }
    for (int i = 1; i <= k; ++i) {
        int x = i, y = n - k + i, tx = n - k + i, ty = i;
        while (x != tx || y != ty) a[x][y] = 1, (a[x][y - 1] || f[x][y - 1] < i) && x != tx ? ++x : --y;
    }
    std::cout << "Yes\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) std::cout << a[i][j];
        std::cout << '\n';
    }
    return 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) Main();
    return 0;
}