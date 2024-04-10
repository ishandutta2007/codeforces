#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
typedef complex<ld> pt;

#define G(x) ll x; cin >> x;
#define GD(x) ld x; cin >> x;
#define GS(s) string s; cin >> s;
#define F(i, l, r) for(ll i = l; i < r; i++)
#define FD(i, r, l) for(ll i = r; i > l; i--)
#define PN(a, n) { cout << #a << ": { "; F(_, 0, n) cout << a[_] << " "; cout << "}" << endl; }
#define CE(a, x) lower_bound(a.begin(), a.end(), x)
#define UP(a, x) upper_bound(a.begin(), a.end(), x)
#define FL(a, x) (x < *a.begin() ? a.end() : --UP(a, x))
#define LO(a, x) (x <= *a.begin() ? a.end() : --CE(a, x))
#define MC(a, x) a.lower_bound(x)
#define MU(a, x) a.upper_bound(x)
#define MF(a, x) (x < (*a.begin()).K ? a.end() : --MU(a, x))
#define ML(a, x) (x <= (*a.begin()).K ? a.end() : --MC(a, x))
#define EX(x) { cout << x << endl; exit(0); }
#define K first
#define V second
#define X real()
#define Y imag()
#define M 1000000007 //998244353
#define N 200010

vector<ll> rev[N], graph[N];
vector<pl> q;
bool used[N];
ll path[N], d[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(n) G(m)
    while(m--) {
        G(u) G(v)
        rev[v].push_back(u);
        graph[u].push_back(v);
    }
    G(k)
    for(ll i = k - 1; i >= 0; i--) cin >> path[i];
    q.push_back({path[0], 0});
    for(ll i = 0; i < q.size(); i++) {
        if(!used[q[i].K]) {
            used[q[i].K] = true;
            d[q[i].K] = q[i].V;
            for(ll j : rev[q[i].K])
                if(!used[j]) q.push_back({j, q[i].V + 1});
        }
    }
    ll bigger = 0, same = 0;
    for(ll i = 1; i < k - 1; i++) {
        ll cEq = 0, cLess = 0;
        for(ll j : graph[path[i + 1]])
            if(d[j] == d[path[i]]) cEq++;
            else if(d[j] < d[path[i]]) cLess++;
        if(cLess) bigger++;
        else if(cEq > 1) same++;
    }
    cout << bigger << " " << bigger + same << endl;
}