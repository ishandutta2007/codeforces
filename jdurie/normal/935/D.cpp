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
#define F(i, l, r) for(ll i = l; i < r; i++)
#define FD(i, r, l) for(ll i = r; i > l; i--)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(x) (x).begin(), (x).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 100010
#define INV(a) pw(a, M - 2)

ll a[N], b[N], ct[N];

ll pw(ll aa, ll p) {
    if(!p) return 1;
    ll t = pw(aa, p / 2);
    return t * t % M * (p % 2 ? aa : 1) % M;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(m)
    F(i, 0, n) cin >> b[i];
    F(i, 0, n) cin >> a[i];
    FD(i, n - 1, -1) {
        ct[i] = ct[i + 1];
        if(!a[i]) ct[i]++;
        if(!b[i]) ct[i]++;
    }
    ll eqP = 1, ans = 0, f = ct[0];
    F(i, 0, n + 1) ct[i] = pw(m, ct[i]);
    F(i, 0, n) {
        ll k = eqP * ct[i + 1] % M;
        if(!a[i] && !b[i]) ans = (ans + k * ((m * (m - 1) / 2) % M) % M) % M;
        if(!a[i] && b[i]) ans = (ans + k * (b[i] - 1) % M) % M;
        if(a[i] && !b[i]) ans = (ans + k * (m - a[i]) % M) % M;
        if(a[i] && b[i] && a[i] < b[i]) ans = (ans + k) % M;
        if(!a[i] && !b[i]) eqP = (eqP * m) % M;
        if(a[i] && b[i] && a[i] - b[i]) break;
    }
    F(i, 0, f) ans = ans * INV(m) % M;
    EX(ans)
}