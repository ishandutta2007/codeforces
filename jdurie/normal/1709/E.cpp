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
typedef ll T;

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

ll a[N], mid[N], pref[N], ans = 0;
vector<ll> tree[N];
map<ll, ll> mp[N];

void dfs(ll i, ll p) {
    mid[i] = i;
    for(ll j : tree[i]) if(j - p) {
        dfs(j, i);
        if(mp[mid[j]].size() >= mp[mid[i]].size()) mid[i] = mid[j];
    }
    pref[mid[i]] ^= a[i];
    for(ll j : tree[i]) if(j - p && mid[j] != mid[i]) {
        for(auto q : mp[mid[j]]) {
            if(mp[mid[i]].count(q.K ^ pref[mid[j]] ^ pref[mid[i]])) {
                mp[mid[i]].clear(); ans++;
                return;
            }
        }
        for(auto q : mp[mid[j]]) mp[mid[i]][q.K ^ pref[mid[j]] ^ a[i] ^ pref[mid[i]]] += q.V;
    }
    if(mp[mid[i]].count(pref[mid[i]])) {
        mp[mid[i]].clear(); ans++;
        return;
    }
    mp[mid[i]][a[i] ^ pref[mid[i]]]++;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n)
    F(i, 1, n + 1) cin >> a[i];
    F(i, 0, n - 1) {
        G(u) G(v)
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1, 1);
    cout << ans << '\n';
}