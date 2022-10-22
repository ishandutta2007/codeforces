#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int index = 0; index < t; index++) {
        int n, m;
        std::cin >> n >> m;
        std::vector<int> edjes1(m);
        std::vector<int> edjes2(m);
        std::vector<int> edges(n);
        int count = 0;
        std::vector<bool> covered(3 * n, false);
        for (int i = 0; i < m; i++) {
            std::cin >> edjes1[i] >> edjes2[i];
        }
        for (int i = 0; i < m; i++) {
            int a = edjes1[i] - 1, b = edjes2[i] - 1;
            if (!covered[a] && !covered[b]) {
                    edges[count] = i;
                    count++;
                    covered[a] = covered[b] = true;
                    if (count == n)
                        break;
            }
        }
        
        if (count == n) {
            std::cout << "Matching\n";
            for (auto edge : edges)
                std::cout << edge + 1 << " ";
            std::cout << "\n";
        } else {
            int num = 0;
            std::cout << "IndSet\n";
            for (int i = 0; i < 3 * n; i++)
                if (!covered[i] && num < n) {
                    num++;
                    std::cout << i + 1 << " ";
                    if (num == n)
                        break;
                }
            std::cout << "\n";
        }
    }
    return 0;
}