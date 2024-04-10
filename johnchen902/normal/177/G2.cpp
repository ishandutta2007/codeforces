#include <cstdio>
#include <algorithm>
using namespace std;
constexpr int mod = 1000000007;

bool *gens(int n, bool *s) {
    if(n <= 1) {
        *s = n;
        return s + 1;
    } else {
        return gens(n - 2, gens(n - 1, s));
    }
}

struct MP {
    const int n;
    const bool (&p)[100000];
    int (&f)[100001];
    int i;
    MP(int n0, const bool (&p0) [100000], int (&f0) [100001]) : n(n0), p(p0), f(f0) {}
    void compute_fl() {
        f[0] = -1;
        for(int i = 1, j = 0; i < n; i++) {
            while(j >= 1 && p[i] != p[j])
                j = f[j];
            if(p[i] == p[j])
                j++;
            f[i + 1] = j;
        }
    }
    void reset() { i = 0; }
    bool insert(bool c) {
        while(i >= 0 && p[i] != c)
            i = f[i];
        if(c == p[i++] && i == n) {
            i = f[i];
            return true;
        }
        return false;
    }
};

struct Mx { int a[2][2]; };
Mx operator * (const Mx& lhs, const Mx& rhs) {
    Mx m = {};
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
                m.a[i][j] = (m.a[i][j] + (long long) lhs.a[i][k] * rhs.a[k][j]) % mod;
    return m;
}

int len[27];
bool s26[196418];
int pn;
bool p[100000];
int fl[100001];

int solve(long long k) {
    if(k <= 1)
        return (pn == 1 && p[0] == k) ? 1 : 0;
    if(k <= 26 && len[k] < pn)
        return 0;
    int x = 2;
    while(len[x] < pn)
        x++;
    // len[x] >= pn, len[x] = O(pn), x <= 25
    int f0 = 0, c0 = 0, f1 = 0, c1 = 0;
    MP mp(pn, p, fl);
    mp.compute_fl();
    mp.reset();
    for(int i = 0; i < len[x]; i++)
        f0 += mp.insert(s26[i]);
    for(int i = 0; i < min(len[x], pn - 1); i++)
        c0 += mp.insert(s26[i]);
    mp.reset();
    for(int i = 0; i < len[x + 1]; i++)
        f1 += mp.insert(s26[i]);
    for(int i = 0; i < min(len[x], pn - 1); i++)
        c1 += mp.insert(s26[i]);
    // Got x, f0, c0, f1, c1, k
    k -= x;
    Mx mx = { 0, 1, 1, 1 }, mxp = mx, mxq = {1, 0, 0, 1};
    for(long long kk = k; kk; kk >>= 1, mxp = mxp * mxp)
        if(kk & 1)
            mxq = mxq * mxp;
    return ((long long) mxq.a[0][0] * (f0 + c0) + (long long) mxq.a[0][1] * (f1 + c1) + (mod - (k % 2 ? c1 : c0))) % mod;
}

int main() {
    len[0] = len[1] = 1;
    for(int i = 2; i <= 26; i++)
        len[i] = len[i - 1] + len[i - 2];
    gens(26, s26);
    long long k;
    int m;
    scanf("%lld %d\n", &k, &m);
    k--;
    for(int i = 0; i < m; i++) {
        pn = 0;
        for(char c; (c = getchar()) != '\n'; )
            p[pn++] = c == 'b';
        printf("%d\n", solve(k));
    }
}