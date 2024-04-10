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

map<ll, pair<pl, ll>> dp;
map<string, pair<pl, ll>> mp;
ll n, m;
string s;

pair<pl, ll> r(ll i) {
    if(i > m) return {{0, 0}, -1};
    if(i == m) return {{0, 0}, 0};
    if(dp.count(i)) return dp[i];
    F(k, 2, 4) if(~r(i + k).V && mp.count(s.substr(i, k))) return dp[i] = mp[s.substr(i, k)];
    return dp[i] = {{0, 0}, -1};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        cin >> n >> m;
        F(i, 1, n + 1) {
            GS(t)
            F(k, 2, 4) F(j, 0, m - k + 1) mp[t.substr(j, k)] = {{j + 1, j + k}, i};
        }
        cin >> s;
        if(~r(0).V) {
            vector<pair<pl, ll>> ans;
            ll idx = 0;
            while(idx < m) {
                ans.push_back(r(idx));
                idx += r(idx).K.V - r(idx).K.K + 1;
            }
            cout << ans.size() << '\n';
            for(auto a : ans) cout << a.K.K << ' ' << a.K.V << ' ' << a.V << '\n';
        } else cout << "-1\n";
        dp.clear();
        mp.clear();
    }
}