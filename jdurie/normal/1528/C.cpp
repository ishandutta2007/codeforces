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

set<pl> cur;
ll tin[N], tout[N], ans = 0, cans = 0;
vector<ll> chil1[N], chil2[N];

ll tdfs(ll i, ll t) {
    tin[i] = tout[i] = t;
    for(ll j : chil2[i])
        tout[i] = tdfs(j, tout[i] + 1) + 1;
    return tout[i];
}

void dfs(ll i) {
    cur.insert({tin[i], i});
    cur.insert({tout[i], i});
    ll prev = cur.begin()->K == tin[i] ? -1 : (--cur.lower_bound({tin[i], i}))->V;
    ll nxt = cur.rbegin()->K == tout[i] ? -2 : cur.upper_bound({tout[i], i})->V;
    if(prev - nxt) cans++;
    ans = max(ans, cans);
    for(ll j : chil1[i]) dfs(j);
    if(prev - nxt) cans--;
    cur.erase({tin[i], i});
    cur.erase({tout[i], i});
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n)
        F(i, 2, n + 1) { G(j) chil1[j].push_back(i); }
        F(i, 2, n + 1) { G(j) chil2[j].push_back(i); }
        tdfs(1, 0);
        dfs(1);
        cout << ans << '\n';
        ans = cans = 0;
        cur.clear();
        F(i, 1, n + 1) chil1[i].clear(), chil2[i].clear();
    }
}