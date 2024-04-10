#include <cstdio>
#include <algorithm>
#include <climits>

int war[5007];
int tab[5007];
long long _dp[2][5007];

long long *dpTer = _dp[0], *dpLast = _dp[1];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &tab[i]);
        war[i] = tab[i];
    }
    std::sort(war + 1, war + N + 1);
    for (int w = 1; w <= N; w++)
        dpLast[w] = std::min((long long) std::abs(tab[1] - war[w]), w == 1 ? LLONG_MAX : dpLast[w - 1]);
    for (int i = 2; i <= N; i++) {
        for (int w = 1; w <= N; w++) {
            dpTer[w] = std::abs(tab[i] - war[w]) + dpLast[w];
            if (w != 1)
                dpTer[w] = std::min(dpTer[w], dpTer[w - 1]);
        }
        std::swap(dpLast, dpTer);
    }
    printf("%lld", dpLast[N]);
    return 0;
}