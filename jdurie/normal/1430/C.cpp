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
#define F(i, l, r) for(ll i = l; i < (r); i++)
#define FD(i, r, l) for(ll i = r; i > (l); i--)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(a) (a).begin(), (a).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 100010

vector<ll> o, e;
vector<pl> ops;

void addOp(bool o1, bool o2) {
    ll a, b;
    if(o1) a = o.back(), o.pop_back(); else a = e.back(), e.pop_back();
    if(o2) b = o.back(), o.pop_back(); else b = e.back(), e.pop_back();
    ops.emplace_back(a, b);
    ll c = (a + b + 1) / 2;
    if(c & 1) o.push_back(c); else e.push_back(c);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n)
        o.clear(), e.clear(), ops.clear();
        F(i, 1, n + 1) if(i & 1) o.push_back(i); else e.push_back(i);
        F(i, 0, n - 1) {
            if(o.size() == 1 && e.size() == 1)
                addOp(true, false);
            else if(e.size() < 2 || (o.size() >= 2 && o.back() >= e.back())) 
                addOp(true, true);
            else addOp(false, false);
        }
        cout << (o.size() ? o[0] : e[0]) << '\n';
        for(pl p : ops) cout << p.K << ' ' << p.V << '\n';
    }
}