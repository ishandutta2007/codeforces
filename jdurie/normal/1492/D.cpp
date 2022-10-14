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

char ans1[N], ans2[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(z) G(o) G(k)
    ll n = z + o;
    if(k && k > n - 2) cout << "No\n";
    else if(k && (o < 2 || !z)) cout << "No\n";
    else if(!k) {
        cout << "Yes\n";
        F(c, 0, 2) {
            F(i, 0, o) cout << '1';
            F(i, 0, z) cout << '0';
            cout << '\n';
        }
    } else {
        cout << "Yes\n";
        fill_n(ans1, N, '$');
        ans1[0] = ans2[0] = ans1[1] = ans2[1 + k] = '1';
        ans2[1] = ans1[1 + k] = '0';
        o -= 2, z--;
        F(i, 0, n) if(ans1[i] == '$') {
            if(o) ans1[i] = ans2[i] = '1', o--;
            else ans1[i] = ans2[i] = '0', z--;
        }
        F(i, 0, n) cout << ans1[i];
        cout << '\n';
        F(i, 0, n) cout << ans2[i];
        cout << '\n';
    }
}