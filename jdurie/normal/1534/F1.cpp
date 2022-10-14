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
#define N 500010

vector<ll> graph[N], rGraph[N], sccList[N], ord;
set<ll> sccGraph[N];
ll scc[N]; //sccs are 1-indexed
bool used[N];
vector<ll> verts[N];
string grid[N];
set<ll> cols[N];

void dfs1(ll i) {
    used[i] = true;
    for(ll j : graph[i]) if(!used[j]) dfs1(j);
    ord.push_back(i);
}

void dfs2(ll i, ll c) {
    scc[i] = c;
    sccList[c].push_back(i);
    for(ll j : rGraph[i]) if(!scc[j]) dfs2(j, c);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(m)
    F(i, 0, n) { cin >> grid[i]; F(j, 0, m) verts[i].push_back(0); }
    F(i, 0, m) { G(a) }
    ll cur = 1;
    F(i, 0, n) F(j, 0, m) if(grid[i][j] == '#') verts[i][j] = cur++, cols[j].insert(i);
    F(i, 0, n) F(j, 0, m) if(verts[i][j]) {
        if(i && verts[i - 1][j]) graph[verts[i][j]].push_back(verts[i - 1][j]);
        if(*cols[j].rbegin() > i) graph[verts[i][j]].push_back(verts[*cols[j].upper_bound(i)][j]);
        if(j && cols[j - 1].size() && *cols[j - 1].rbegin() >= i) graph[verts[i][j]].push_back(verts[*cols[j - 1].lower_bound(i)][j - 1]);
        if(cols[j + 1].size() && *cols[j + 1].rbegin() >= i) graph[verts[i][j]].push_back(verts[*cols[j + 1].lower_bound(i)][j + 1]);
    }
    F(i, 1, cur) for(ll j : graph[i]) rGraph[j].push_back(i);
    //F(i, 1, cur) cout << i << ' ' << graph[i] << '\n';
    //F(i, 0, n) F(j, 0, m) cout << verts[i][j] << " \n"[j == m - 1];
    F(i, 1, cur) if(!used[i]) dfs1(i);
    ll c = 1;
    reverse(ord.begin(), ord.end());
    for(ll i : ord) if(!scc[i]) dfs2(i, c++);
    //F(i, 1, cur) cout << scc[i] <<  ' ';
    //cout << '\n';
    F(i, 1, cur) for(ll j : graph[i]) if(scc[j] - scc[i]) sccGraph[scc[j]].insert(scc[i]);
    ll ans = 0;
    F(i, 1, c) if(!sccGraph[i].size()) ans++;
    //F(i, 1, c) cout << i << ' ' << sccGraph[i] << '\n';
    cout << ans << '\n';
}