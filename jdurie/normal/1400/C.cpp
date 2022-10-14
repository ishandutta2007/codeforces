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
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(x) (x).begin(), (x).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 100010

char ans[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        GS(s) G(x)
        ll n = s.size();
        fill_n(ans, n, 'X');
        bool ok = true;
        F(i, 0, n) {
            if(s[i] == '0') {
                if(i >= x) {
                    if(ans[i - x] == '1') ok = false;
                    ans[i - x] = '0';
                }
                if(i + x < n) {
                    if(ans[i + x] == '1') ok = false;
                    ans[i + x] = '0';
                }
            } else {
                if(i >= x && ans[i - x] != '0') ans[i - x] = '1';
                else if(i + x < n && ans[i + x] != '0') ans[i + x] = '1';
                else ok = false;
            }
        }
        F(i, 0, n) if(ans[i] == 'X') ans[i] = '0';
        if(!ok) cout << "-1\n";
        else {
            F(i, 0, n) cout << ans[i];
            cout << '\n';
        }
    }
}