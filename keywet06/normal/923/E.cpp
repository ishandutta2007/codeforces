#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int P = 998244353;
const int N = 200010;

inline int add(const int &x, const int &y) {
    return x + y < P ? x + y : x + y - P;
}
inline int sub(const int &x, const int &y) {
    return x - y < 0 ? x - y + P : x - y;
}
inline int mul(const int &x, const int &y) { return (int)((ll)x * y % P); }
int ksm(int x, ll y = P - 2) {
    int ss = 1;
    for (; y; y /= 2, x = mul(x, x)) {
        if (y % 2) ss = mul(ss, x);
    }
    return ss;
}

namespace Poly {

int Get(int x) {
    int ss = 1;
    while (ss <= x) ss <<= 1;
    return ss;
}
void ntt(vector<int> &A, int lmt, int opt) {
    A.resize(lmt);
    for (int i = 0, j = 0; i < lmt; i++) {
        if (i < j) swap(A[i], A[j]);
        for (int k = lmt >> 1; (j ^= k) < k;) k >>= 1;
    }
    vector<int> w(lmt >> 1);
    for (int mid = 1; mid < lmt; mid <<= 1) {
        w[0] = 1;
        int w0 = ksm(opt == 1 ? 3 : (P + 1) / 3, (P - 1) / mid / 2);
        for (int j = 1; j < mid; j++) w[j] = mul(w[j - 1], w0);
        for (int j = 0; j < lmt; j += mid << 1) {
            for (int k = 0; k < mid; k++) {
                int x = A[j + k], y = mul(w[k], A[j + mid + k]);
                A[j + k] = add(x, y), A[j + mid + k] = sub(x, y);
            }
        }
    }
    if (opt == -1) {
        for (int inv = ksm(lmt), i = 0; i < lmt; i++) A[i] = mul(A[i], inv);
    }
}
vector<int> Mul(const vector<int> &a, const vector<int> &b) {
    vector<int> A = a, B = b;
    int lmt = Get(a.size() + b.size() - 2);
    ntt(A, lmt, 1), ntt(B, lmt, 1);
    for (int i = 0; i < lmt; i++) A[i] = mul(A[i], B[i]);
    return ntt(A, lmt, -1), A.resize(a.size() + b.size() - 1), A;
}

}  // namespace Poly

int n;
ll m;
vector<int> f, g;
int fa[N], fb[N];

int main() {
    scanf("%d%I64d", &n, &m);
    fa[0] = fa[1] = fb[0] = fb[1] = 1;
    for (int i = 2; i <= n; i++) fa[i] = mul(fa[i - 1], i);
    for (int i = 2; i <= n; i++) fb[i] = mul(P - P / i, fb[P % i]);
    for (int i = 2; i <= n; i++) fb[i] = mul(fb[i - 1], fb[i]);
    f.resize(n + 1), g.resize(n + 1);
    for (int i = 0; i <= n; i++) {
        scanf("%d", &f[n - i]), f[n - i] = mul(f[n - i], fa[i]), g[i] = fb[i];
    }
    g = Poly::Mul(f, g), g.resize(n + 1);
    for (int i = 0; i <= n; i++) g[n - i] = mul(g[n - i], ksm(ksm(i + 1, m)));
    for (int i = 0; i <= n; i++) f[i] = (i & 1) ? (P - fb[i]) : fb[i];
    f = Poly::Mul(f, g);
    for (int i = 0; i <= n; i++) printf("%d ", mul(f[n - i], fb[i]));
    printf("\n");
    return 0;
}