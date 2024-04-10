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
#define M 2000010 //998244353
#define N 2000010

ll a[N], b[N], q[N], ord[N], an[N], prime[M];

ll getnum(ll i) {
    ll ct = 0;
    while(i > 1) {
        ll p = prime[i];
        if(!(i % (p * p))) return 0;
        i /= p; ct++;
    }
    return ct & 1 ? 1 : -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    prime[0] = prime[1] = 1;
    F(i, 2, M) if(!prime[i]) {
        prime[i] = i;
        for (ll j = i * i; j < M; j += i) if(!prime[j]) prime[j] = i;
    }
    G(n)
    F(i, 1, n + 1) cin >> a[i];
    F(i, 1, n + 1) cin >> b[i];
    G(qq) F(i, 1, qq + 1) cin >> q[i], q[i] = q[i] - a[1];
    F(i, 1, n + 1) a[i] = b[i] - a[i];
    a[1] = -M;
    q[0] = -M;
    iota(ord, ord + qq + 1, 0ll);
    sort(ord, ord + qq + 1, [&](ll i, ll j) { return q[i] < q[j]; });
    vector<ll> pr, sqf;
    ll ans = 0;
    F(i, 1, n + 1) {
        ans += abs(a[i]);
        for(ll j = 2 * i; j <= n; j += i) a[j] -= a[i];
        ll z = getnum(i);
        if(z == 1) pr.push_back(-a[i]); else if(z) sqf.push_back(-a[i]);
    }
    sort(pr.rbegin(), pr.rend()); sort(A(sqf));
    ll pi = 0, si = 0;
    while(pi < pr.size() && pr[pi] >= 0) pi++;
    while(si < sqf.size() && sqf[si] <= 0) si++;
    F(i, 1, qq + 1) {
        ll dlt = q[ord[i]] - q[ord[0]], d2 = q[ord[i]] - q[ord[i - 1]], d3 = q[ord[i - 1]] - q[ord[0]];
        while(pi < pr.size() && pr[pi] >= -dlt) {
            ans += abs(pr[pi] + dlt) - abs(pr[pi] + d3) - d2;
            pi++;
        }
        while(si < sqf.size() && sqf[si] <= dlt) {
            ans += abs(sqf[si] - dlt) - abs(sqf[si] - d3) - d2;
            si++;
        }
        ans += pi * d2 - (pr.size() - pi) * d2;
        ans += si * d2 - (sqf.size() - si) * d2;
        an[ord[i]] = ans;
    }
    F(i, 1, qq + 1) cout << an[i] << '\n';
}