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

vector<ll> tree[N];
ll s[N], dp[N][2], sm[N];

void dpdfs(ll i, ll k) {
    sm[i] = k;
    for(ll j : tree[i]) dpdfs(j, k / tree[i].size());
}

#define DP dp[i][b]
ll r(ll i, ll b) {
    if(~DP) return DP;
    ll k = sm[i] + b;
    DP = k * s[i];
    multiset<ll> diff;
    for(ll j : tree[i]) {
        diff.insert(r(j, 1) - r(j, 0));
        DP += r(j, k / tree[i].size() > sm[j]);
    }
    if(tree[i].size()) F(q, 0, k % tree[i].size()) { DP += *diff.rbegin(); diff.erase(diff.find(*diff.rbegin())); }
    return DP;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(k)
        F(i, 1, n + 1) dp[i][0] = dp[i][1] = -1;
        F(i, 2, n + 1) { G(p) tree[p].push_back(i); }
        F(i, 1, n + 1) cin >> s[i];
        dpdfs(1, k);
        cout << r(1, 0) << '\n';
        F(i, 1, n + 1) tree[i].clear();
    }
}