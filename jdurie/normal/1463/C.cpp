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
#define N 100010

ll pi[N], ti[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) F(i, 0, n) cin >> ti[i] >> pi[i];
        ti[n] = LLONG_MAX;
        ll ans = 0, t = 0, p = 0, nT = 0, nP = 0;
        F(i, 0, n) {
            if(ti[i] < nT) {
                ll tTR = (pi[i] > p) == (nP > p) && abs(pi[i] - p) <= abs(nP - p) ? t + abs(pi[i] - p) : -1;
                if(tTR >= ti[i] && tTR <= ti[i + 1]) ans++;
            } else {
                nT = ti[i] + abs(nP - pi[i]);
                if(nT <= ti[i + 1]) ans++;
                p = nP;
                nP = pi[i];
                t = ti[i];
            }
        }
        cout << ans << '\n';
    }    
}