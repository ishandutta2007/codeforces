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

ll s[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(m)
        set<pl> st;
        ll mv = M;
        F(i, 0, n) { cin >> s[i]; if(s[i] < mv) st.insert({i, s[i]}), mv = s[i]; }
        while(m--) {
            G(k) G(d) s[--k] -= d;
            if((--st.upper_bound({k, M}))->V > s[k]) {
                while(st.size() && st.rbegin()->K >= k) {
                    pl p = *st.lower_bound({k, -1});
                    if(p.V >= s[k]) st.erase(p);
                    else break;
                }
                st.insert({k, s[k]});
            }
            cout << st.size() << ' ';
        }
        cout << '\n';
    }
}