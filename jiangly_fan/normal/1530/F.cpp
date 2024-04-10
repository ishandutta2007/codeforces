#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 31607;
LL A[1 << 23], B[1 << 21];
int a[21][21], b[21][21];
int z[1 << 21];
LL power(LL a, LL r) {
    LL res = 1;
    for (; r; r >>= 1, a = a * a % mod)
        if (r & 1) res = res * a % mod;
    return res;
}
void sub(LL& x, LL y) {
    x -= y;
    if (x < 0) x += mod;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i += 1) {
        LL p = 1;
        for (int j = 0; j < n; j += 1) {
            cin >> a[i][j];
            a[i][j] = a[i][j] * power(10000, mod - 2);
            p = p * a[i][j] % mod;
        }
    }
    for (int i = 0; i < (1 << (n + 2)); i += 1) A[i] = 1;
    for (int i = 0; i < (1 << n); i += 1)
        for (int j = 0; j < n; j += 1)
            if ((i >> j) & 1)
                z[i] = j;
    for (int i = 0; i < n; i += 1) {
        B[0] = 1;
        for (int j = 1; j < (1 << n); j += 1) {
            B[j] = B[j ^ (1 << z[j])] * a[i][z[j]] % mod;
        }
        for (int j = 0; j < (1 << n); j += 1) {
            sub(B[j], B[(1 << n) - 1]);
        }
        for (int j = 0; j < (1 << (n + 2)); j += 1) {
            int F = i, S = n - i - 1;
            int k = j & ((1 << n) - 1);
            k |= ((j >> n) & 1) << F;
            k |= ((j >> (n + 1)) & 1) << S;
            A[j] = A[j] * B[k] % mod;
            //cout << i << " " << j << " " << k << " " << B[k] % mod << "\n";
        }
    }
    for (int i = 0; i < (1 << (n + 2)); i += 1) {
        //cout << i << " " << A[i] % mod << "\n";
    }
    for (int i = 0; i < n + 2; i += 1) 
        for (int j = 0; j < (1 << (n + 2)); j += 1)
            if (((j >> i) & 1) == 0) A[j] = (A[j] + mod - A[j | (1 << i)]) % mod;
    cout << (mod + 1 - A[0]) % mod;
    return 0;
}