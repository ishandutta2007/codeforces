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
#define N 1010

string grid[N];
bool occR[N], occC[N], connR[N], connC[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(n) G(m)
    F(i, 0, n) cin >> grid[i];
    F(i, 0, n) {
        bool seen = false, done = false;
        F(j, 0, m) 
            if(grid[i][j] == '#') {
                occR[i] = occC[j] = true;
                if(done) EX(-1)
                seen = true;
            } else if(seen) done = true;
    }
    F(j, 0, m) {
        bool seen = false, done = false;
        F(i, 0, n) 
            if(grid[i][j] == '#') {
                if(done) EX(-1)
                seen = true;
            } else if(seen) done = true;
    }
    bool freeR = false, freeC = false;
    F(i, 0, n) F(j, 0, m) {
        if(!occR[i]) freeR = true;
        if(!occC[j]) freeC = true;
        if(i && grid[i][j] == '#' && grid[i - 1][j] == '#') connR[i - 1] = true;
        if(i && !occR[i] && !occR[i - 1]) connR[i - 1] = true;
        if(j && grid[i][j] == '#' && grid[i][j - 1] == '#') connC[j - 1] = true;
        if(j && !occC[j] && !occC[j - 1]) connC[j - 1] = true;
    }
    if(freeR != freeC) EX(-1)
    ll rCt = 0, cCt = 0;
    F(i, 0, n) if(occR[i] && (!i || !connR[i - 1])) rCt++;
    F(j, 0, m) if(occC[j] && (!j || !connC[j - 1])) cCt++;
    if(rCt != cCt) EX(-1)
    EX(rCt)
}