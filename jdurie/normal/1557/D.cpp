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
#define N 300010

ll ii[N], l[N], r[N], dp[N], q[N];
vector<ll> nxt[N];
vector<pair<ll, pl>> eee;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(q, -1, sizeof q);
    G(n) G(m)
    set<ll> cur;
    vector<pair<pl, ll>> v;
    F(i, 0, m) { G(a) G(b) G(c) eee.emplace_back(a, pl{b, c}); }
    sort(A(eee));
    F(i, 0, m) {
        ii[i] = eee[i].K;
        l[i] = eee[i].V.K;
        r[i] = eee[i].V.V;
        v.emplace_back(pl{l[i], r[i]}, i);
    }
    sort(A(v));
    set<pl> rs;
    for(auto a : v) {
        ll lx = a.K.K, rx = a.K.V, i = a.V;
        while(rs.size() && rs.begin()->K < lx) {
            ll j = rs.begin()->V;
            cur.erase(j);
            if(cur.size() && *cur.begin() < j && *cur.rbegin() > j) {
                ll k1 = *--cur.upper_bound(j);
                ll k2 = *cur.upper_bound(j);
                nxt[ii[k1]].push_back(ii[k2]);
            }
            rs.erase(rs.begin());
        }
        if(cur.size() && *cur.begin() < i) {
            ll j = *--cur.upper_bound(i);
            nxt[ii[j]].push_back(ii[i]);
        }
        if(cur.size() && *cur.rbegin() > i) {
            ll j = *cur.upper_bound(i);
            nxt[ii[i]].push_back(ii[j]);
        }
        cur.insert(i);
        rs.insert({rx, i});
    }
    ll ans = 0, iii = -1;
    FD(i, n, 0) {
        dp[i] = 1;
        for(ll j : nxt[i]) if(i - j && 1 + dp[j] > dp[i]) {
            dp[i] = 1 + dp[j];
            q[i] = j;
        }
        if(dp[i] > ans) ans = dp[i], iii = i;
    }
    set<ll> s;
    while(~iii) s.insert(iii), iii = q[iii];
    cout << n - ans << '\n';
    F(i, 1, n + 1) if(!s.count(i)) cout << i << ' ';
    cout << '\n';
}