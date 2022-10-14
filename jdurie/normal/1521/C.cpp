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
#define N 10010

ll ask(ll t, ll i, ll j, ll x) {
    cout << "? " << t << ' ' << i + 1 << ' ' << j + 1 << ' ' << x << endl;
    G(res) if(!~res) exit(0);
    return res;
}

ll mx[N], ans[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        G(n) F(i, 0, n) ans[i] = 0, mx[i] = ask(1, i, (i + 1) % n, n - 1);
        F(i, 0, n) if(mx[i] == n) { mx[(i + 1) % n] = n; break; }
        ll x = -1;
        F(i, 0, n)
            if(mx[i] < mx[(i + 1) % n]) ans[(i + 2) % n] = mx[(i + 1) % n];
            else if(mx[i] > mx[(i + 1) % n]) ans[i] = mx[i];
            else { ans[(i + 1) % n] = mx[i]; if(mx[i] == n) x = (i + 1) % n; }
        F(i, 0, n) if(!ans[i]) ans[i] = ask(2, i, x, 1);
        cout << '!';
        F(i, 0, n) cout << ' ' << ans[i];
        cout << endl;
    }
}