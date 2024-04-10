#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
template<class T, class S>
ostream& operator << (ostream &o, const pair<T, S> &p) {
    return o << '(' << p.first << ", " << p.second << ')';
}
template<template<class, class...> class T, class... A>
typename enable_if<!is_same<T<A...>, string>(), ostream&>::type
operator << (ostream &o, T<A...> V) {
	o << '[';
	for(auto a : V) o << a << ", ";
	return o << ']';
}

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;

#define G(x) ll x; cin >> x;
#define GD(x) ld x; cin >> x;
#define GS(s) string s; cin >> s;
#define F(i, l, r) for(ll i = l; i < (r); i++)
#define FD(i, r, l) for(ll i = r; i > (l); i--)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(a) (a).begin(), (a).end()
#define K first
#define V second
#define M 998244353
#define N 300010

pl p[N];

#define NCR(n, r) (f[n] * fi[r] % M * fi[(n) - (r)] % M)

ll f[N], fi[N];

ll inv(ll a, ll b) { return 1 < a ? b - inv(b % a, a) * b / a : 1; } //inv a mod b

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    f[0] = fi[0] = 1;
    F(i, 1, N) f[i] = i * f[i - 1] % M, fi[i] = inv(f[i], M);
    G(n) G(k)
    F(i, 0, n) cin >> p[i].K >> p[i].V;
    sort(p, p + n);
    map<ll, ll> ends;
    ll ans = 0, sz = 0, i = 0;
    while(i < n) {
        ll i0 = i;
        while(ends.size() && ends.begin()->K < p[i0].K) {
            sz -= ends.begin()->V;
            ends.erase(ends.begin());
        }
        while(p[i].K == p[i0].K) ends[p[i++].V]++;
        ll nw = i - i0;
        ll waysB = (sz + nw >= k ? NCR(sz + nw, k) : 0);
        ll waysS = (sz >= k ? NCR(sz, k) : 0);
        ans = (ans + waysB + M - waysS) % M;
        sz += nw;
    }
    cout << ans << '\n';
}