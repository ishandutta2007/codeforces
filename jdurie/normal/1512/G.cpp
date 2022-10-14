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
#define N 10000010

ll prime[N], ans[N], q[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(q, -1, sizeof q);
    prime[0] = prime[1] = 1;
    F(i, 2, N) if(!prime[i]) {
        prime[i] = i;
        for (ll j = i * i; j < N; j += i) if(!prime[j]) prime[j] = i;
    }
    ans[1] = q[1] = 1;
    F(i, 2, N) {
        ll ct = 0, p = prime[i], temp = i, f = 1, g = p;
        while(!(temp % p)) {
            ct++; temp /= p; f += g; g *= p;
        }
        ans[i] = ans[temp] * f;
        if(ans[i] < N && q[ans[i]] == -1) q[ans[i]] = i;
    }
    G(tc) while(tc--) {
        G(c) cout << q[c] << '\n';
    }
}