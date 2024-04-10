#include <bits/stdc++.h>

int n, i;

int main() {
    scanf("%d", &n);
    std::vector<std::pair<int, int>> ve = {{0, 0}, {0, 2}};
    int x = 1;
    for (i = 2; ve.size() < n; i += 3, x += 2) {
        ve.push_back({x + 1, 0});
        ve.push_back({x, 1});
        ve.push_back({x + 1, 2});
    }
    ve.resize(n);
    for (auto u : ve) printf("%d %d\n", u.first, u.second);
    return 0;
}