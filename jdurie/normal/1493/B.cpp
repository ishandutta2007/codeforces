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

ll refl[10] = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};

bool valid(ll h, ll m, ll ch, ll cm) {
    ll d1 = ch / 10, d2 = ch % 10;
    ll d3 = cm / 10, d4 = cm % 10;
    if(~refl[d1] && ~refl[d2] && ~refl[d3] && ~refl[d4]) {
        ll nm = 10 * refl[d2] + refl[d1];
        ll nh = 10 * refl[d4] + refl[d3];
        return nh < h && nm < m;
    } else return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(h) G(m)
        GS(s)
        ll ch = stoll(s.substr(0, 2)), cm = stoll(s.substr(3));
        while(!valid(h, m, ch, cm)) {
            cm++;
            if(cm == m) cm = 0, ch++;
            if(ch == h) ch = 0;
        }
        if(ch < 10) cout << '0';
        cout << ch << ":";
        if(cm < 10) cout << '0';
        cout << cm << '\n';
    }
}