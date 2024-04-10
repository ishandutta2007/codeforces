#include <bits/stdc++.h>
int main() {
    int n;
    std::cin >> n;
    std::vector<int> p(n), vis(n);
    int j = 0;
    for (int i = 1; i < n; ++i) {
        std::cout << "? " << i + 1 << " " << j + 1 << std::endl;
        int x;
        std::cin >> x;
        std::cout << "? " << j + 1 << " " << i + 1 << std::endl;
        int y;
        std::cin >> y;
        if (x < y) {
            p[j] = y;
            vis[y - 1] = 1;
            j = i;
        } else {
            p[i] = x;
            vis[x - 1] = 1;
        }
    }
    p[j] = 1;
    while (vis[p[j] - 1])
        ++p[j];
    std::cout << "!";
    for (int i = 0; i < n; ++i)
        std::cout << " " << p[i];
    std::cout << std::endl;
    return 0;
}