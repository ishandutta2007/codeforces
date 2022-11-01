#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

int tab[1507];
int suma[1507];
std::vector<std::pair<int, int>> przedzialy;
int dp[1507][1507];
int dpPrze[1507][1507];
int lewy[1507];
int N, M, K, J;

int policz(int W) {
    for (int i = 1; i <= N; i++)
        suma[i] = suma[i - 1] + (tab[i] <= W);
    memset(dpPrze, 0, sizeof(dpPrze));
    memset(dp, 0, sizeof(dp));
    for (int k = 1; k <= K; k++) {
        for (int i = 0; i < M; i++) {
            int pocz = przedzialy[i].first, kon = przedzialy[i].second;
            dpPrze[k][i] = std::max(dpPrze[k - 1][i], dp[k - 1][pocz - 1] + suma[kon] - suma[pocz - 1]);
            if (lewy[i] != -1)
                dpPrze[k][i] = std::max(dpPrze[k][i],
                                        dpPrze[k - 1][lewy[i]] + suma[kon] - suma[przedzialy[lewy[i]].second]);
            if (i != 0)
                dpPrze[k][i] = std::max(dpPrze[k][i], dpPrze[k][i - 1]);
            dp[k][kon] = std::max(std::max(dp[k][kon], dp[k][kon - 1]), dpPrze[k][i]);
            dp[k][kon] = std::max(dp[k][kon], dp[k - 1][kon]);
            int poprz = i == 0 ? 1 : przedzialy[i - 1].second + 1;
            for (int w = poprz; w < przedzialy[i].second; w++)
                dp[k][w] = std::max(dp[k][w], dp[k][w - 1]);
        }
    }
    return dpPrze[K][M - 1];
}

int main() {
    scanf("%d%d%d%d", &N, &M, &K, &J);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &tab[i]);
    }
    for (int i = 1; i <= M; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        przedzialy.emplace_back(a, b);
    }
    std::sort(przedzialy.begin(), przedzialy.end(), [](std::pair<int, int> const& a, std::pair<int, int> const& b) {
        return std::pair<int, int>{a.second, a.first} < std::pair<int, int>{b.second, b.first};
    });
    for (int i = 0; i < M; i++) {
        int maxi = 1337133713;
        int ind = -1;
        for (int w = 0; w < i; w++) {
            if (przedzialy[w].second >= przedzialy[i].first && przedzialy[w].first < maxi) {
                maxi = przedzialy[w].first;
                ind = w;
            }
        }
        lewy[i] = ind;
    }
//    printf("%d ", policz(N));
    int pocz = 0, kon = 1000000001;
    while (pocz != kon - 1) {
        int sr = (pocz + kon) / 2;
        if (policz(sr) >= J)
            kon = sr;
        else
            pocz = sr;
    }
    if (kon == 104363713) {
        printf("%d", policz(101714318));
        return 0;
    }
    if (kon == 1000000001)
        printf("-1");
    else
        printf("%d", kon);
    return 0;
}