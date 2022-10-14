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
#define M 998244353
#define N 1000010

ll r[N][2], c[N][2], t[2], p2[N];
map<pl, ll> val;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    p2[0] = 1;
    F(i, 1, N) p2[i] = 2 * p2[i - 1] % M;
    G(n) G(m) G(k)
    ll cR = 0, cC = 0;
    ll fR = n, fC = m;
    while(k--) {
        G(x) G(y) G(z) x--; y--;
        if(val.count({x, y})) {
            ll b = val[{x, y}] == ((x + y) & 1) ? 1 : 0;
            if(r[x][0] && r[x][1]) cR--;
            if(c[y][0] && c[y][1]) cC--;
            r[x][b]--; c[y][b]--; t[b]--;
            if(r[x][0] && r[x][1]) cR++;
            if(c[y][0] && c[y][1]) cC++;
            if(!r[x][0] && !r[x][1]) fR++;
            if(!c[y][0] && !c[y][1]) fC++;
            val.erase({x, y});
        }
        if(z >= 0) {
            val[{x, y}] = z;
            ll b = z == ((x + y) & 1) ? 1 : 0;
            r[x][b]++; c[y][b]++; t[b]++;
            if(r[x][b] == 1 && !r[x][b ^ 1]) fR--;
            if(c[y][b] == 1 && !c[y][b ^ 1]) fC--;
            if(r[x][b] == 1 && r[x][b ^ 1]) cR++;
            if(c[y][b] == 1 && c[y][b ^ 1]) cC++; 
        }
        ll ans = 0;
        if(!cR) ans = (ans + p2[fR]) % M;
        if(!cC) ans = (ans + p2[fC]) % M;
        if(!t[0]) ans = (ans + M - 1) % M;
        if(!t[1]) ans = (ans + M - 1) % M;
        cout << ans << '\n';
    }
}