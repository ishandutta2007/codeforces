#include <cstdio>

int tab[200007];
long long silnie[200007];
const int mod = 1000000007;

long long binpow(long long a, int n) {
    long long ret = 1;
    while (n) {
        if (n % 2 == 1) {
            ret *= a;
            ret %= mod;
        }
        a *= a;
        a %= mod;
        n /= 2;
    }
    return ret;
}

long long dwumian(int n, int k) {
    return (((silnie[n] * binpow(silnie[k], mod - 2)) % mod) * binpow(silnie[n - k], mod - 2)) % mod;
}

int policz(int n) {
    int ter = tab[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (ter == 0 && tab[i] == 0)
            ter = 1;
        else
            ter = 0;
    }
    return ter;
}

int main() {
    int zera, jedynki, wynik;
    scanf("%d%d%d", &zera, &jedynki, &wynik);
    if (zera == 0 || jedynki == 0) {
        for (int i = 0; i < jedynki; i++)
            tab[i] = (zera == 0);
        printf("%d", wynik == policz(zera == 0 ? jedynki : zera));
        return 0;
    }
    int N = zera + jedynki;
    silnie[0] = 1;
    for (int i = 1; i <= N; i++) {
        silnie[i] = silnie[i - 1] * i;
        silnie[i] %= mod;
    }
    long long wyn = 0;
    for (int i = 1; i < N; i++) {
        int pewno = i - 1;
        int zera_zostalo = zera - pewno;
        int jedynki_zostalo = jedynki - 1;
        int zostalo = N - i;
        if (zera_zostalo >= 0 && jedynki_zostalo >= 0 && zostalo == zera_zostalo + jedynki_zostalo && wynik == (pewno % 2)) {
            wyn += dwumian(zostalo, zera_zostalo);
            wyn %= mod;
        }
    }
    if (jedynki == 1 && N % 2 == wynik) {
        wyn++;
        wyn %= mod;
    }
    printf("%lld", wyn);
    return 0;
}