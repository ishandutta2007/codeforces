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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) GS(s) GS(t)
    ll sCt = 0, tCt = 0;
    for(char c : s) if(c == '1') sCt++;
    for(char c : t) if(c == '1') tCt++;
    if(sCt != tCt) EX(-1)
    vector<pair<ll, char>> v;
    F(i, 0, n) if(s[i] != t[i]) {
        if(v.size() && s[i] == v.back().V) v.back().K++;
        else v.emplace_back(1, s[i]);
    }
    if(v.size() > 1 && v[0].V == v.back().V) {
        v[0].K += v.back().K;
        v.pop_back();
    }
    for(ll ops = 0;; ops++) {
        if(v.empty()) EX(ops)
        vector<pair<ll, char>> newV;
        for(pl p : v) if(p.K - 1) {
            if(newV.size() && p.V == newV.back().V) newV.back().K += p.K - 1;
            else newV.emplace_back(p.K - 1, p.V);
        }
        if(newV.size() > 1 && newV[0].V == newV.back().V) {
            newV[0].K += newV.back().K;
            newV.pop_back();
        }
        v = newV;
    }
}