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

ll mx[256];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        GS(s) ll n = s.size();
        set<char> st;
        ll str = 0;
        string ans = "";
        F(iter, 0, 26) {
            fill_n(mx + 'a', 26, M);
            F(i, str, n) if(!st.count(s[i])) mx[s[i]] = i;
            ll p = *min_element(mx + 'a', mx + 'z' + 1);
            if(p == M) break;
            char bst = 'a';
            F(i, str, p + 1) if(!st.count(s[i])) bst = max(bst, s[i]);
            st.insert(bst);
            while(s[str] - bst) str++;
            ans = ans + s.substr(str, 1);
        }
        cout << ans << '\n';
    }
}