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
#define N 100010

ll a[N];
ll b[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) F(i, 1, n + 1) cin >> a[i];
    vector<ll> need;
    fill(b + 1, b + n + 1, 1000000);
    F(i, 1, n + 1) if(a[i] > a[i - 1]) {
        b[i] = a[i - 1];
        F(j, a[i - 1] + 1, a[i]) need.push_back(j);
    }
    ll idx = 0;
    F(i, 1, n + 1) if(b[i] == 1000000 && idx < need.size()) b[i] = need[idx++];
    ll mex = 0;
    set<ll> s;
    F(i, 1, n + 1) {
        s.insert(b[i]);
        while(s.count(mex)) mex++;
        if(mex != a[i]) EX(-1)
    }
    F(i, 1, n + 1) cout << b[i] << ' ';
    cout << '\n';
}