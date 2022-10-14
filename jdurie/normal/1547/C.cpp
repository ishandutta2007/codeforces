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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(k) G(n) G(m)
        vector<ll> ans, a, b;
        while(n--) { G(x) a.push_back(x); }
        while(m--) { G(x) b.push_back(x); }
        ll iA = 0, iB = 0;
        while(iA < a.size() || iB < b.size()) {
            if(iA < a.size() && (iB == b.size() || a[iA] < b[iB])) ans.push_back(a[iA++]);
            else ans.push_back(b[iB++]);
        }
        bool ok = true;
        for(ll x : ans)
            if(x > k) ok = false;
            else if(!x) k++;
        if(ok) {
            for(ll x : ans) cout << x << ' ';
            cout << '\n';
        } else cout << "-1\n";
    }
}