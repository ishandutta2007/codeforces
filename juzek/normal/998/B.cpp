#include <cstdio>
#include <algorithm>

int dp[107][107];
int tab[107];
int ilP[107];
int ilNP[107];

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &tab[i]);
        ilP[i] = ilP[i - 1];
        ilNP[i] = ilNP[i - 1];
        if (tab[i] % 2 == 0) {
            ilP[i]++;
        } else {
            ilNP[i]++;
        }
    }
    for (int i = 1; i <= M; i++)
        dp[0][i] = -1337133713;
    for (int i = 1; i < N; i++) {
        for (int w = 0; w <= M; w++) {
            dp[i][w] = -1337133713;
        }
        for (int w = 1; w < i; w++) {
            if (ilP[i] - ilP[w - 1] == ilNP[i] - ilNP[w - 1]) {
                int cost = std::max(tab[i + 1] - tab[i], tab[i] - tab[i + 1]);
                for (int z = cost; z <= M; z++) {
                    dp[i][z] = std::max(dp[i][z], dp[w - 1][z - cost] + 1);
                }
            }
        }
    }
    int maxi = 0;
//    for (int w = 0; w <= M; w++) {
//        for (int i = 0; i < N; i++) {
//            if (dp[i][w] < 0)
//                printf(" X ");
//            else
//                printf("%2d ", dp[i][w]);
//        }
//        printf("\n");
//    }
    for (int i = 0; i < N; i++) {
        for (int w = 0; w <= M; w++) {
            maxi = std::max(maxi, dp[i][w]);
        }
    }
    printf("%d", maxi);
    return 0;
}