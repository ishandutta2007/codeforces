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

typedef int ll;
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
#define N 200010

ll fact[N];
vector<ll> abc[6], fs[N];
vector<ll> aa[6];
ll precalc[N][3];
ll gc[8];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    	F(i, 1, N) for(ll j = i; j < N; j += i) fact[j]++, fs[j].push_back(i);
	G(tc) while(tc--) {
		G(a) G(b) G(c)
		abc[0] = {a, b, c};
		abc[1] = {a, c, b};
		abc[2] = {b, a, c};
		abc[3] = {b, c, a};
		abc[4] = {c, a, b};
		abc[5] = {c, b, a};
		aa[0] = {0, 1, 2};
		aa[1] = {0, 2, 1};
		aa[2] = {1, 0, 2};
		aa[3] = {1, 2, 0};
		aa[4] = {2, 0, 1};
		aa[5] = {2, 1, 0};
		ll ans = 0, ans2 = 0;
		fill_n(gc, 8, 0);
		F(i, 0, 8) F(j, 0, 3) if((i >> j) & 1) gc[i] = __gcd(gc[i], abc[0][j]);
		F(mask, 1, 64) {
			vector<ll> v(3, 0);
			F(j, 0, 6) if((mask >> j) & 1)
				F(k, 0, 3) v[k] |= 1 << aa[j][k];
			F(k, 0, 3) v[k] = gc[v[k]];
			ll s = __builtin_popcount(mask) & 1 ? 1 : -1;
			ans += s * fact[v[0]] * fact[v[1]] * fact[v[2]];
			ans2 += s * (fact[__gcd(v[0], v[1])] * fact[v[2]] + fact[__gcd(v[0], v[2])] * fact[v[1]] + fact[__gcd(v[1], v[2])] * fact[v[0]]);
		}
		ll g = __gcd(__gcd(a, b), c);
		ll ans3 = fact[g];
		ans2 -= 3 * ans3;
		//x x y 3x
		//ll ans2 = fact[__gcd(a, b)]*fact[c] + fact[__gcd(a, c)]*fact[b] + fact[__gcd(b, c)]*fact[a] - 3*ans3;
		ans -= ans3 + ans2;
		cout << abs(ans / 6 + ans2/3 + ans3) << '\n';
	}	
}