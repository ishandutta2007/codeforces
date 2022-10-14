//Codeforces Template
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
#define N 400010

vector<ll> graph[N], back[N], tree[N];
ll dep[N], par[N];

void dfs(ll i, ll p) {
    par[i] = p;
    dep[i] = dep[p] + 1;
    for(ll j : graph[i]) if(j - p) {
        if(!dep[j]) {
            tree[i].push_back(j);
            dfs(j, i);
        } else if(dep[j] < dep[i])
            back[i].push_back(j);
    }
}

bool up[N], secup[N];
ll mindep[N];
string ok;

ll sortedges(ll i) {
    mindep[i] = N;
    for(ll j : back[i]) mindep[i] = min(mindep[i], dep[j]);
    for(ll j : tree[i]) mindep[i] = min(mindep[i], sortedges(j));
    sort(A(tree[i]), [](ll j, ll k) { return mindep[j] < mindep[k]; });
    return mindep[i];
}

void chain(ll i, ll c);

void makechain(ll i, ll j, ll c) {
    if(ok[0] == 'N') return;
    for(ll c2 = i; c2 - c; c2 = par[c2])
        up[c2] = secup[c2] = !secup[j];
    secup[c] = !secup[j];
    for(ll lst = -1, c2 = i; c2 - c; lst = c2, c2 = par[c2])
        for(ll x : tree[c2]) if(x - lst) chain(x, c2);
}

void chain(ll i, ll c) {
    if(ok[0] == 'N') return;
    for(ll j : back[i]) if(dep[j] < dep[c]) { makechain(i, j, c); return; }
    if(tree[i].empty()) ok = "No\n";
    else chain(tree[i][0], c);
}

void printback(ll i) {
    secup[par[i]] = up[i];
    for(ll j : back[i]) {
        if(secup[j]) cout << i << ' ' << j << '\n';
        else cout << j << ' ' << i << '\n';
    }
    for(ll j : tree[i]) printback(j);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    secup[N - 1] = true;
    G(tc) while(tc--) {
        G(n) G(m) G(s) G(t)
        ok = "Yes\n";
        while(m--) {
            G(u) G(v)
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(s, s);
        sortedges(s);
        if(tree[s].size() - 1) ok = "No\n";
        makechain(t, N - 1, s);
        cout << ok;
        if(ok[0] == 'Y') {
            F(i, 1, n + 1) if(i - s) {
                if(up[i]) cout << i << ' ' << par[i] << '\n';
                else cout << par[i] << ' ' << i << '\n';
            }
            printback(s);
        }
        F(i, 1, n + 1) graph[i].clear(), back[i].clear(), tree[i].clear();
        fill_n(dep, n + 1, 0);
    }
}

/*
1
14 22 1 4
1 2
2 3
3 4
4 5
4 6
2 7
7 8
8 9
9 10
3 11
11 12
12 13
10 14
8 1
10 8
10 7
14 9
13 2
12 2
11 2
5 3
6 2
*/