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
#define N 100010

ll a[N], ct[N], md[N], q[N];
pl x[N];

void inc(ll i, ll v, ll t) {
    if(md[i] == t) ct[i] = v, md[i] = t;
    else ct[i] += v;
} 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) F(i, 0, n) cin >> a[i];
        x[0] = {a[n - 1], 1}; ll z = 1;
        ll ans = 0;
        FD(i, n - 2, -1) {
            F(j, 0, z) {
                ll sg = (a[i] + x[j].K - 1) / x[j].K;
                ans = (ans + x[j].V * (i + 1) % M * (sg - 1)) % M;
                inc(a[i] / sg, x[j].V, i);
                q[j] = a[i] / sg;
            }
            inc(a[i], 1, i);
            q[z] = a[i];
            ll nz = 0;
            F(j, 0, z + 1) if(ct[q[j]]) {
                x[nz++] = {q[j], ct[q[j]]};
                ct[q[j]] = 0;
            }
            z = nz;
        }
        cout << ans << '\n';
    }
}