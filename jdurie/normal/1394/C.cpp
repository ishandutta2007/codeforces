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
#define N 300010

pl pts[N];
ll n;

bool ok(ll a, ll b) { return a >= 0 && b >= 0 && (a + b > 0); }

pl works(ll m) {
    ll minK = -M, maxK = M, minV = -M, maxV = M;
    ll minQ = -M, maxQ = M;
    F(i, 0, n) {
        if(minK > pts[i].K + m || maxK < pts[i].K - m ||
           minV > pts[i].V + m || maxV < pts[i].V - m) return {M, M};
        if(minQ > pts[i].K - pts[i].V + m || maxQ < pts[i].K - pts[i].V - m) return {M, M};
        minK = max(minK, pts[i].K - m);
        maxK = min(maxK, pts[i].K + m);
        minV = max(minV, pts[i].V - m);
        maxV = min(maxV, pts[i].V + m);
        minQ = max(minQ, pts[i].K - pts[i].V - m);
        maxQ = min(maxQ, pts[i].K - pts[i].V + m);
    }
    if(maxK - maxV >= minQ && maxK - maxV <= maxQ && ok(maxK, maxV)) return {maxK, maxV};
    ll tempK = maxV + maxQ;
    if(tempK >= minK && tempK <= maxK && ok(tempK, maxV)) return {tempK, maxV};
    tempK = maxV + minQ;
    if(tempK >= minK && tempK <= maxK && ok(tempK, maxV)) return {tempK, maxV};
    ll tempV = maxK - maxQ;
    if(tempV >= minV && tempV <= maxV && ok(maxK, tempV)) return {maxK, tempV};
    tempV = maxK - minQ;
    if(tempV >= minV && tempV <= maxV && ok(maxK, tempV)) return {maxK, tempV};
    return {M, M};
}

ll bSearch(ll l, ll r) {
    if(l == r) return l;
    ll m = (l + r) / 2;
    return works(m).K != M ? bSearch(l, m) : bSearch(m + 1, r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    F(i, 0, n) {
        GS(s)
        for(char c : s) if(c == 'B') pts[i].K++; else pts[i].V++;
    }
    ll ans = bSearch(0, M);
    pl p = works(ans);
    cout << ans << '\n';
    F(i, 0, p.K) cout << 'B';
    F(i, 0, p.V) cout << 'N';
    cout << '\n';
}