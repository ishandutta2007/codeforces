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
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}" << endl; }
#define EX(x) { cout << x << endl; exit(0); }
#define K first
#define V second
#define M 998244353
#define N 200010

ll f[N], fi[N];

ll pw(ll a, ll p) {
    if(!p) return 1;
    ll t = pw(a, p / 2);
    return t * t % M * (p % 2 ? a : 1) % M;
}

ll inv(ll a) { return pw(a, M - 2); }

ll ch(ll n, ll r) { return f[n] * fi[r] % M * fi[n - r] % M; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    f[0] = fi[0] = 1;
    F(i, 1, N) { f[i] = i * f[i - 1] % M; fi[i] = inv(i) * fi[i - 1] % M; }
    G(n) G(k)
    if(!k) EX(f[n])
    if(k > n - 1) EX(0)
    ll ans = 0;
    F(i, 1, n - k + 1)
        if(i % 2 == (n - k) % 2)
            ans = (ans + pw(i, n) * ch(n - k, i) % M) % M;
        else
            ans = (ans + M - (pw(i, n) * ch(n - k, i) % M)) % M;
    EX(2 * ans * ch(n, k) % M)
}