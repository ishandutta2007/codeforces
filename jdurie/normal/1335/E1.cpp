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
#define N 100010

ll mCtL[N][26], mCtR[N][26], ct[N], a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) F(i, 1, n + 1) { cin >> a[i]; a[i]--; }
        F(i, 0, 26) mCtL[n + 1][i] = mCtR[n + 1][i] = 0;
        fill(ct, ct + 26, 0);
        F(i, 1, n + 1) {
            ct[a[i]]++;
            F(j, 0, 26) mCtL[i][j] = ct[j];
        }
        fill(ct, ct + 26, 0);
        FD(i, n, 0) {
            ct[a[i]]++;
            F(j, 0, 26) mCtR[i][j] = ct[j];
        }
        ll ans = *max_element(ct, ct + 26);
        F(l, 1, n + 1) {
            fill(ct, ct + 26, 0);
            F(r, l, n + 1) {
                ct[a[r]]++;
                ll k = 0;
                F(i, 0, 26) k = max(k, 2 * min(mCtL[l - 1][i], mCtR[r + 1][i]));
                ans = max(ans, k + *max_element(ct, ct + 26));
            }
        }
        cout << ans << '\n';
    }
}