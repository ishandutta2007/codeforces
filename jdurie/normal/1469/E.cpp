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
#define N 1000010
#define L 20ll

ll nxt1[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(k) GS(s)
        F(i, 0, n) s[i] = '1' + '0' - s[i];
        nxt1[n] = -1;
        FD(i, n - 1, -1) nxt1[i] = s[i] == '1' ? i : nxt1[i + 1];
        set<ll> st;
        F(i, 0, n - k + 1) {
            if(!~nxt1[i]) st.insert(0ll);
            else if(nxt1[i] >= i + k - L) {
                ll v = 0;
                F(j, 0, min(k, L)) if(s[i + k - 1 - j] == '1') v |= (1 << j);
                st.insert(v);
            }
        }
        ll mex = 0;
        while(st.count(mex)) mex++;
        if(k < 30 && mex == (1ll << k)) cout << "NO\n";
        else {
            cout << "YES\n";
            F(i, 0, k - L) cout << 0;
            FD(i, min(L, k) - 1, -1) cout << ((mex >> i) & 1);
            cout << '\n';
        }
    }
}