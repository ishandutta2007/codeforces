#include <cstdio>

const int mod = 1000000007;

int wsp[1000007];
int tab[1000007];
int pot[1000007];

int main() {
    int N;
    scanf("%d", &N);
    pot[0] = 1;
    for (int i = 1; i <= N; i++)
        pot[i] = (2 * pot[i - 1]) % mod;
    int a;
    for (int i = 0; i < N; i++) {
        scanf("%d", &a);
        tab[a]++;
    }
    long long wyn = 0;
    for (int i = 2; i <= 1000000; i++) {
        wsp[i] = i - wsp[i];
        for (int w = i + i; w <= 1000000; w += i)
            wsp[w] += wsp[i];
        int ile = 0;
        for (int w = i; w <= 1000000; w += i)
            ile += tab[w];
        if (ile != 0) {
            long long dod = (long long) wsp[i] * pot[ile - 1];
            dod %= mod;
            dod *= ile;
            dod %= mod;
            wyn += dod;
            wyn %= mod;
        }
    }
    printf("%lld", wyn);
    return 0;
}