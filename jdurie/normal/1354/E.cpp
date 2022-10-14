#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
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
#define F(i, l, r) for(ll i = l; i < r; i++)
#define FD(i, r, l) for(ll i = r; i > l; i--)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}" << endl; }
#define EX(x) { cout << x << endl; exit(0); }
#define K first
#define V second
#define M 1000000007 //998244353
#define N 5010

vector<ll> graph[N];
ll n1, n2, n3;
ll col[N], comp[N], sz[2][N], comps = 0;
ll dp[N][N], ans[N];

void color(ll i, ll c) {
    col[i] = c;
    sz[c - 1][comps]++;
    for(ll j : graph[i]) 
        if(!col[j]) color(j, 3 - c);
        else if(col[j] == c) EX("NO")
}

ll r(ll i, ll s) {
    if(i == -1) return s == 0;
    if(s < 0) return dp[i][s] = 0;
    if(dp[i][s] != -1) return dp[i][s];
    if(r(i - 1, s - sz[0][i])) return dp[i][s] = 1;
    if(r(i - 1, s - sz[1][i])) return dp[i][s] = 2;
    return dp[i][s] = 0;
}

void dfs(ll i, ll c2) {
    if(col[i] == c2) ans[i] = 2;
    else if(n1) { n1--; ans[i] = 1; }
    else ans[i] = 3;
    col[i] = 0;
    for(ll j : graph[i]) if(col[j]) dfs(j, c2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(n) G(m)
    cin >> n1 >> n2 >> n3;
    while(m--) {
        G(u) G(v)
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    F(i, 1, n + 1) if(!col[i]) { comp[comps] = i; color(i, 1); comps++; }
    F(i, 0, N) F(j, 0, N) dp[i][j] = -1;
    if(!r(comps - 1, n2)) EX("NO")
    for(ll i = comps - 1; i >= 0; i--) {
        ll c = dp[i][n2];
        dfs(comp[i], c);
        n2 -= sz[c - 1][i];
    }
    cout << "YES\n";
    F(i, 1, n + 1) cout << ans[i];
    cout << '\n';
}