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
//#define N 200010

ll pw(ll a, ll p) { return p ? pw(a * a % M, p / 2) * (p & 1 ? a : 1) % M : 1; }

ll inv(ll a, ll b = M) { return 1 < a ? b - inv(b % a, a) * b / a : 1; } //inv a mod b

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(m) G(rb) G(cb) G(rd) G(cd) G(p)
        ll dr = 1, dc = 1, t = 0, s1 = 0, s2 = 0, k = 0;
        set<pair<pl, pl>> seen;
        p = p * inv(100) % M; ll q = (M + 1 - p) % M;
        while(1) {
            if(rb + dr < 1 || rb + dr > n) dr *= -1;
            if(cb + dc < 1 || cb + dc > m) dc *= -1;
            if(seen.count({{rb, cb}, {dr, dc}})) break;
            if(rb == rd || cb == cd) {
                s1 = (s1 + pw(q, k) * p % M * t % M) % M;
                s2 = (s2 + pw(q, k) * p % M) % M;
                k++;
            }
            seen.insert({{rb, cb}, {dr, dc}});
            t++; rb += dr, cb += dc;
        }
        ll z = pw(q, k), d = inv((M + 1 - z) % M);
        cout << (s1 * d % M + s2 * t % M * z % M * d % M * d % M) % M << '\n';
    }
}