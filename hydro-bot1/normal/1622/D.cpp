// Hydro submission #62596d6ccc64917dc46695e3@1650027885010
#include <bits/stdc++.h>
using namespace std;
#define int long long
 
inline int read() {
    int x = 0, f = 0; char c = 0;
    while (!isdigit(c)) f |= c == '-', c = getchar();
    while (isdigit(c)) x = (x << 3) + (x << 1) + (c & 15), c = getchar();
    return f ? -x : x;
}
 
#define N 5010
#define P 998244353

int n, k, fac[N], inv[N], res = 1;
char a[N];

int Pow(int x, int k, int r = 1) {
    for (; k; k >>= 1, x = x * x % P)
        if (k & 1) r = r * x % P;
    return r;
}
void Mem() {
    fac[0] = 1;
    for (int i = 1; i < N; i ++) {
        fac[i] = fac[i - 1] * i % P;
    }
    inv[N - 1] = Pow(fac[N - 1], P - 2);
    for (int i = N - 2; i >= 0; i --) {
        inv[i] = inv[i + 1] * (i + 1) % P;
    }
}
int C(int n, int m) {
    if (n < m) return 0;
    return fac[n] * inv[m] % P * inv[n - m] % P;
}

signed main() {
    Mem();
    n = read(), k = read(), scanf("%s", a + 1);
    if (k == 0) return puts("1"), 0;
    a[0] = a[n + 1] = '1';
    for (int i = 1; i <= n; i ++) {
        if (a[i - 1] != '1') continue;
        for (int j = i, s = 0; j <= n; j ++) {
            s += (a[j] == '1');
            if (s == k - 1 && a[j + 1] == '1' && i != 1 && j != n) {
                (res += P + 1 - C(j - i + 1, k - 1)) %= P;
            } 
            if (s == k && a[j + 1] == '1') {
                (res += C(j - i + 1, k) - 1 + P) %= P;
            }
        }
    }
    printf("%lld\n", res);
    return 0;
}