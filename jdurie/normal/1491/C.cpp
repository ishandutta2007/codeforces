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
#define N 5010

ll s[N], par[N];
ll dsu(ll i) { return par[i] == i ? i : par[i] = dsu(par[i]); }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) ll ans = 0;
        F(i, 0, n) cin >> s[i];
        iota(par, par + n + 1, 0);
        F(i, 0, n) {
            if(i + s[i] > n) ans += i + s[i] - n, s[i] = n - i;
            while(s[i] > 1) {
                ll j = i;
                while(j < n) {
                    ll tmp = s[j];
                    if(s[j] - 1) s[j]--;
                    else par[dsu(j)] = dsu(j + 1);
                    j += tmp; if(j <= n) j = par[j];
                }
                ans++;
            }
        }
        cout << ans << '\n';
    }
}