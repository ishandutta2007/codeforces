#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

const int N = 5005;
const int P = 1000000007;

int n, m, p;
int f[N];

inline int power(int a, int b) {
    if (b <= 0) return 1;
    int c = power(a, b >> 1);
    c = (int64)c * c % P;
    if (b & 1) c = (int64)c * a % P;
    return c;
}

int main() {
    int i, j;
    scanf("%d%d", &n, &m);
    f[0] = 1;
    for (i = 1; i <= m; i++) {
        for (j = i; j > 0; j--)
            f[j] = ((int64)f[j] * j + (int64)f[j - 1] * (n - j + 1)) % P;
        f[0] = 0;
    }
    for (i = 1; i <= m; i++) p = (p + (int64)f[i] * power(2, n - i)) % P;
    printf("%d\n", p);
    return 0;
}