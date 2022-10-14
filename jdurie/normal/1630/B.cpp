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

ll a[N], c[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) G(k) 
        F(i, 0, n) cin >> a[i], c[a[i]]++;
        F(i, 1, n + 1) c[i] += c[i - 1];
        pl p = {1, n}; ll q = (n + k + 1) / 2;
        F(i, 1, n + 1) if(n - c[i - 1] >= q) {
            ll j = lower_bound(c, c + n + 1, c[i - 1] + q) - c;
            if(j - i < p.V - p.K) p = {i, j};
        } 
        cout << p.K << ' ' << p.V << '\n';
        ll inx = 0, outx = 0, st = 1, done = 0;
        F(i, 0, n) {
            if(a[i] >= p.K && a[i] <= p.V) inx++; else outx++;
            if(inx > outx && done < k - 1) {
                cout << st << ' ' << i + 1 << '\n'; 
                st = i + 2; done++; inx = outx = 0;
            }
        }
        cout << st << ' ' << n << '\n'; 
        F(i, 1, n + 1) c[i] = 0;
    }
}