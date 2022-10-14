//Codeforces Template
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
#define N 500010

bool used[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    set<ll> tm;
    set<pl> cst;
    ll cust = 1;
    G(q) F(i, 1, q + 1) {
        G(t)
        if(t == 1) {
            G(m)
            cst.insert({-m, cust});
            tm.insert(cust++);
        } else if(t == 2) {
            while(used[*tm.begin()]) tm.erase(tm.begin());
            ll j = *tm.begin();
            cout << j << ' ';
            used[j] = true;
        } else {
            while(used[cst.begin()->V]) cst.erase(cst.begin());
            ll j = cst.begin()->V;
            cout << j << ' ';
            used[j] = true;
        }
    }
    cout << '\n';
}