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
#define N 200010

map<ll, pl> s;
ll a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) F(id, 1, n + 1) {
        G(k) ll sm = 0;
        F(i, 1, k + 1) cin >> a[i], sm += a[i];
        F(i, 1, k + 1)
            if(s.count(sm - a[i]) && s[sm - a[i]].K - id) { cout << "YES\n" << id << ' ' << i << '\n' << s[sm - a[i]].K << ' ' << s[sm - a[i]].V; exit(0); }
            else if(!s.count(sm - a[i])) s[sm - a[i]] = {id, i};
    }
    cout << "NO\n";
}