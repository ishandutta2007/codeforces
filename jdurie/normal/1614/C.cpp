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
#define N 200010
#define NCR(n, r) (f[n] * fi[r] % M * fi[(n) - (r)] % M)

pair<pl, bool> ev[2 * N];
ll f[N], fi[N], p2[N];

ll inv(ll a, ll b = M) { return 1 < a ? b - inv(b % a, a) * b / a : 1; } //inv a mod b

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    f[0] = fi[0] = p2[0] = 1;
    F(i, 1, N) f[i] = i * f[i - 1] % M, fi[i] = inv(f[i]);
    F(i, 1, N) p2[i] = 2 * p2[i - 1] % M;
    G(tc) while(tc--) {
        G(n) G(m)
        for(ll i = 0; i < 2 * m; i += 2) {
            cin >> ev[i].K.K >> ev[i + 1].K.K >> ev[i].K.V;
            ev[i].V = true; ev[i + 1].V = false;
            ev[i + 1].K.K++;
            ev[i + 1].K.V = ev[i].K.V;
        }
        sort(ev, ev + 2 * m);
        ll ans = 0;
        F(j, 0, 30) {
            ll cr = 0, ct = 0, tot = 0;
            F(i, 1, n + 1) {
                while(ev[cr].K.K <= i) {
                    if(!((ev[cr].K.V >> j) & 1)) {
                        if(ev[cr].V) ct++; else ct--; 
                    }
                    cr++;
                }
                if(!ct) tot++;
            }
            for(ll i = 1; i <= tot; i += 2)
                ans = (ans + NCR(tot, i) * p2[n - tot] % M * p2[j] % M) % M;
        }
        cout << ans << '\n';
    }
}