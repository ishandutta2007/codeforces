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
#define N 1000010
#define L 21

ll a[N], xr[N], id[N][2];
vector<ll> p[N][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) F(i, 1, n + 1)
        cin >> a[i], xr[i] = a[i] ^ xr[i - 1];
    ll ans = 0;
    F(j, 0, L) {
        F(i, 0, N) {
            p[i][0].clear(), p[i][1].clear();
            id[i][0] = id[i][1] = 0;
        }
        p[0][0].push_back(1);
        ll cur = 0;
        F(i, 1, n + 1) {
            ll k = xr[i] >> (j + 1);
            ll z = (i & 1);
            if((a[i] >> j) & 1) cur++;
            else cur = 0;
            while(id[k][z] < p[k][z].size() && p[k][z][id[k][z]] < i - cur + 1) id[k][z]++;
            if(id[k][z] < p[k][z].size()) ans = max(ans, i - p[k][z][id[k][z]] + 1);
            p[k][z].push_back(i + 1);
        }
    }
    cout << ans << '\n';
}