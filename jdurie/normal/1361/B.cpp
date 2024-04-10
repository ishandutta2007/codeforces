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
#define EX(x) { cout << x << endl; goto eotc; }
#define K first
#define V second
#define M 1000000007 //998244353
#define N 1000010

ll a[N];

ll pw(ll a, ll p) {
    if(!p) return 1;
    ll t = pw(a, p / 2);
    return t * t % M * (p % 2 ? a : 1) % M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(T) while(T--) {
        G(n) G(p)
        F(i, 0, n) cin >> a[i];
        if(p == 1) cout << n % 2 << '\n';
        else {
            sort(a, a + n);
            ll diff = 1, cPow = a[n - 1];
            bool alwaysSub = false, alwaysAdd = false;
            FD(i, n - 2, -1) {
                while(cPow > a[i]) {
                    if(!diff || alwaysSub || alwaysAdd) {
                        diff = diff * pw(p, cPow - a[i]) % M;
                        cPow = a[i];
                        break;
                    }
                    else diff *= p;
                    if(diff > n) alwaysSub = true;
                    if(diff < -n) alwaysAdd = true;
                    cPow--;
                }
                if(alwaysSub) diff = (diff + M - 1) % M;
                else if(alwaysAdd) diff = (diff + 1) % M;
                else if(diff > 0) diff--;
                else diff++;
            }
            diff = diff * pw(p, cPow) % M;
            cout << diff << '\n';
        }
    }
}