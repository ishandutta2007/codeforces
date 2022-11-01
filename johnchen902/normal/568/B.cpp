#include <cstdio>
using namespace std;
constexpr int mod = 1000000007;
int c[4002][4002];
int a[4002];
int main() {
    c[0][0] = 1;
    for(int i = 0; i < 4001; i++)
        for(int j = 0; j <= i; j++) {
            c[i + 1][j    ] = (c[i + 1][j    ] + c[i][j]) % mod;
            c[i + 1][j + 1] = (c[i + 1][j + 1] + c[i][j]) % mod;
        }

    a[0] = 1;
    for(int i = 1; i <= 4001; i++)
        for(int j = 0; j <= i - 1; j++)
            a[i] = (a[i] + c[i - 1][j] * 1ll * a[i - 1 - j]) % mod;

    int n;
    scanf("%d", &n);
    printf("%d\n", (a[n + 1] - a[n] + mod) % mod);
}