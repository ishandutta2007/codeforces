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

#define G(x) int x; cin >> x;
#define GD(x) ld x; cin >> x;
#define GS(s) string s; cin >> s;
#define F(i, l, r) for(int i = l; i < (r); ++i)
#define FD(i, r, l) for(int i = r; i > (l); --i)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(a) (a).begin(), (a).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 20000001

int a[N], ct[N], primes[N];
bool prime[N];
ll dp[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll idx = 0;
    F(i, 2, N) if(!prime[i]) {
        prime[i] = true;
        primes[idx++] = i;
        for (ll j = i * (ll) i; j < N; j += i) prime[j] = true;
    }
    primes[idx++] = N;
    G(n)
    F(i, 0, n) { G(x) a[x]++; }
    F(i, 1, N) for(int j = i; j < N; j += i) ct[i] += a[j];
    FD(i, N - 1, 0) if(ct[i]) {
        dp[i] = ct[i] * (ll) i;
        for(int j = 0; primes[j] * i < N; ++j) {
            ll q = i * primes[j];
            if(ct[q]) dp[i] = max(dp[i], (ct[i] - ct[q]) * (ll) i + dp[q]);
        }
    }
    cout << dp[1] << '\n';
}