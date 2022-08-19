#include <bits/stdc++.h>
constexpr int A[] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::cout << A[n / 10] * A[n % 10] << "\n";
    return 0;
}