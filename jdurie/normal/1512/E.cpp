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
#define N 100010
#define TRI(x) ((x) * ((x) - 1) / 2)

ll p[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(l) G(r) G(s) l--;
        ll mx = n;
        set<ll> st;
        F(i, l, r) {
            p[i] = min(mx, s - TRI(r - i));
            mx = p[i] - 1;
            s -= p[i];
            st.insert(p[i]);
        }
        ll c = 1;
        F(i, 0, n) if(i < l || i >= r) {
            while(st.count(c)) c++;
            p[i] = c;
            st.insert(c);
        }
        if(!s && st.size() == n && *st.begin() == 1 && *st.rbegin() == n) {
            F(i, 0, n) cout << p[i] << ' ';
            cout << '\n';
        } else cout << "-1\n";
    }    
}