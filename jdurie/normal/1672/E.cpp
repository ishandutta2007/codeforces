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
 
map<ll, ll> q;
 
ll query(ll x) {
    if(!q.count(x)) {
        cout << "? " << x << endl;
        cin >> q[x];
    }
    return q[x];
}
 
ll bsch(ll l, ll r) {
    if(l == r) return l;
    ll m = (l + r) / 2;
    return query(m) == 1 ? bsch(l, m) : bsch(m + 1, r);
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n)
    ll s = bsch(1, 5000000);
    ll ans = s;
    s -= n - 1;
    vector<ll> v;
    F(d, s, s + n - 1) {
        for(ll j = 1; j * j <= d; ++j) if(!(d % j)) {
            if(d / j <= n && d / j >= s + n - 1 - d) v.push_back(j);
            if(j <= n && j >= s + n - 1 - d) v.push_back(d / j);
        }
    }
    mt19937 g(__builtin_ia32_rdtsc());
    shuffle(A(v), g);
    for(ll x : v) if(query(x)) ans = min(ans, query(x) * x);
    cout << "! " << ans << endl;
}