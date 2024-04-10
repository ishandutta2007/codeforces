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

ll a[N], o[N], x, n, k, v[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    cout << "and 1 3" << endl;
    cin >> x;
    F(i, 1, n) {
        cout << "and " << i << ' ' << i + 1 << endl;
        cin >> a[i];
        cout << "or " << i << ' ' << i + 1 << endl;
        cin >> o[i];
    }
    F(b, 0, 30) {
        ll id = -1;
        F(i, 1, n) {
            if((a[i] >> b) & 1) id = i;
            if(!((o[i] >> b) & 1)) id = i;
        }
        if(id == -1) {
            F(i, 1, n + 1) if((i & 1) == ((x >> b) & 1)) v[i] |= (1 << b);
        } else {
            if((a[id] >> b) & 1) v[id] |= (1 << b), v[id + 1] |= (1 << b);
            F(i, id + 1, n) 
                if((v[i] >> b) & 1) {
                    if((a[i] >> b) & 1) v[i + 1] |= (1 << b);
                } else {
                    if((o[i] >> b) & 1) v[i + 1] |= (1 << b);
                }
            FD(i, id, 1)
                if((v[i] >> b) & 1) {
                    if((a[i - 1] >> b) & 1) v[i - 1] |= (1 << b);
                } else {
                    if((o[i - 1] >> b) & 1) v[i - 1] |= (1 << b);
                }
        }
    }
    sort(v + 1, v + n + 1);
    cout << "finish " << v[k] << '\n';
}