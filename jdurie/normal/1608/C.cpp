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
#define N 100010

pair<pl, ll> p[N];
ll mx[N];
char ans[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) F(i, 0, n) cin >> p[i].K.K;
        F(i, 0, n) cin >> p[i].K.V, p[i].V = i;
        sort(p, p + n);
        mx[0] = p[0].K.V;
        F(i, 1, n) mx[i] = max(p[i].K.V, mx[i - 1]);
        ll b = 0, c = M;
        FD(i, n - 1, 0) {
            c = min(c, p[i].K.V);
            if(c > mx[i - 1]) {b = i; break;}
        }
        F(i, 0, b) ans[p[i].V] = '0';
        F(i, b, n) ans[p[i].V] = '1';
        F(i, 0, n) cout << ans[i];
        cout << '\n';
    }
}