#include <iostream>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> e(n);
    std::vector<int> id(n - 1, -1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        e[u].push_back(i);
        e[v].push_back(i);
    }
    int c = 0;
    for (int i = 0; i < n; ++i) {
        if (int(e[i].size()) >= 3) {
            for (int j = 0; j < 3; ++j)
                id[e[i][j]] = j;
            c = 3;
            break;
        }
    }
    for (int i = 0; i < n - 1; ++i)
        if (id[i] == -1)
            id[i] = c++;
    for (int i = 0; i < n - 1; ++i)
        std::cout << id[i] << "\n";
    return 0;
}