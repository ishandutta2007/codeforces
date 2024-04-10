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

ll a[N], ans[1000][1000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(m) G(k) 
        F(i, 1, k + 1) cin >> a[i];
        ll mxc = *max_element(a + 1, a + k + 1);
        ll n = 1, ff, f, x, o;
        while(1) {
            ff = n * n - (n / 2) * (n / 2);
            o = ((n + 1) / 2) * ((n + 1) / 2);
            x = ff - o; f = o + x / 2;
            if(ff >= m && f >= mxc) break;
            n++;
        }
        vector<pl> os, x1s;
        F(i, 0, n) F(j, 0, n) {
            if(!(i % 2) && !(j % 2)) os.push_back({i, j});
            else if(!(i % 2)) x1s.push_back({i, j});
        }
        if(mxc >= x / 2) {
            ll c = 1; while(a[c] - mxc) c++; a[c] = 0;
            for(pl p : x1s) ans[p.K][p.V] = c;
            F(i, 0, mxc - x / 2) ans[os[i].K][os[i].V] = c; 
        } else {
            vector<ll> knap;
            F(i, 1, k + 1) if(knap.size() < x / 2) { F(j, 0, a[i]) knap.push_back(i); a[i] = 0; }
            F(i, 0, x / 2) ans[x1s[i].K][x1s[i].V] = knap[i];
            F(i, x / 2, knap.size()) ans[os[i - x / 2].K][os[i - x / 2].V] = knap[i];
        }
        vector<ll> lft; ll idx = 0;
        F(i, 1, k + 1) F(j, 0, a[i]) lft.push_back(i);
        F(i, 0, n) F(j, 0, n) if((!(i % 2) || !(j % 2)) && !ans[i][j] && idx < lft.size()) ans[i][j] = lft[idx++];
        cout << n << '\n';
        F(i, 0, n) F(j, 0, n) cout << ans[i][j] << " \n"[j == n - 1], ans[i][j] = 0;
    }
}