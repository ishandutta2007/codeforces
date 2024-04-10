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
//#define N 100010

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        vector<ll> v1, v2, w1, w2;
        G(n) F(i, 0, n) {
            G(x)
            if(i & 1) v1.push_back(i);
            else v2.push_back(i);
            if(x & 1) w1.push_back(i);
            else w2.push_back(i);
        }
        ll ans = LLONG_MAX;
        if(v1.size() == w1.size()) {
            ll temp = 0;
            F(i, 0, v1.size()) temp += abs(v1[i] - w1[i]);
            F(i, 0, v2.size()) temp += abs(v2[i] - w2[i]);
            ans = min(ans, temp / 2);
        }
        if(v1.size() == w2.size()) {
            ll temp = 0;
            F(i, 0, v1.size()) temp += abs(v1[i] - w2[i]);
            F(i, 0, v2.size()) temp += abs(v2[i] - w1[i]);
            ans = min(ans, temp / 2);
        }
        cout << (ans == LLONG_MAX ? -1 : ans) << '\n';
    }
}