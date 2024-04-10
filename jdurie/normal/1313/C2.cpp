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
typedef complex<ld> pt;
     
#define G(x) ll x; cin >> x;
#define GD(x) ld x; cin >> x;
#define GS(s) string s; cin >> s;
#define F(i, l, r, ...) for(ll i = l; i != r; i += (1, ##__VA_ARGS__))
#define P(a, n) { cout << #a << ": { "; F(_, 0, n) cout << a[_] << " "; cout << "}" << endl; }
#define CE(a, x) lower_bound(a.begin(), a.end(), x)
#define UP(a, x) upper_bound(a.begin(), a.end(), x)
#define FL(a, x) (x < *a.begin() ? a.end() : --UP(a, x))
#define LO(a, x) (x <= *a.begin() ? a.end() : --CE(a, x))
#define MC(a, x) a.lower_bound(x)
#define MU(a, x) a.upper_bound(x)
#define MF(a, x) (x < (*a.begin()).K ? a.end() : --MU(a, x))
#define ML(a, x) (x <= (*a.begin()).K ? a.end() : --MC(a, x))
#define EX(x) { cout << x << endl; exit(0); }
#define K first
#define V second
#define X real()
#define Y imag()
#define M 1000000007 //998244353
#define N 5000010

ll h[N], pSum[N], sSum[N];
map<ll, ll> cur;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	G(n) F(i, 0, n) cin >> h[i];
	F(i, 0, n) {
		ll ct = 1;
		if(i) pSum[i] = pSum[i - 1];
		while(!cur.empty() && h[i] <= (*cur.rbegin()).K) {
			auto a = *cur.rbegin();
			ct += a.V;
			pSum[i] -= a.K * a.V;
			cur.erase(a.K);
		}
		cur[h[i]] = ct;
		pSum[i] += ct * h[i];
	}
	cur.clear();
	for(ll i = n - 1; i >= 0; i--) {
		ll ct = 1;
		if(i != n - 1) sSum[i] = sSum[i + 1];
		while(!cur.empty() && h[i] <= (*cur.rbegin()).K) {
			auto a = *cur.rbegin();
			ct += a.V;
			sSum[i] -= a.K * a.V;
			cur.erase(a.K);
		}
		cur[h[i]] = ct;
		sSum[i] += ct * h[i];
	}
	ll ind = 0;
	F(i, 0, n) if(pSum[i] + sSum[i] - h[i] > pSum[ind] + sSum[ind] - h[ind]) ind = i;
	ll lM = h[ind], rM = h[ind];
	for(ll j = ind - 1; j >= 0; j--)
		if(h[j] < lM) lM = h[j];
		else h[j] = lM;
	for(ll j = ind + 1; j < n; j++)
		if(h[j] < rM) rM = h[j];
		else h[j] = rM;
	F(i, 0, n) cout << h[i] << " ";
	cout << endl;
}