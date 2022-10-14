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
#define M 1000000007 //998244353
#define N 200010

ll a[N];
vector<ll> v;

ll kadane() {
    ll sm = 0, mx = 0;
    for(ll x : v) {
        sm += x;
        mx = max(mx, sm);
        if(sm < 0) sm = 0;
    }
    return mx;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) 
        ll evSum = 0;
        F(i, 0, n) {
            cin >> a[i];
            if(!(i & 1)) evSum += a[i];
        }
        v.clear();
        for(ll i = 0; i + 1 < n; i += 2) v.push_back(a[i + 1] - a[i]);
        ll extra = kadane();
        v.clear();
        for(ll i = 2; i < n; i += 2) v.push_back(a[i - 1] - a[i]);
        extra = max(extra, kadane());
        cout << evSum + extra << '\n';
    }
}