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

void _print() {cerr << "]\n";} template <class T, class... V>
void _print(T t, V... v) {cerr<<t; if (sizeof...(v)) cerr << ", "; _print(v...);}
#define D(x...) do {cerr << "[" << #x << "] = ["; _print(x); } while(0);
#define DF(i, s, e, x...) do { for (ll i=(s); i<(e); ++i) {cerr<<i<<": "; D(x)} } while(0);


typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;

#define G(x) ll x; cin >> x;
#define GD(x) ld x; cin >> x;
#define GS(s) string s; cin >> s;
#define F(i, l, r) for(ll i = l; i < (r); ++i)
#define FD(i, r, l) for(ll i = r; i > (l); --i)
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(a) (a).begin(), (a).end()
#define TC ll ntests;cin>>ntests;ll tc=0;goto _restart;_restart:;while(++tc<=ntests)
#define EXT(x) {cout<<x<<'\n'; goto _restart;}
#define K first
#define V second
#define M 1000000007 //998244353
//#define N 200010

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	G(tc) while(tc--) {
		G(n)
		F(i, 0, n) { G(x) }
		cout << 3 * n << '\n';
		for(ll i = 1; i < n; i += 2) {
			#define P(k) cout << k << ' ' << i << ' ' << i + 1 << '\n';
			P(1) P(1) P(2) P(1) P(1) P(2)
		}	
	}
}