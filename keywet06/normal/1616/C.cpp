#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        std::vector<int> A(n);
        for (int i = 0; i < n; ++i) std::cin >> A[i];
        int Ans = n > 1 ? n : 0;
        for (int a = 0; a < n; ++a) {
            for (int b = a + 1; b < n; ++b) {
                int Sum = 0, x = A[a], y = A[b];
                for (int u = 0; u < n; ++u) {
                    Sum += x * (u - b) + y * (a - u) != A[u] * (a - b);
                }
                Ans = std::min(Ans, Sum);
            }
        }
        std::cout << Ans << std::endl;
    }
    return 0;
}