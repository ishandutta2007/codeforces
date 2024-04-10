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

map<ll, ll> divs[N], ctm;
pl qs[N];
ll ans = 1;

ll inv(ll a, ll b = M) { return 1 < a ? b - inv(b % a, a) * b / a : 1; }
ll pw(ll a, ll p) { return p ? pw(a * a % M, p / 2) * (p & 1 ? a : 1) % M : 1; }

void addDivs(ll i, ll x) {
    for(ll j = 2; j * j <= x; ++j) if(!(x % j)) {
        ll ct = 0;
        while(!(x % j)) x /= j, ct++;
        divs[i][j] += ct;
    }
    if(x > 1) divs[i][x]++;
}

void subDivs(ll i, ll x) {
    for(ll j = 2; j * j <= x; ++j) if(!(x % j)) {
        ll ct = 0;
        while(!(x % j)) x /= j, ct++;
        divs[i][j] -= ct;
        if(divs[i][j] < ctm[j]) { ans = ans * pw(inv(j), ctm[j] - divs[i][j]) % M; ctm[j] = divs[i][j]; }
    }
    if(x > 1) divs[i][x]--;
    if(divs[i][x] < ctm[x]) { ans = ans * pw(inv(x), ctm[x] - divs[i][x]) % M; ctm[x] = divs[i][x]; }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(q)
    F(i, 0, n) { G(x) addDivs(i, x); }
    F(i, 0, q) cin >> qs[i].K >> qs[i].V, qs[i].K--, addDivs(qs[i].K, qs[i].V);
    ctm = divs[0];
    F(i, 1, n) {
        map<ll, ll> ct2;
        for(pl p : ctm) if(divs[i].count(p.K)) ct2[p.K] = min(p.V, divs[i][p.K]);
        ctm = ct2;
    }
    for(pl p : ctm) ans = ans * pw(p.K, p.V) % M;
    vector<ll> v = {ans};
    FD(i, q - 1, 0) subDivs(qs[i].K, qs[i].V), v.push_back(ans);
    reverse(A(v));
    for(ll x : v) cout << x << '\n';
}