#include <bits/stdc++.h>

using int64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n + 1);
        auto Add = [&](int i, int x) {
            while (i <= n) a[i] += x, i += i & (-i);
        };
        auto Sum = [&](int i) {
            int Ret = 0;
            while (i) Ret += a[i], i &= i - 1;
            return Ret;
        };
        std::priority_queue<int> Que;
        int64 U = 0;
        for (int i = 1, x; i <= n; ++i) {
            std::cin >> x;
            int I = Sum(x);
            U += i - I - 1;
            Que.push((i - I - 1) - I - 2 * (x - I - 1));
            Add(x, 1);
        }
        std::cout << U;
        for (int i = 1; i <= n; ++i) std::cout << ' ' << (U -= Que.top() + i - 1), Que.pop();
        std::cout << '\n';
    }
    return 0;
}