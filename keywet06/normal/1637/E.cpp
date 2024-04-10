#include <bits/stdc++.h>

using int64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n, m;
        std::cin >> n >> m;
        std::map<int, int> Map;
        for (int i = 0, x; i < n; ++i) std::cin >> x, ++Map[x];
        std::set<int> Set;
        for (auto [x, Num] : Map) Set.insert(Num);
        std::vector<int> Col(n + 1), Um(n);
        int CntC = 0;
        for (int x : Set) Um[Col[x] = CntC++] = x;
        std::vector<std::vector<int> > Ber(CntC);
        for (auto [x, Num] : Map) Ber[Col[Num]].push_back(x);
        for (int i = 0; i < CntC; ++i) std::sort(Ber[i].begin(), Ber[i].end(), std::greater<int>());
        std::map<int, std::vector<int> > Mav;
        for (int i = 0, x, y; i < m; ++i) {
            std::cin >> x >> y;
            Mav[x].push_back(y), Mav[y].push_back(x);
        }
        for (auto [x, Num] : Map) Mav[x].push_back(x);
        int64 Ans = 0;
        for (int i = 0; i < CntC; ++i) {
            for (int x : Ber[i]) {
                std::vector<int> Id(CntC);
                std::sort(Mav[x].begin(), Mav[x].end(), std::greater<int>());
                for (int u : Mav[x]) {
                    int c = Col[Map[u]];
                    Id[c] += Ber[c][Id[c]] == u;
                }
                for (int j = 0; j < CntC; ++j) {
                    if (Id[j] != Ber[j].size()) Ans = std::max(Ans, int64(Um[i] + Um[j]) * (x + Ber[j][Id[j]]));
                }
            }
        }
        std::cout << Ans << '\n';
    }
    return 0;
}