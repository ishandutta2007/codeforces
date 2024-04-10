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
#define N 1000010

ll ptr[N], pq[N], mptr[N], n;

ll fixmptr(ll i, ll k) { return ptr[i] - i >= k ? i : mptr[i] = fixmptr(mptr[i], k); }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n; GS(s)
    ll last0 = 2 * n, last1 = 2 * n;
    FD(i, n - 1, -1) {
        if(s[i] == '0') last0 = i, ptr[i] = last1;
        else if(s[i] == '1') last1 = i, ptr[i] = last0;
        else ptr[i] = max(last0, last1);
    }
    F(i, 0, n) {
        if(i && s[i - 1] == '?') pq[i] = pq[i - 1];
        else if(s[i] == '?') pq[i] = i;
        else pq[i] = i;
    }
    F(i, 0, n) mptr[i] = pq[ptr[i]];
    F(k, 1, n + 1) {
        ll idx = 0, ans = 0;
        while(1) {
            if(ptr[idx] == 2 * n) {
                ans += (n - idx) / k;
                break;
            } if(ptr[idx] - idx >= k) {
                ll sets = (ptr[idx] - idx) / k;
                ans += sets;
                idx += sets * k;
            } else fixmptr(idx, k), idx = mptr[idx]; 
        }
        cout << ans << ' ';
    }
    cout << '\n';
}