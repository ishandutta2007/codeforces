#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = (int)1e9 + 7;

const int K = 17;
const int N = 1 << K;
vector<int> f;

int bin(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1) res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
        n >>= 1;
    }
    return res;
}

int inv(int x) {
    return bin(x, MOD - 2);
}

void ORt(vector<int> &a, bool rev) {
    for (int k = 1; k < N; k <<= 1) for (int i = 0; i < N; i += 2 * k) for (int j = 0; j < k; j++) {
                int u = a[i + j], v = a[i + k + j];
                if (!rev) {
                    a[i + j] = u;
                    a[i + j + k] = (u + v) % MOD;
                } else {
                    a[i + j] = u;
                    a[i + j + k] = (v - u + MOD) % MOD;
                }
            }
    /*if (rev) {
        int oN = inv(N);
        for (int &x : a) x = 1LL * x * oN % MOD;
    }*/
}

void XORt(vector<int> &a, bool rev) {
    for (int k = 1; k < N; k <<= 1) for (int i = 0; i < N; i += 2 * k) for (int j = 0; j < k; j++) {
                int u = a[i + j], v = a[i + k + j];
                a[i + j] = (u + v) % MOD;
                a[i + k + j] = (u - v + MOD) % MOD;
            }
    if (rev) {
        int oN = inv(N);
        for (int &x : a) x = 1LL * x * oN % MOD;
    }
}

void ANDt(vector<int> &a, bool rev) {
    for (int k = 1; k < N; k <<= 1) for (int i = 0; i < N; i += 2 * k) for (int j = 0; j < k; j++) {
                int u = a[i + j], v = a[i + k + j];
                if (!rev) {
                    a[i + j] = (u + v) % MOD;
                    a[i + j + k] = v;
                } else {
                    a[i + j] = (u - v + MOD) % MOD;
                    a[i + j + k] = v;
                }
            }
    /*if (rev) {
        int oN = inv(N);
        for (int &x : a) x = 1LL * x * oN % MOD;
    }*/
}


int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    f.assign(N, 0);
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= N; i++) {
        f[i] = (f[i - 2] + f[i - 1]) % MOD;
    }

    int n;
    while (scanf("%d", &n) == 1) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        vector<int> a1(N);
        for (int i = 0; i < n; i++) a1[a[i]]++;
        /*ORt(a1, 0);
        for (int i = 0; i < N; i++) a1[i] = 1LL * a1[i] * a1[i] % MOD;
        ORt(a1, 1);*/
        vector<int> na1(N);
        for (int m = 0; m < N; m++) {
            for (int s = m;; s = (s - 1) & m) {
                na1[m] = (na1[m] + 1LL * a1[s] * a1[m ^ s]) % MOD;
                if (s == 0) break;
            }
        }
        a1 = na1;

        vector<int> a2(N);
        for (int i = 0; i < n; i++) a2[a[i]]++;

        vector<int> a3(N);
        for (int i = 0; i < n; i++) a3[a[i]]++;
        XORt(a3, 0);
        for (int i = 0; i < N; i++) a3[i] = 1LL * a3[i] * a3[i] % MOD;
        XORt(a3, 1);

        for (int i = 0; i < N; i++) {
            a1[i] = 1LL * a1[i] * f[i] % MOD;
            a2[i] = 1LL * a2[i] * f[i] % MOD;
            a3[i] = 1LL * a3[i] * f[i] % MOD;
        }

        ANDt(a1, 0);
        ANDt(a2, 0);
        ANDt(a3, 0);
        for (int i = 0; i < N; i++) a1[i] = 1LL * a1[i] * a2[i] % MOD * a3[i] % MOD;
        ANDt(a1, 1);

        int ans = 0;
        for (int i = 1; i < N; i++) {
            if (!(i & (i - 1))) {
                ans = (ans + a1[i]) % MOD;
            }
        }
        cout << ans << endl;
    }

    return 0;
}