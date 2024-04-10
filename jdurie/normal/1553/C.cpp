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
//#define N 100010

ll sc[2], rem[2];

ll kicks(ll m) {
    sc[0] = sc[1] = 0;
    rem[0] = rem[1] = 5;
    F(i, 0, 10) {
        sc[i & 1] += (m >> i) & 1;
        rem[i & 1]--;
        if(sc[0] > sc[1] + rem[1]) return i + 1;
        if(sc[1] > sc[0] + rem[0]) return i + 1;
    }
    return 10;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        GS(s)
        ll sub = 0, sup = 0;
        F(i, 0, 10) {
            if(s[i] - '0') sup |= (1 << i);
            if(s[i] == '1') sub |= (1 << i);
        }
        ll ans = 10;
        F(m, 0, 1024) if((m & sub) == sub && (m & sup) == m) ans = min(ans, kicks(m));
        cout << ans << '\n';
    }
}