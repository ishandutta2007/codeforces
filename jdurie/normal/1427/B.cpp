#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
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
#define F(i, l, r) for(ll i = l; i < (r); i++)
#define FD(i, r, l) for(ll i = r; i > (l); i--)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(a) (a).begin(), (a).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 100010

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(k) GS(s)
        vector<ll> ls;
        ll lct = 0, wct = 0, ws = 0, www = 0;
        for(char c : s)
            if(c == 'L') {
                if(wct) ws++, wct = 0;
                if(ws) lct++;
            } else {
                wct++, www++;
                if(lct) ls.push_back(lct), lct = 0;
            }
        if(wct) ws++;
        if(!www) cout << max(0ll, 2 * k - 1) << '\n';
        else {
            sort(A(ls));
            ll idx = 0, origK = k;
            while(idx < (ll)ls.size() && k >= ls[idx]) k -= ls[idx++];
            cout << 2 * min(n, www + origK) - (ws - idx) << '\n';
        }
    }   
}