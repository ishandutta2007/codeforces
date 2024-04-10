#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef vector<int> vi;
typedef long long i64;
// #ifdef LOCAL
// const int maxn = 1000;
// #else
const int maxn = 1000500;
// #endif
const int mod = 1000000007;
int add(int x, int y) { x += y; if (x >= mod) x -= mod; return x; }
int sub(int x, int y) { x -= y; if (x < 0) x += mod; return x; }
int mul(i64 x, i64 y) { return x*y%mod; }
int rev(int x) {
    int a = 1;
    int k = mod - 2;
    while (k) {
        if (k&1) a = mul(a, x);
        x = mul(x, x);
        k /= 2;
    }
    return a;
}

vi divs[maxn];
int ff[maxn], rff[maxn];
void gend() {
    for (int i = 1; i < maxn; ++i) {
        for (int j = i; j < maxn; j += i) {
            divs[j].push_back(i);
        }
        reverse(divs[i].begin(), divs[i].end());
    }

    ff[0] = rff[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        ff[i] = mul(ff[i-1], i);
        rff[i] = mul(rff[i-1], rev(i));
    }
}

int cnk(int n, int k) {
    if (n < k) return 0;
    return mul(ff[n], mul(rff[k], rff[n-k]));
}

int n, k, q;
int sz[maxn], f[maxn], g[maxn], gs[maxn];
int res;

void addn(int x) {
    for (int d: divs[x]) {
        ++sz[d];
        int df = sub(cnk(sz[d], k), f[d]);
        f[d] = add(f[d], df);

        int newg = sub(f[d], gs[d]);
        int dg = sub(newg, g[d]);
        g[d] = add(g[d], dg);

        for (int dd: divs[d]) if (dd != d) {
            gs[dd] = add(gs[dd], dg);
        }

        res = add(res, mul(dg, d));
    }

//     cout << "sz: "; forn(i, 10) if(i) cout << sz[i] << " "; cout << endl;
//     cout << "f: "; forn(i, 10)  if(i)cout << f[i] << " "; cout << endl;
//     cout << "g: "; forn(i, 10)  if(i)cout << g[i] << " "; cout << endl;
//     cout << "gs: "; forn(i, 10)  if(i)cout << gs[i] << " "; cout << endl;
//     cout << endl;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    gend();

    scanf("%d%d%d", &n, &k, &q);
    forn(i, n) {
        int x;
        scanf("%d", &x);
        addn(x);
    }
    forn(i, q) {
        int x;
        scanf("%d", &x);
        addn(x);
        printf("%d\n", res);
    }

#ifdef LOCAL
    cerr << "Time: " << clock()/1000 << endl;
#endif

    return 0;
}