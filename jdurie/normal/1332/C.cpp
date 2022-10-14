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
#define F(i, l, r) for(ll i = l; i < r; i++)
#define FD(i, r, l) for(ll i = r; i > l; i--)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}" << endl; }
#define EX(x) { cout << x << endl; exit(0); }
#define K first
#define V second
#define M 1000000007 //998244353
#define N 200010

ll ct[N][26];
bool used[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(T) while(T--) {
        G(n) G(k) GS(s)
        F(i, 0, k) {
            used[i] = false;
            fill(ct[i], ct[i] + 26, 0);
        }
        F(i, 0, n) ct[i % k][s[i] - 'a']++;
        ll ans = 0;
        F(i, 0, k) if(!used[i]) {
            ll oI = (n - 1 - i) % k;
            used[i] = used[oI] = true;
            ll tot = 0, mx = 0;
            F(j, 0, 26) {
                ll v = ct[i][j] + (oI - i ? ct[oI][j] : 0);
                tot += v; mx = max(mx, v);
            }
            ans += tot - mx;
        }
        cout << ans << '\n';
    }
}