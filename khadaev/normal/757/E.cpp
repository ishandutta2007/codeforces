#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
    for (auto i : a) cerr << i << ' ';\
    cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

const int N = 1e6 + 10;
const int LOG = 20;

ll coeff[N][LOG];
int maxdiv[N];
int p[N];

void add(ll &a, ll b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

int main() {
    coeff[0][0] = 1;
    forn(i, 1, LOG) coeff[0][i] = 2;
    forn(i, 1, N) {
        coeff[i][0] = coeff[i - 1][0];
        forn(j, 1, LOG) {
            coeff[i][j] = coeff[i][j - 1];
            add(coeff[i][j], coeff[i - 1][j]);
        }
    }
    vector<int> primes;
    forn(i, 0, N) maxdiv[i] = i;
    forn(i, 2, N) {
        if (maxdiv[i] == i) primes.eb(i);
        for (int j : primes) {
            if (i * j >= N) break;
            maxdiv[i * j] = i;
        }
    }
    forn(i, 1, N) p[i] = (i == maxdiv[i] ? i : i / maxdiv[i]);
    int q;
    scanf("%d", &q);
    while (q--) {
        int r, n;
        scanf("%d %d", &r, &n);
        int pr = -1, deg = 0;
        ll ans = 1;
        while (n != maxdiv[n]) {
            if (p[n] == pr) ++deg;
            else {
                ans *= coeff[r][deg];
                ans %= MOD;
                pr = p[n];
                deg = 1;
            }
            n = maxdiv[n];
        }
        if (n != 1) {
            if (p[n] == pr) ++deg;
            else {
                ans *= coeff[r][deg];
                ans %= MOD;
                pr = p[n];
                deg = 1;
            }
        }
        ans *= coeff[r][deg];
        ans %= MOD;
        printf("%lld\n", ans);
    }
}