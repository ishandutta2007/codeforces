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

typedef int ll;
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
#define N 2000010

ll a[40], b[40], prime[N];
char works[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    prime[0] = prime[1] = 1;
    F(i, 2, N) if(!prime[i]) {
        prime[i] = i;
        if(i < 5000) for (ll j = i * i; j < N; j += i) if(!prime[j]) prime[j] = i;
    }
    G(tc) F(z, 1, tc + 1) {
        G(n) F(i, 0, n) cin >> a[i], a[i] += N;
        ll ans = 1;
        map<ll, ll> ct;
        F(i, 0, n) ct[a[i]]++;
        for(pl p : ct) if(2 * p.V >= n) ans = -1;
        if(~ans) {
            works[1] = z;
            F(k, 2, N) if(works[k / prime[k]] == z) {
                F(i, 0, n) b[i] = a[i] % k;
                sort(b, b + n);
                ll lst = -1;
                F(i, 0, n) if(i == n - 1 || b[i] - b[i + 1]) {
                    if(2 * (i - lst) >= n) ans = k;
                    lst = i;
                }
                if(ans == k) works[k] = z;
            }
        }
        cout << ans << '\n';
    }
}