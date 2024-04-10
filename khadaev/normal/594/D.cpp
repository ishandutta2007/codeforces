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

const int MAX = 1e6 + 10;

const int N = 1 << 18;
ll tree[2 * N];

ll get(int l, int r) {
    ll ans = 1;
    l += N;
    r += N;
    while (l < r) {
        if (l % 2) {
            ans = ans * tree[l] % MOD;
            ++l;
        }
        if (r % 2) {
            --r;
            ans = ans * tree[r] % MOD;
        }
        l /= 2;
        r /= 2;
    }
    return ans;
}

void mult(int pos, ll val) {
    if (pos < 0) return;
    pos += N;
    while (pos) {
        tree[pos] = tree[pos] * val % MOD;
        pos /= 2;
    }
}

ll Pow(ll a, ll b) {
    ll x = 1, y = a;
    while (b) {
        if (b % 2) x = x * y % MOD;
        y = y * y % MOD;
        b /= 2;
    }
    return x;
}

ll Inv(ll a) {
    return Pow(a, MOD - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    forn(i, 0, n) cin >> a[i];

    vector<int> primes;
    vector<int> maxdiv(MAX);
    forn(i, 0, MAX) maxdiv[i] = i;
    forn(i, 2, MAX) {
        if (maxdiv[i] == i) primes.eb(i);
        for (int j : primes) {
            if (j * i >= MAX) break;
            maxdiv[i * j] = i;
        }
    }

    vector<vector<int>> factors(n);
    forn(i, 0, n) {
        int x = a[i];
        while (x != maxdiv[x]) {
            int p = x / maxdiv[x];
            while (x % p == 0) x /= p;
            factors[i].eb(p);
        }
        if (x > 1) factors[i].eb(x);
    }

    vector<ll> prod(n + 1);
    prod[0] = 1;
    forn(i, 0, n) prod[i + 1] = prod[i] * a[i] % MOD;

    vector<ll> invprod(n + 1);
    fore(i, 0, n) invprod[i] = Inv(prod[i]);

    vector<vector<pair<int, int>>> qs(n);
    int q;
    cin >> q;
    forn(i, 0, q) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        qs[r].eb(l, i);
    }

    vector<int> prev(MAX, -1);
    vector<ll> val(MAX), invval(MAX);
    for (int p : primes) {
        val[p] = MOD + 1 - Inv(p);
        invval[p] = Inv(val[p]);
    }

    forn(i, 0, 2 * N) tree[i] = 1;
    vector<ll> ans(q);
    forn(i, 0, n) {
        for (int p : factors[i]) {
            mult(prev[p], invval[p]);
            //if (prev[p] != -1) cerr << "REMOVED: " << p << '\n'; 
            mult(i, val[p]);
            //cerr << "ADDED: " << p << '\n';
            prev[p] = i;
        }
        for (auto x : qs[i]) {
            int l = x.fs, id = x.sn;
            ans[id] = prod[i + 1] * invprod[l] % MOD;
            ans[id] = ans[id] * get(l, n + 1) % MOD;
            //cerr << ans[id] << ' ' << tree[1] * prod[i + 1] % MOD * invprod[l] % MOD << '\n' << '\n';;
        }
    }
    forn(i, 0, q) cout << ans[i] << '\n';
}