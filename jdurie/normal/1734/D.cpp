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
#define EX(x) { cout << x << '\n'; break; }
#define A(a) (a).begin(), (a).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 200010

ll a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(k) k--;
        F(i, 0, n) cin >> a[i];
        vector<pl> vl = {{0, 0}}, vr = {{0, 0}};
        F(i, k + 1, n) {
            if(vr.back().V > 0) vr.push_back({0, 0});
            vr.back().V += a[i];
            vr.back().K = min(vr.back().K, vr.back().V);
        }
        FD(i, k - 1, -1) {
            if(vl.back().V > 0) vl.push_back({0, 0});
            vl.back().V += a[i];
            vl.back().K = min(vl.back().K, vl.back().V);
        }
        ll il = 0, ir = 0, cur = a[k];
        while(1) {
            if(il == vl.size() || ir == vr.size()) EX("YES")
            else if(cur + vl[il].K >= 0) cur += vl[il++].V;
            else if(cur + vr[ir].K >= 0) cur += vr[ir++].V;
            else EX("NO")
        }
    }
}