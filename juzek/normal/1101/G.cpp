#include <cstdio>
#include <algorithm>
#include <set>

int tab[1000007];
bool odw[1000007];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &tab[i]);
        tab[i] ^= tab[i - 1];
    }
    if (tab[N] == 0) {
        printf("-1");
        return 0;
    }
    for (int bit = 1 << 30; bit >= 1; bit >>= 1) {
        int pos = -1;
        for (int i = 1; i <= N; i++) {
            if (!odw[i] && (tab[i] & bit)) {
                pos = i;
                break;
            }
        }
        if (pos == -1)
            continue;
        odw[pos] = true;
        for (int i = 1; i <= N; i++)
            if (i != pos && (tab[i] & bit))
                tab[i] ^= tab[pos];
    }
    int zera = 0;
    for (int i = 1; i <= N; i++)
        if (tab[i] == 0)
            zera++;
    printf("%d", N - zera);
    return 0;
}