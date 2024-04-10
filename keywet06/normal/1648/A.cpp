#include <bits/stdc++.h>

using int64 = long long;
using int128 = __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    const int N = 1e5 + 1;
    std::vector<int64> Num(N), Sum(N);
    int128 Ans = 0;
    std::vector<std::vector<int> > a(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0, x; j < m; ++j) {
            std::cin >> x, a[i][j] = x;
            Ans += Num[x] * i - Sum[x];
            ++Num[x], Sum[x] += i;
        }
    }
    Num.assign(Num.size(), 0);
    Sum.assign(Sum.size(), 0);
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            int x = a[i][j];
            Ans += Num[x] * j - Sum[x];
            ++Num[x], Sum[x] += j;
        }
    }
    std::string s = Ans == 0 ? "0" : "";
    while (Ans) s = char(Ans % 10 + '0') + s, Ans /= 10;
    std::cout << s << std::endl;
    return 0;
}