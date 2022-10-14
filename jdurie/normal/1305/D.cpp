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
#define EX(x) { cout << "! " << x << endl; exit(0); }
#define K first
#define V second
#define M 1000000007 //998244353
#define N 100010
#define ASK(a, b) cout << "? " << a << " " << b << endl; G(res)

vector<ll> tree[N];
bool used[N];
ll sz[N], unused;

pl deep(ll i, ll p) {
    pl best = {-1, -1};
    for(ll j : tree[i]) if(!used[j] && j - p) {
        pl ch = deep(j, i);
        if(ch.V + 1 > best.V) best = {ch.K, ch.V + 1};
    }
    if(best.K == -1) return {i, 0};
    return best;
}

void dfsFill(ll i, ll x) {
    used[i] = true;
    unused--;
    for(ll j : tree[i]) if(j - x && !used[j]) dfsFill(j, x); 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(n)
    F(i, 0, n - 1) {
        G(u) G(v)
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    unused = n;
    while(unused > 1) {
        F(i, 1, n + 1) if(!used[i]) { 
            ll v1 = deep(i, -1).K;
            ll v2 = deep(v1, -1).K;
            ASK(v1, v2)
            if(res == v1) EX(v1)
            else if(res == v2) EX(v2) 
            dfsFill(v1, res);
            dfsFill(v2, res);
            break;
        }
    }
    F(i, 1, n + 1) if(!used[i]) EX(i)
}