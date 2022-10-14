#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
#define F(i, l, r) for(ll i = l; i < (r); ++i)
#define FD(i, r, l) for(ll i = r; i > (l); --i)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(a) (a).begin(), (a).end()
#define K first
#define V second
#define M 1000000007 //998244353
//#define N 200010

ll f[12];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    f[0] = 6;
    F(i, 1, 12) f[i] = (i + 3) * f[i - 1];
    G(tc) while(tc--) {
        G(n) ll ans = M; F(mk, 0, 1 << 12) {
            ll t = n;
            F(i, 0, 12) if((mk >> i) % 2 && t >= f[i]) t -= f[i];
            ans = min(ans, (ll)__builtin_popcountll(t) + __builtin_popcountll(mk));
        }
        cout << ans << '\n';
    }
}