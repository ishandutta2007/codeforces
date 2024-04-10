#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;

typedef long long int64;

const int P = 1e9 + 7;

int Add(int a, int b) { return (a += b) >= P ? a - P : a; }
int Sub(int a, int b) { return (a -= b) < 0 ? a + P : a; }
int Mul(int a, int b) { return (int64)a * b % P; }

int Pow(int a, int b) {
    int ret = 1;
    for (; b; b >>= 1, a = Mul(a, a)) {
        if (b & 1) ret = Mul(ret, a);
    }
    return ret;
}

int Fac[N], IFac[N];
inline void init(int n) {
    IFac[0] = Fac[0] = 1;
    for (int i = 1; i <= n; ++i) Fac[i] = Mul(Fac[i - 1], i);
    IFac[n] = Pow(Fac[n], P - 2);
    for (int i = n - 1; i; --i) IFac[i] = Mul(IFac[i + 1], i + 1);
}

inline int C(int a, int b) {
    if (b > a) return 0;
    return Mul(Fac[a], Mul(IFac[b], IFac[a - b]));
}

int f[N], g[N];
int n;

int main() {
    init(2e6);
    cin >> n;
    for (int i = n; i; --i) {
        if (i * 2 > n) f[i] = g[i] = 1;
        for (int j = 2; j * i <= n; ++j) {
            if (f[i * j] + 1 > f[i]) f[i] = f[i * j] + 1, g[i] = 0;
            if (f[i * j] + 1 == f[i]) {
                int t1 = n / (i * j), t2 = n / (i);
                g[i] = Add(g[i],
                           Mul(g[i * j],
                               Mul(Fac[t2 - t1], C(n - t1 - 1, t2 - t1 - 1))));
            }
        }
    }
    cout << g[1] << endl;
    return 0;
}