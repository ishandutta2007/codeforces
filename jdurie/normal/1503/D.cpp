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
#define N 400010

ll pr[N];
bool used[N], l[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n)
    F(i, 0, n) {
        G(a) G(b) l[a] = true;
        pr[a] = b, pr[b] = a;
    }
    ll ans = 0, cur = 0, cswp = 0;
    ll tasc = 0, tdsc = 2 * n + 1;
    ll basc = 2 * n + 1, bdsc = 0;
    ll mn = 1, mx = 2 * n;
    F(i, 0, n) {
        while(used[mn] && mn <= 2 * n) mn++;
        while(used[mx] && mx) mx--;
        bool mntop = mn > tasc && mn < basc && pr[mn] < tdsc && pr[mn] > bdsc;
        bool mnbot = mn > bdsc && mn < tdsc && pr[mn] < basc && pr[mn] > tasc;
        bool mxtop = mx < tdsc && mx > bdsc && pr[mx] > tasc && pr[mx] < basc;
        bool mxbot = mx < basc && mx > tasc && pr[mx] > bdsc && pr[mx] < tdsc;
        if(mntop && mnbot && mxtop && mxbot) {
            ans += min(cswp, cur - cswp);
            tasc = mn, tdsc = pr[mn];
            cur = 1, cswp = l[mn] ? 0 : 1;
            used[mn] = used[pr[mn]] = true;
        } else if(!(mntop || mnbot) || !(mxtop || mxbot)) EX(-1)
        else if(!mntop) {
            basc = pr[mn], bdsc = mn;
            cur++; if(l[mn]) cswp++;
            used[mn] = used[pr[mn]] = true;
        } else if(!mnbot) {
            tasc = mn, tdsc = pr[mn];
            cur++; if(!l[mn]) cswp++;
            used[mn] = used[pr[mn]] = true;
        } else if(!mxtop) {
            basc = mx, bdsc = pr[mx];
            cur++; if(!l[mx]) cswp++;
            used[mx] = used[pr[mx]] = true;
        } else if(!mxbot) {
            tasc = pr[mx], tdsc = mx;
            cur++; if(l[mx]) cswp++;
            used[mx] = used[pr[mx]] = true;
        }
    }
    ans += min(cswp, cur - cswp);
    cout << ans << '\n';
}