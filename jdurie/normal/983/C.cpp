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
#define M 1000000007 //998244353
#define N 2010
 
unordered_map<ll, ll> dp[N][10];
ll cur[N], nxt[N], n, x = 0;
 
ll r(ll i, ll f, ll mask) {
	if(i == n && !mask) return 0;
	if(dp[i][f].count(mask)) return dp[i][f][mask];
	multiset<ll> fl;
	dp[i][f][mask] = 0;
	ll temp = mask;
	F(iiiiii, 0, 4) { 
		if(temp % 10 && temp % 10 != f) fl.insert(temp % 10);
		temp /= 10; 
	}
	ll j = i;
	while(fl.size() != 4 && j < n && cur[j] == f)
		fl.insert(nxt[j++]);
	ll newMask = 0, pw = 1;
	for(ll k : fl) {
		newMask += k * pw;
		pw *= 10;
	}
	if(j == n && !newMask) return dp[i][f][mask];
	ll mn = LLONG_MAX / 10000;
	for(ll k : fl) mn = min(mn, abs(k - f) + r(j, k, newMask));
	if(j < n && f != cur[j]) mn = min(mn, abs(cur[j] - f) + r(j, cur[j], newMask));
	return dp[i][f][mask] = mn + dp[i][f][mask]; 
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
	F(i, 0, n) cin >> cur[i] >> nxt[i];
	cout << r(0, 1, 0) + 2 * n << endl;
}