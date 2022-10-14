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
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
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

	TC {
		ll n, m; cin>>n>>m;
		string cur; cin>>cur;
		for (ll i=0; i<m; ++i) {
			string ne;
			for (ll j=0; j<n; ++j) {
				ll r = 0;
				if (j && cur[j-1]=='1') r++; 
				if (j!=n-1 && cur[j+1]=='1') r++; 
				if (cur[j]=='1' || r==1) ne+='1';
				else ne+='0';
			}
			if (ne==cur) break;
			cur = ne;
		}
		cout<<cur<<'\n';
	}

}