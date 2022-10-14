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
#define N 1000010

bool prime[N];
ll ans[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fill_n(prime, N, true);
    F(i, 2, N) if(prime[i])
        for (ll j = i * i; j < N; j += i) prime[j] = false;
    ans[1] = 1;
    ll cur = 1;
    F(n, 2, N) {
        ll k = round(sqrt(n));
        if(k * k == n && prime[k]) cur--;
        else if(prime[n]) cur++;
        ans[n] = cur;
    }
    G(tc) while(tc--) { G(n) cout << ans[n] << '\n'; }
}