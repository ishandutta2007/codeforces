#include <bits/stdc++.h>

int tab[1000007];

int main() {
    int Z;
    scanf("%d", &Z);
    while (Z--) {
        int N, M, K;
        scanf("%d%d%d", &N, &M, &K);
        K = std::min(K, M - 1);
        for (int i = 1; i <= N; i++)
            scanf("%d", &tab[i]);
        int zostanie = N - M + 1;
        for (int i = 1; i <= N; i++)
            if (i + zostanie - 1 <= N)
                tab[i] = std::max(tab[i], tab[i + zostanie - 1]);
        int maxi = 0;
        for (int pref = 0; pref <= K; pref++) {
            int NN = N - (K - pref);
            int terMin = 1337133713;
            for (int i = pref + 1; i <= N; i++)
                if (i + zostanie - 1 <= NN)
                    terMin = std::min(terMin, tab[i]);
            maxi = std::max(maxi, terMin);
        }
        printf("%d\n", maxi);
    }
    return 0;
}