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
#define N 12

ll ct[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        memset(ct, 0, sizeof ct);
        GS(s) reverse(A(s));
        F(i, 0, s.size()) ct[i] = s[i] - '0';
        ll ans = 0;
        F(mask, 0, (1 << N)) {
            if(mask & 3) continue;
            bool z = true, p = true;
            ll w = 1;
            F(i, 0, N) {
                ll val = ct[i];
                if((mask >> (i + 2)) & 1) val += 10;
                if((mask >> i) & 1) val--;
                if(val < 0 || val > 18) p = false; 
                if(val >= 10) z = false;
                ll f = 0;
                F(d, 0, 10) if(val >= d && val - d <= 9) f++;
                w *= f;
            }
            if(p) ans += z ? max(0ll, w - 2) : w;
        }
        cout << ans << '\n';
    }    
}