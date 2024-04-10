#include <cstdio>
#include <algorithm>

int tab[407];
int L[250007], R[250007], C[250007], K[250007];
int poz[250007];

bool sprawdz(int l, int r, long long c, int k, long long war) {
    long long ter = war;
    int zostalo = k;
    for (int i = l + 1; i <= r; i++) {
        if (tab[i] * c > ter) {
            ter = war;
            zostalo--;
        }
        if (zostalo < 0 || tab[i] * c > ter)
            return false;
        ter -= tab[i] * c;
    }
    return true;
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
        scanf("%d", &tab[i]);
    for (int i = N; i >= 1; i--)
        tab[i] -= tab[i - 1];
    long long maxi = 0;
    for (int i = 1; i <= M; i++) {
        scanf("%d%d%d%d", &L[i], &R[i], &C[i], &K[i]);
        poz[i] = i;
    }
    std::random_shuffle(poz + 1, poz + M + 1);
    for (int i = 1; i <= M; i++) {
        long long pocz = maxi, kon = 1000000000000000001;
        int x = poz[i];
        if (sprawdz(L[x], R[x], C[x], K[x], maxi))
            continue;
        while (pocz != kon - 1) {
            long long sr = (pocz + kon) / 2;
            bool ok = sprawdz(L[x], R[x], C[x], K[x], sr);
            if (ok)
                kon = sr;
            else
                pocz = sr;
        }
        maxi = std::max(maxi, kon);
    }
    printf("%lld", maxi);
    return 0;
}