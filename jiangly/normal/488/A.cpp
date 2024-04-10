#include <bits/stdc++.h>
using i64 = long long;
bool check(int a) {
    auto s = std::to_string(a);
    return s.find('8') != -1;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int a;
    std::cin >> a;
    int b = 1;
    a++;
    while (!check(a)) {
        a++;
        b++;
    }
    std::cout << b << "\n";
    return 0;
}