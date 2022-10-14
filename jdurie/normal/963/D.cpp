//String Hashing
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pl;
typedef pair<unsigned ll, ll> hsh;

#define K first
#define V second
#define M 1000000321
#define OP(x, y) constexpr hsh operator x (const hsh a, const hsh b) { return { a.K x b.K, (a.V y b.V) % M }; }
OP(+, +) OP(*, *) OP(-, + M -)
mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> dist(256, M - 1);

#define G(x) ll x; cin >> x;
#define GD(x) ld x; cin >> x;
#define GS(s) string s; cin >> s;
#define F(i, l, r) for(ll i = l; i < (r); i++)
#define FD(i, r, l) for(ll i = r; i > (l); i--)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define H(i, l) (h[(i) + (l)] - h[i] * p[l])
#define EQ(i, j, l) (H(i, l) == H(j, l))
#define A(a) (a).begin(), (a).end()
#define K first
#define V second
#define N 200010

string s;
hsh p[N], h[N];
ll n, suff[N];

ll lcp(ll i, ll j, ll l, ll r) {
    if(l == r) return l;
    ll m = (l + r + 1) / 2;
    return EQ(i, j, m) ? lcp(i, j, m, r) : lcp(i, j, l, m - 1);
}

bool lex_less(ll i, ll lI, ll j, ll lJ) {
    if(EQ(i, j, min(lI, lJ))) return lI < lJ;
    ll m = lcp(i, j, 0, min(lI, lJ) - 1);
    return s[i + m] < s[j + m];
}

ll bS1(ll l, ll r, ll i, ll L) {
    if(l == r) return l;
    ll m = (l + r) / 2;
    return lex_less(suff[m], min(n - suff[m], L), i, L) ? bS1(m + 1, r, i, L) : bS1(l, m, i, L);
}

ll bS2(ll l, ll r, ll i, ll L) {
    if(l == r) return l;
    ll m = (l + r + 1) / 2;
    return lex_less(i, L, suff[m], min(n - suff[m], L)) ? bS2(l, m - 1, i, L) : bS2(m, r, i, L);
}

ll k[N], idx[N], sz[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s; n = s.size();
    G(q) F(i, 0, q) {
        cin >> k[i];
        idx[i] = s.size();
        GS(t)
        s += t;
        sz[i] = t.size();
    }
    p[0] = { 1, 1 }, p[1] = { dist(gen) | 1, dist(gen) };
    F(i, 1, s.size() + 1) p[i] = p[i - 1] * p[1], h[i] = h[i - 1] * p[1] + make_pair(s[i - 1], s[i - 1]);
    iota(suff, suff + n, 0);
    sort(suff, suff + n, [](ll i, ll j) { return lex_less(i, n - i, j, n - j); });
    F(i, 0, q) {
        ll st = bS1(0, n - 1, idx[i], sz[i]), en = bS2(0, n - 1, idx[i], sz[i]);
        if(en - st + 1 < k[i]) cout << "-1\n";
        else {
            vector<ll> v;
            F(j, st, en + 1) v.push_back(suff[j]);
            sort(A(v));
            ll ans = n;
            F(j, 0, v.size() - k[i] + 1) ans = min(ans, v[j + k[i] - 1] - v[j]);
            cout << ans + sz[i] << '\n';
        }
    }
}