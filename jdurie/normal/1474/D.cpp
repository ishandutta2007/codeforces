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

ll a[N], incL[N], incR[N];
bool okL[N], okR[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n)
        F(i, 1, n + 1) cin >> a[i];
        a[n + 1] = 0;
        ll k = 0;
        F(i, 0, n + 2) {
            incL[i] = k;
            okL[i] = k >= 0 && k <= a[i];
            if(i) okL[i] &= okL[i - 1];
            k = a[i] - k;
        }
        k = 0;
        FD(i, n + 1, -1) {
            incR[i] = k;
            okR[i] = k >= 0 && k <= a[i];
            if(i - n - 1) okR[i] &= okR[i + 1];
            k = a[i] - k;
        }
        string ans = okL[n + 1] ? "YES\n" : "NO\n";
        F(i, 1, n)
            if(incL[i] >= 0 && incL[i] <= a[i + 1] && incR[i + 1] >= 0 && incR[i + 1] <= a[i])
                if(a[i + 1] - incL[i] == a[i] - incR[i + 1])
                    if(okL[i - 1] && okR[i + 2])
                        ans = "YES\n";
        cout << ans;
    }
}