#include <bits/stdc++.h>


int main() {

    int n;
    std::cin >> n;
    std::vector<int> ans(n + 1);
    std::cout << "? 2 3" << std::endl;
    int a, b, c;
    std::cin >> a;
    std::cout << "? 1 3" << std::endl;
    std::cin >> b;
    ans[1] = b - a;
    std::cout << "? 1 2" << std::endl;
    std::cin >> c;
    ans[2] = c - ans[1];
    ans[3] = a - ans[2];
    for (int i = 4, x; i <= n; i++) {
        std::cout << "? " <<  i - 1 << ' ' << i << std::endl;
        std::cin >> x;
        ans[i] = x - ans[i - 1];
    }
    std::cout << '!';
    for (int i  = 1; i <= n; i++) {
        std::cout << ' ' << ans[i];
    }
    std::cout << std::endl;
}