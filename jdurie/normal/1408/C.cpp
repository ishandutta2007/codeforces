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

vector<ld> fwd, rev;
ll n; ld l;

bool works(ld m) {
    ld pos0 = 0, v = 1, rem = m;
    for(ld x : fwd) {
        if((x - pos0) / v <= rem) {
            rem -= (x - pos0) / v;
            v++;
            pos0 = x;
        } else break;
    }
    pos0 += rem * v;
    ld pos1 = l; v = 1; rem = m;
    for(ld x : rev) {
        if((pos1 - x) / v <= rem) {
            rem -= (pos1 - x) / v;
            v++;
            pos1 = x;
        } else break;
    }
    pos1 -= rem * v;
    return pos0 < pos1;
}

ld bSearch(ld lll, ld r) {
    if(r - lll < 0.000000001) return r;
    ld m = (lll + r) / 2;
    return works(m) ? bSearch(m, r) : bSearch(lll, m);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        fwd.clear(), rev.clear();
        cin >> n >> l;
        F(i, 0, n) { G(x) fwd.push_back(x); }
        F(i, 0, n) rev.push_back(fwd[n - 1 - i]);
        cout << fixed << setprecision(10) << bSearch(0, 10000000000000000000.) << '\n';
    }    
}