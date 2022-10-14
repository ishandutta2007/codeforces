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
//#define N 200010

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(fb) G(db) G(nb)
        G(fc) G(dc) G(nc)
        ll lb = fb + (nb - 1) * db;
        ll lc = fc + (nc - 1) * dc;
        if(dc % db || abs(fc - fb) % db || fc < fb || lc > lb) cout << "0\n";
        else if(fc - dc < fb || lc + dc > lb) cout << "-1\n";
        else {
            ll ans = 0;
            for(ll g = 1; g * g <= db; ++g) if(!(db % g)) {
                if(!((dc * g) % db)) {
                    ll da = dc * g / db;
                    if(__gcd(da, db) == g) ans = (ans + db / g * db / g) % M;
                }
                if(g - db / g && !((dc * db / g) % db)) {
                    ll da = dc * db / g / db;
                    if(__gcd(da, db) == db / g) ans = (ans + g * g) % M;
                }
            }
            cout << ans << '\n';
        }
    }
}