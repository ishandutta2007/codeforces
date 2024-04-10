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
#define M 998244353
#define N 110

ll dp[N][N], ncr[N][N], f[N];
bool good[N][N], used[N], q, cont[N];
ll x[N], y[N], num, mnd;
vector<ll> sz, graph[N];

#define D(i, j) (abs(x[i] - x[j]) + abs(y[i] - y[j]))

void dfs(ll i) {
    if(cont[i]) q = true;
    num++; used[i] = true; mnd = min(mnd, (ll)graph[i].size());
    for(ll j : graph[i]) if(!used[j]) dfs(j);
}

#define DP dp[i][k]
ll r(ll i, ll k) {
    if(i < 0) return 1;
    if(~DP) return DP;
    if(sz[i] == 1) return DP = k * r(i - 1, k - 1) % M;
    return DP = (k * r(i - 1, k - 1) + ncr[k][sz[i]] * f[sz[i]] % M * r(i - 1, k - sz[i])) % M;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    f[0] = 1;
    F(i, 1, N) f[i] = i * f[i - 1] % M;
    memset(dp, -1, sizeof dp);
    F(i, 0, N) {
        ncr[i][0] = 1;
        F(j, 1, i + 1) ncr[i][j] = (ncr[i - 1][j] + ncr[i - 1][j - 1]) % M;
    }
    G(n)
    F(i, 0, n) cin >> x[i] >> y[i];
    F(i, 0, n) {
        ll md = LLONG_MAX;
        F(j, 0, n) if(j - i) md = min(md, D(i, j));
        F(j, 0, n) if(j - i && D(i, j) == md) good[i][j] = true;
    }
    F(i, 0, n) F(j, 0, n) if(good[i][j] && !good[j][i]) cont[i] = true;
    F(i, 0, n) F(j, 0, n) if(good[i][j] && good[j][i]) graph[i].push_back(j);
    F(i, 0, n) if(!used[i]) {
        num = 0, mnd = LLONG_MAX, q = false; dfs(i);
        if(q || mnd < num - 1) while(num--) sz.push_back(1); else sz.push_back(num);
    }
    cout << r(sz.size() - 1, n) << '\n';
}