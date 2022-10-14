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
#define N 100010

map<ll, ll> doub, sing, lgt;
ll dSz, sSz, dSm, sSm, k;

void addD(ll x) { doub[x]++; dSz++; dSm += 2 * x; }
void remD(ll x) { doub[x]--; if(!doub[x]) doub.erase(x); dSz--; dSm -= 2 * x; }
void addS(ll x) { sing[x]++; sSz++; sSm += x; }
void remS(ll x) { sing[x]--; if(!sing[x]) sing.erase(x); sSz--; sSm -= x; }
void DtoS(ll x) { remD(x); addS(x); }
void StoD(ll x) { remS(x); addD(x); }
void addL(ll x) { lgt[x]++; k++; }
void remL(ll x) { lgt[x]--; if(!lgt[x]) lgt.erase(x); k--; }

ll curSum() {
    ll minL = k ? lgt.begin()->K : -1;
    ll maxS = sSz ? sing.rbegin()->K : 0;
    ll ans = dSm + sSm;
    if(~minL && !sing.count(minL)) ans += maxS - minL;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) while(n--) {
        G(tp) G(d)
        if(tp && d > 0) addL(d); else if(tp) remL(-d);
        ll minD = dSz ? doub.begin()->K : -1;
        if(dSz > k) DtoS(minD);
        ll maxS = sSz ? sing.rbegin()->K : -1;
        if(d > 0) {
            if(dSz < k) { if(d >= maxS) addD(d); else StoD(maxS), addS(d); }
            else if(k && d > minD) DtoS(minD), addD(d);
            else { addS(d); if(~maxS && ~minD && maxS > minD) StoD(maxS), DtoS(minD); }
        } else {
            if(sing.count(-d)) remS(-d);
            else { remD(-d); if(~maxS) StoD(maxS); }
        }
        cout << curSum() << '\n';
    }
}