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
#define N 510

map<pl, vector<pl>> graph;
string gr[N];
ll ans[N][N];
ll dx[4] = {-1, 1, 0, 0};
ll dy[4] = {0, 0, 1, -1};

void dfs(ll i, ll j, ll z) {
    ans[i][j] = z;
    for(pl p : graph[{i, j}]) if(!ans[p.K][p.V]) dfs(p.K, p.V, 5 - z);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(m)
    F(i, 0, n) cin >> gr[i];
    F(i, 0, n) F(j, 0, m) if(gr[i][j] == 'X') {
        vector<pl> v;
        F(k, 0, 4) {
            ll i2 = i + dx[k], j2 = j + dy[k];
            if(gr[i2][j2] == '.') v.emplace_back(i2, j2);
        }
        if(v.size() & 1) EX("NO")
        else if(v.size() == 2) graph[v[0]].push_back(v[1]), graph[v[1]].push_back(v[0]);
        else if(v.size() == 4) {
            graph[{i - 1, j}].push_back({i, j - 1}), graph[{i, j - 1}].push_back({i - 1, j});
            graph[{i + 1, j}].push_back({i, j + 1}), graph[{i, j + 1}].push_back({i + 1, j});
        }
    }
    F(i, 0, n) F(j, 0, m) if(gr[i][j] == '.' && !ans[i][j]) dfs(i, j, 1);
    F(i, 0, n) F(j, 0, m) if(gr[i][j] == 'X') {
        F(k, 0, 4) {
            ll i2 = i + dx[k], j2 = j + dy[k];
            if(gr[i2][j2] == '.') ans[i][j] += ans[i2][j2];
        }
        if(ans[i][j] % 5) EX("NO")
    }
    cout << "YES\n";
    F(i, 0, n) { F(j, 0, m) cout << ans[i][j] << ' '; cout << '\n'; }
}