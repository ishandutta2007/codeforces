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

ll p[N], x[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(m)
        map<ll, ll> tot, del;
        map<ll, vector<ll>> id;
        F(i, 0, n) {
            cin >> x[i] >> p[i];
            id[x[i]].push_back(i);
            del[x[i]] -= 2;
            del[x[i] - p[i]]++;
            del[x[i] + p[i]]++;
        }
        ll cur = -2e9, d = 0, q = 0;
        for(pl pp : del) {
            q = tot[pp.K] = q + (pp.K - cur) * d;
            d += pp.V; cur = pp.K;
        }
        vector<pl> totv;
        for(pl pp : tot) totv.push_back(pp);
        string ans(n, '1');
        ll mx = LLONG_MIN;
        for(pl pp : totv) {
            if(pp.V > m) mx = max(mx, pp.V - m - pp.K);
            for(ll i : id[pp.K]) if(p[i] - x[i] < mx) ans[i] = '0';
        }
        reverse(A(totv));
        mx = LLONG_MIN;
        for(pl pp : totv) {
            if(pp.V > m) mx = max(mx, pp.V - m + pp.K);
            for(ll i : id[pp.K]) if(p[i] + x[i] < mx) ans[i] = '0';
        }
        cout << ans << '\n';
    }    
}