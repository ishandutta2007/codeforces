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
#define F(i, l, r) for(ll i = l; i < r; i++)
#define FD(i, r, l) for(ll i = r; i > l; i--)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(x) (x).begin(), (x).end()
#define K first
#define V second
#define M 10000000000007 //998244353
#define N 100010

ll dist[26][26];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    GS(a) GS(b)
    F(i, 0, 26) F(j, 0, 26) dist[i][j] = M;
    F(i, 0, 26) dist[i][i] = 0;
    G(n) while(n--) {
        GS(s) GS(t) G(c)
        dist[s[0] - 'a'][t[0] - 'a'] = min(dist[s[0] - 'a'][t[0] - 'a'], c);
    }
    F(k, 0, 26) F(i, 0, 26) F(j, 0, 26) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    string cd = "";
    ll ans = 0;
    F(i, 0, a.size()) {
        ll mi = LLONG_MAX;
        char mc = 'a';
        F(c, 0, 26) {
            if(dist[a[i] - 'a'][c] + dist[b[i] - 'a'][c] < mi) {
                mc = c;
                mi = dist[a[i] - 'a'][c] + dist[b[i] - 'a'][c];
            }
        }
        cd += (char)(mc + 'a');
        ans += mi;
    }
    if(ans >= M || a.size() != b.size()) cout << -1 << '\n';
    else cout << ans << '\n' << cd << '\n';
}