#include <cstdio>
#include <algorithm>

int tab[1000007];

int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    int sumA = 0, sumB = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &tab[i]);
        if (tab[i] == -1)
            sumA++;
        else
            sumB++;
    }
    int maxi = 0;
    for (int i = 1; i <= K; i++) {
        int terA = 0, terB = 0;
        for (int w = i; w <= N; w += K) {
            if (tab[w] == -1)
                terA++;
            else
                terB++;
        }
        int sum = (sumA - terA) - (sumB - terB);
        maxi = std::max(maxi, std::max(-sum, sum));
    }
    printf("%d", maxi);
    return 0;
}