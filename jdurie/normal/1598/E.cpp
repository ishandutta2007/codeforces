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
#define N 1010

ll v[2][N][N], nm[2 * N];
set<ll> s[2 * N];

ll c2(ll x) { return x * (x - 1) / 2; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(m) G(qs)
    F(i, 0, n) F(j, 0, m) {
        v[0][i][j] = ++nm[i - j + N];
        v[1][i][j] = ++nm[i - j + 1 + N];
    }
    ll ans = 0, sq = n * m;
    F(i, 0, 2 * N) s[i].insert(0), s[i].insert(nm[i] + 1), ans += c2(nm[i]);
    while(qs--) {
        G(x) G(y) x--; y--;
        F(z, 0, 2) {
            ll k = x - y + z + N;
            ll q = v[z][x][y];
            ll a = *--s[k].lower_bound(q);
            ll b = *s[k].upper_bound(q);
            if(s[k].count(q)) {
                ans -= c2(q - a - 1);
                ans -= c2(b - q - 1);
                s[k].erase(q);
                ans += c2(b - a - 1);
            } else {
                ans -= c2(b - a - 1);
                s[k].insert(q);
                ans += c2(q - a - 1);
                ans += c2(b - q - 1);
            }
        }
        if(s[x - y + N].count(v[0][x][y])) sq--; else sq++;
        cout << ans + sq << '\n';
    }
}