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
//#define N 200010

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) multiset<ll> piles = {0}; ll sm = 0;
        while(n--) { G(x) piles.insert(x); sm += x; }
        vector<ll> fib = {0, 1}; sm--;
        while(sm > 0) fib.push_back(fib.back() + fib[fib.size() - 2]), sm -= fib.back();
        if(sm) cout << "NO\n";
        else {
            reverse(A(fib)); fib.pop_back();
            ll rsv = -1; string ans = "YES\n";
            for(ll x : fib) {
                ll k = *piles.rbegin(); piles.erase(piles.find(k));
                if(~rsv) piles.insert(rsv);
                if(x > k) { ans = "NO\n"; break; }
                rsv = k - x;
            }
            cout << ans;
        }
    }
}