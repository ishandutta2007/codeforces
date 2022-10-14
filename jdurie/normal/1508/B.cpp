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
#define N 100010
 
ll p2[N];
 
void solve(ll n, ll k, ll s) {
    if(n <= 0) return;
    if(n == 1) { cout << s << ' '; return; }
    ll x = 1;
    while(x < n && p2[n - x - 1] <= k) k -= p2[n - x - 1], x++;
    FD(j, s + x - 1, s - 1) cout << j << ' ';
    solve(n - x, k, s + x); 
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fill_n(p2, N, LLONG_MAX);
    F(i, 0, 62) p2[i] = (1ll << i);
    G(tc) while(tc--) {
        G(n) G(k)
        if(k > p2[n - 1]) cout << "-1";
        else solve(n, k - 1, 1);
        cout << '\n';
    }    
}