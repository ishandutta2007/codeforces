#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n), Num(n + 1), GNum(n + 1);
        for (int i = 0; i < n; ++i) std::cin >> a[i], ++Num[a[i]];
        int Mex = 0;
        while (Num[Mex]) ++Mex;
        std::vector<int> Ans;
        for (int i = 0, j = 0; i < n; i = j) {
            int GMex = 0;
            while (true) {
                ++GNum[a[j++]];
                while (GNum[GMex]) ++GMex;
                if (GMex == Mex) break;
            }
            Ans.push_back(Mex);
            for (int k = i; k < j; ++k) {
                --GNum[a[k]];
                if (!--Num[a[k]]) Mex = std::min(Mex, a[k]);
            }
        }
        std::cout << Ans.size() << std::endl;
        for (int u : Ans) std::cout << u << ' ';
        std::cout << std::endl;
    }
    return 0;
}