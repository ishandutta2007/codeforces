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
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(x) (x).begin(), (x).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 1010

vector<ll> graph[N];
vector<pl> badEdges;
bool used[N];
ll c = 0, crep[N];
ll dep[N]; //make depth of root 1

void dfs(ll i, ll p, ll d) {
    used[i] = true;
    dep[i] = d;
    for(ll j : graph[i]) if(j - p) {
        if(!dep[j]) {
            dfs(j, i, d + 1);
        } else if(dep[j] < dep[i]) badEdges.emplace_back(i, j);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n)
    F(i, 0, n - 1) {
        G(u) G(v)
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    stringstream ans;
    F(i, 1, n + 1) if(!used[i]) {
        dfs(i, i, 1);
        crep[c++] = i;
    }
    cout << c - 1 << '\n';
    ll x = 0;
    for(pl p : badEdges) {
        cout << p.K << ' ' << p.V << ' ' << crep[x] << ' ' << crep[x + 1] << '\n';
        x++;
    }
}