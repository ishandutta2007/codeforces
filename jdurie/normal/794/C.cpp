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
    GS(s) GS(t)
    string ans = s;
    sort(A(s)); sort(A(t));
    reverse(A(t));
    ll n = s.size();
    ll is = 0, it = 0;
    ll is2 = (n - 1) / 2, it2 = (n - 2) / 2;
    ll f = 0, l = n - 1;
    F(i, 0, n)
        if(i & 1) {
            if(s[is] >= t[it]) ans[l--] = t[it2--];
            else ans[f++] = t[it++];
        } else {
            if(s[is] >= t[it]) ans[l--] = s[is2--];
            else ans[f++] = s[is++];
        }
    EX(ans)
}