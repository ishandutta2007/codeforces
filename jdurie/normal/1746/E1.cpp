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

bool ask(vector<ll> v) {
    cout << "? " << v.size() << ' ';
    for(ll x : v) cout << x << ' ';
    cout << endl;
    GS(res)
    return res[0] == 'Y';
}

#define RESET(x, y) { poss = x; for(ll i : y) poss.push_back(i); n = poss.size(); }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n)
    vector<ll> poss;
    F(i, 1, n + 1) poss.push_back(i);
    while(n > 2) {
        vector<ll> a, b, c;
        ll as = n / 3, bs = (n - as + 1) / 2;
        F(i, 0, as) a.push_back(poss[i]);
        F(i, as, as + bs) b.push_back(poss[i]);
        F(i, as + bs, n) c.push_back(poss[i]);
        if(!ask(a) && !ask(a)) RESET(b, c)
        else if(ask(b)) RESET(a, b)
        else RESET(a, c)
    }
    cout << "! " << poss[0] << endl;
    GS(res) if(res[1] == '(') { cout << "! " << poss[1] << endl; GS(res) }
}