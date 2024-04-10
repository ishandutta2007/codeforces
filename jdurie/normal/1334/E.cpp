#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
#define N 100010

ll f[N], fInv[N];
vector<ll> prim;

ll pw(ll a, ll p) {
    if(!p) return 1;
    ll t = pw(a, p / 2);
    return t * t % M * (p % 2 ? a : 1) % M;
}

ll inv(ll a) { return pw(a, M - 2); }

ll pLen(ll v) {
    ll sm = 0, pd = 1;
    for(ll p : prim) if(!(v % p)) {
        ll ct = 0;
        while(!(v % p)) { v /= p; ct++; }
        sm += ct;
        pd = pd * f[ct] % M;
    }
    return f[sm] * inv(pd) % M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(D) G(q)
    for(ll i = 2; i * i <= D; i++)
        if(!(D % i)) {
            prim.push_back(i);
            while(!(D % i)) D /= i;
        }
    if(D > 1) prim.push_back(D);
    f[0] = fInv[0] = 1;
    F(i, 1, N) {
        f[i] = f[i - 1] * i % M;
        fInv[i] = fInv[i - 1] * inv(i) % M;
    }
    while(q--) {
        G(u) G(v)
        ll g = __gcd(u, v);
        cout << pLen(u / g) * pLen(v / g) % M << endl;
    }
}