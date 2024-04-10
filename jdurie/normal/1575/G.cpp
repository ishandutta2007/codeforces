//Codeforces Template
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
typedef pair<int, int> pi;
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
#define N 100010
 
int n, a[N], b[N];
ll ansg[N], ct[N];
vector<int> divs[N];
int v[N * 150];
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    F(i, 1, N) for(int j = 1; j * j <= i; ++j) if(!(i % j)) {
        divs[i].push_back(j);
        if(j * j - i) divs[i].push_back(i / j);
    }
    cin >> n; F(i, 1, n + 1) cin >> a[i];
    F(g, 1, n + 1) {
        ll vsz = 0, bsz = 0;
        for(int i = g; i <= n; i += g) b[bsz++] = a[i];
        sort(b, b + bsz);
        ll c = 0;
        F(i, 0, bsz) {
            c++;
            if(i == bsz - 1 || b[i] - b[i + 1]) {
                for(ll z : divs[b[i]]) {
                    v[vsz++] = z;
                    ct[z] += c;
                }
                c = 0;
            }
        }
        sort(v, v + vsz);
        vsz = unique(v, v + vsz) - v;
        F(i, 0, vsz) ct[v[i]] *= ct[v[i]];
        reverse(v, v + vsz);
        F(i, 0, vsz) {
            ll x = v[i];
            for(int y : divs[x]) if(y - x) ct[y] -= ct[x];
            ct[x] %= M;
            ansg[g] = (ansg[g] + x * ct[x]) % M;
        }
        F(i, 0, vsz) ct[v[i]] = 0;
    }
    ll ans = 0;
    FD(i, n, 0) {
        for(int j = 2 * i; j <= n; j += i) ansg[i] = (ansg[i] + M - ansg[j]) % M;
        ans = (ans + ansg[i] * i) % M;
    }
    cout << ans << '\n';
}