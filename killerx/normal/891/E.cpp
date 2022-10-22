#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mod = 1000000007;

int qp(int x, int n = mod - 2) {
    int ans = 1;
    for (; n; n >>= 1, x = 1LL * x * x % mod)
        if (n & 1) ans = 1LL * ans * x % mod;
    return ans;
}

int down(int x, int n) {
    int ans = 1;
    for (int i = x; i > x - n; -- i)
        ans = 1LL * ans * i % mod;
    return ans;
}

struct Poly : vector <int> {
    Poly(int n) {
        clear();
        resize(n);
    }
    
    friend Poly operator * (const Poly &a, const Poly &b) {
        Poly ans(a.size() + b.size() - 1);
        rep(i, a.size()) rep(j, b.size()) {
            ans[i + j] += 1LL * a[i] * b[j] % mod;
            if (ans[i + j] >= mod) ans[i + j] -= mod;
        }
        return ans;
    }
};

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector <int> a(5005);
    rep(i, n) scanf("%d", &a[i]);
    Poly F(1);
    F[0] = 1;
    rep(i, n) {
        Poly temp(2);
        temp[0] = a[i];
        temp[1] = mod - 1;
        F = F * temp;
    }
    int mul = 1;
    rep(i, n) mul = 1LL * mul * a[i] % mod;
    int emul = 0;
    for (int i = 0; i <= n && i <= k; ++ i) {
        int temp = 1LL * F[i] * qp(n, k - i) % mod;
        temp = 1LL * temp * down(k, i) % mod;
        emul += temp;
        if (emul >= mod) emul -= mod;
    }
    emul = 1LL * emul * qp(n, mod - 1 - k) % mod;
    int ans = (mul + mod - emul) % mod;
    printf("%d\n", ans);
    return 0;
}