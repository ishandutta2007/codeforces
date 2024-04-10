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
        G(n) G(a) G(b)
        if(abs(a - b) > 1 || a + b > n - 2) cout << "-1\n";
        else {
            deque<ll> d, ans;
            F(i, 1, n + 1) d.push_back(i);
            ll j = a >= b ? 0 : 1;
            bool lastS = b >= a;
            while(a || b) {
                if(!j) ans.push_back(d.back()), d.pop_back(), a--;
                else ans.push_back(d.front()), d.pop_front(), b--;
                j ^= 1;
            }
            ans.push_front(d.front()), d.pop_front();
            for(ll x : ans) cout << x << ' ';
            if(!lastS) reverse(A(d));
            for(ll x : d) cout << x << ' ';
            cout << '\n';
        }
    }
}