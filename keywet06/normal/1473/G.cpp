#include <bits/stdc++.h>

#define pub push_back

const int P = 998244353;
const int D = 332748118;
const int C = 3;
const int N = 500005;

int n;
int fac[N], ifac[N], inv[N], rev[N];
std::vector<int> f, g;

int mul(int x, int y) { return 1ll * x * y % P; }
int get_limit(int x) {
    int l = 1;
    while (l <= x) l <<= 1;
    for (int i = 0; i < l; i++) {
        rev[i] = (rev[i >> 1] >> 1 | (i & 1 ? l >> 1 : 0));
    }
    return l;
}
int ksm(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = mul(res, a), res %= P;
        a = mul(a, a);
        a %= P;
        b >>= 1;
    }
    return res;
}
void NTT(std::vector<int>& a, int l, int type) {
    for (int i = 0; i < l; i++)
        if (i < rev[i]) std::swap(a[i], a[rev[i]]);
    for (int mid = 1; mid < l; mid <<= 1) {
        int Wn = ksm(type == 1 ? C : D, (P - 1) / (mid << 1));
        for (int j = 0; j < l; j += (mid << 1)) {
            int w = 1;
            for (int k = 0; k < mid; k++, w = mul(w, Wn)) {
                int x = a[j + k], y = mul(w, a[j + k + mid]);
                a[j + k] = (x + y) % P;
                a[j + k + mid] = (x - y + P) % P;
            }
        }
    }
    if (type == -1) {
        int INV = ksm(l, P - 2);
        for (int i = 0; i < l; i++) a[i] = mul(a[i], INV);
    }
}
std::vector<int> operator*(std::vector<int> a, std::vector<int> b) {
    int len = a.size() + b.size() - 1;
    int l = get_limit(len);
    a.resize(l);
    b.resize(l);
    for (int i = 0; i < l; i++) {
        rev[i] = (rev[i >> 1] >> 1 | (i & 1 ? l >> 1 : 0));
    }
    NTT(a, l, 1);
    NTT(b, l, 1);
    for (int i = 0; i < l; i++) a[i] = mul(a[i], b[i]) % P;
    NTT(a, l, -1);
    a.resize(len);
    return a;
}
int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    fac[0] = fac[1] = ifac[0] = ifac[1] = inv[1] = 1;
    for (int i = 2; i <= 500000; i++) {
        inv[i] = mul((P - P / i), inv[P % i]);
        ifac[i] = mul(ifac[i - 1], inv[i]);
        fac[i] = mul(fac[i - 1], i);
    }
    f.pub(0), f.pub(1);
    std::cin >> n;
    while (n--) {
        int a, b;
        std::cin >> a >> b;
        int J = a - b + f.size() - 1, K = f.size() - 1;
        g.clear();
        int ff = 1e9;
        for (int i = 1 - K; i <= J - 1; i++) {
            if (a - i >= 0 && b + i >= 0) {
                if (ff == 1e9) ff = i;
                g.pub(mul(ifac[a - i], ifac[b + i]));
            }
        }
        f = f * g;
        for (int i = 0; i < f.size(); i++) f[i] = mul(f[i], fac[a + b]) % P;
        std::vector<int> tmp;
        tmp.clear();
        for (int i = 0; i < f.size(); i++) {
            if (ff >= 0 && ff <= J) tmp.pub(f[i]);
            ff++;
        }
        f = tmp;
        f[0] = 0;
    }
    int ans = 0;
    for (int i = 1; i < f.size(); i++) ans += f[i], ans %= P;
    std::cout << ans << std::endl;
    return 0;
}