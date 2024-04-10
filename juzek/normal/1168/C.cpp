#include <cstdio>
#include <bitset>
#include <algorithm>
#include <cstring>

int naj[300007][20];
int tab[300007];
int las[20];

int main() {
    int N, Q;
    scanf("%d%d", &N, &Q);
    for (int i = 1; i <= N; i++)
        scanf("%d", &tab[i]);
    memset(naj, 127, sizeof(naj));
    for (int i = N; i >= 1; i--) {
        std::bitset<20> b = tab[i];
        for (int w = 0; w < 20; w++) {
            if (b[w]) {
                if (las[w] != 0) {
                    naj[i][w] = las[w];
                    for (int q = 0; q < 20; q++)
                        naj[i][q] = std::min(naj[i][q], naj[las[w]][q]);
                }
                las[w] = i;
            }
        }
    }
//    printf("\n");
//    for (int i = 1; i <= N; i++) {
//        for (int w = 0; w < 2; w++) {
//            if (naj[i][w] > N)
//                printf("-1 ");
//            else
//                printf("%2d ", naj[i][w]);
//        }
//        printf("\n");
//    }
    while (Q--) {
        int a, b;
        scanf("%d%d", &a, &b);
        std::bitset<20> bit = tab[b];
        bool kk = false;
        for (int w = 0; w < 20; w++)
            if (bit[w] && naj[a][w] <= b)
                kk = true;
        printf(kk ? "Shi\n" : "Fou\n");
    }
    return 0;
}