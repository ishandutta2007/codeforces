#include <cstdio>
#include <algorithm>

long long wyn[1000007][3];
long long ile[3];

const int mod = 1000000007;

int main() {
    int N, L, R;
    scanf("%d%d%d", &N, &L, &R);
    wyn[0][0] = 1;
    int pocz = -1, kon = -1;
    for (int i = L; i <= R; i++)
        if (i % 3 == 0) {
            pocz = i;
            break;
        }
    for (int i = R; i >= L; i--)
        if (i % 3 == 0) {
            kon = i;
            break;
        }
    if (pocz != -1 && kon != -1)
        ile[0] = (kon - pocz) / 3 + 1;

    pocz = -1, kon = -1;
    for (int i = L; i <= R; i++)
        if (i % 3 == 1) {
            pocz = i;
            break;
        }
    for (int i = R; i >= L; i--)
        if (i % 3 == 1) {
            kon = i;
            break;
        }
    if (pocz != -1 && kon != -1)
        ile[1] = (kon - pocz) / 3 + 1;

    pocz = -1, kon = -1;
    for (int i = L; i <= R; i++)
        if (i % 3 == 2) {
            pocz = i;
            break;
        }
    for (int i = R; i >= L; i--)
        if (i % 3 == 2) {
            kon = i;
            break;
        }
    if (pocz != -1 && kon != -1)
        ile[2] = (kon - pocz) / 3 + 1;
    ile[0] %= mod;
    ile[1] %= mod;
    ile[2] %= mod;
    for (int i = 1; i <= N; i++) {
        for (int w = 0; w < 3; w++) {
            for (int z = 0; z < 3; z++) {
                wyn[i][(w + z) % 3] += wyn[i - 1][w] * ile[z];
                wyn[i][(w + z) % 3] %= mod;
            }
        }
    }
    printf("%lld", wyn[N][0] % mod);
    return 0;
}