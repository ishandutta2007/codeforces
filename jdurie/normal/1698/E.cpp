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
#define M 998244353
#define N 200010

ll a[N], b[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(s)
        F(i, 0, n) cin >> a[i];
        F(i, 0, n) cin >> b[i];
        ll ans = 1;
        set<ll> avail;
        vector<ll> v;
        F(i, 1, n + 1) avail.insert(i);
        F(i, 0, n) if(~b[i]) {
            if(a[i] - b[i] > s) ans = 0;
            avail.erase(b[i]);
        } else v.push_back(a[i]);
        sort(A(v));
        ll ct = 0, vi = 0;
        for(ll x : avail) {
            while(vi < v.size() && v[vi] <= x + s) ct++, vi++;
            ans = (ans * ct--) % M;
        }
        cout << ans << '\n';
    }    
}