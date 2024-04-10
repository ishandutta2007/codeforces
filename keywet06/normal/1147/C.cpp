#include <bits/stdc++.h>
const int N = 55;
int n;
int a[N];
int main() {
    std::cin >> n;
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    std::sort(a, a + n);
    std::cout << (a[0] == a[n / 2] ? "Bob" : "Alice") << std::endl;
    return 0;
}