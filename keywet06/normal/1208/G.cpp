#include <bits/stdc++.h>

using int64 = long long;

class Solver {
   private:
    static const int N = 1e6 + 5;

    bool Vis[N];

    int n, k;
    int Phi[N];

    std::vector<int> Pri;

   public:
    void solve() {
        memset(Vis, true, sizeof(Vis));
        int64 ans = 0;
        std::cin >> n >> k;
        Phi[1] = 1;
        for (int i = 2; i <= n; ++i) {
            if (Vis[i]) Pri.push_back(i), Phi[i] = i - 1;
            for (int p : Pri) {
                if (p * i > n) break;
                Vis[i * p] = false;
                if (i % p == 0) {
                    Phi[p * i] = Phi[i] * p;
                    break;
                } else {
                    Phi[p * i] = Phi[i] * (p - 1);
                }
            }
        }
        std::sort(Phi + 1, Phi + n + 1);
        for (int i = 1; i <= k + 2; ++i) ans += Phi[i];
        std::cout << ans - (k == 1) << std::endl;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    Solver().solve();
    return 0;
}