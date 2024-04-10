#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef long long ll;

const int maxn = 100500;

int mod = 1e9+7;
int add(int x, int y) { x += y; if (x >= mod) x -= mod; return x; }
int mul(i64 x, i64 y) { return x*y%mod; }
int sub(int x, int y) { return add(x, mod-y); }
i64 mpow(int x, int k) {
    int a = 1;
    while (k) {
        if (k%2) a = mul(a, x);
        x = mul(x, x);
        k /= 2;
    }
    return a;
}

int n;
int f[maxn], g[maxn];


void solve() {
    --mod;
    fore(i, 1, n) for (int j = i; j <= n; j += i) {
        g[i] = add(g[i], f[j]);
    }
    ++mod;
//     fore(i, 1, n) cerr << g[i] << " "; cerr << endl;
    fore(i, 1, n) g[i] = sub(mpow(2, g[i]), 1);
//     fore(i, 1, n) cerr << g[i] << " "; cerr << endl;
    for (int i = n; i >= 1; --i) {
        f[i] = g[i];
        for (int j = i*2; j <= n; j += i) f[i] = sub(f[i], f[j]);
    }
//     fore(i, 1, n) cerr << f[i] << " "; cerr << endl;

    cout << f[1] << endl;
}

int main() {
#ifdef LOCAL
    freopen("f.in", "r", stdin);
#endif

    int k;
    cin >> k;
    forn(i, k) {
        int x;
        cin >> x;
        ++f[x];
        n = max(n, x);
    }
    solve();

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}