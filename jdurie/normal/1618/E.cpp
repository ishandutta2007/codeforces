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
#define M 1000000000 //998244353
#define N 100010

ll b[N], c[N], a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) F(i, 0, n) cin >> b[i];
        F(i, 0, n) c[i] = b[i] - b[(i + 1) % n];
        ll t = accumulate(b, b + n, 0ll), q = n * (n + 1) / 2;
        string ans = t % q ? "NO\n" : "YES\n";
        ll s = t / q;
        F(i, 0, n) if((c[i] + s) % n) ans = "NO\n"; else a[i] = (c[i] + s) / n;
        if(*max_element(a, a + n) > M || *min_element(a, a + n) <= 0) ans = "NO\n";
        cout << ans;
        if(ans[0] == 'Y') {
            cout << a[n - 1] << ' ';
            F(i, 0, n - 1) cout << a[i] << ' ';
            cout << '\n';
        }
    }
}