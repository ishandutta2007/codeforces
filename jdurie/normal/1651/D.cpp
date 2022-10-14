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

map<pl, ll> pts;
pl p[N], ans[N];
bool done[N];

ll dx[4] = {0, 0, -1, 1};
ll dy[4] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) F(i, 0, n) {
        cin >> p[i].K >> p[i].V;
        pts[p[i]] = i;
    }
    vector<pair<ll, pair<ll, pl>>> src;
    F(i, 0, n) F(k, 0, 4) {
        pl q = {p[i].K + dx[k], p[i].V + dy[k]};
        if(!pts.count(q)) { src.push_back({i, {1, q}}); break; }
    }
    F(i, 0, src.size()) if(!done[src[i].K]) {
        done[src[i].K] = true;
        ans[src[i].K] = src[i].V.V;
        src[i].V.K++;
        F(k, 0, 4) {
            pl q = {p[src[i].K].K + dx[k], p[src[i].K].V + dy[k]};
            if(pts.count(q)) src.push_back({pts[q], src[i].V});
        }
    }
    F(i, 0, n) cout << ans[i].K << ' ' << ans[i].V << '\n';
}