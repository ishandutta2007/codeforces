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

typedef int ll;
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
//#define N 100010

#define EPS 1e-12

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        GD(c) GD(m) GD(p) GD(v)
        ld ans = 0;
        F(l, 0, 20) F(msk, 0, (1 << l)) {
            ld a = c, b = m, x = p, q = 1;
            bool bA = false, bB = false, z = false;
            F(j, 0, l)
                if((msk >> j) & 1) {
                    if(bA) z = true;
                    q *= a;
                    ld del = v;
                    if(a <= v + EPS) { bA = true, del = a; }
                    a -= del;
                    if(bB) x += del; else x += del / 2, b += del / 2;
                } else {
                    if(bB) z = true;
                    q *= b;
                    ld del = v;
                    if(b <= v + EPS) { bB = true; del = b; }
                    b -= del;
                    if(bA) x += del; else x += del / 2, a += del / 2;
                }
            q *= x;
            if(!z) ans += q * (l + 1);
        }
        cout << fixed << setprecision(12) << ans << '\n';
    }
}