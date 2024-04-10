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
#define EX(x) { cout << x << endl; exit(0); }
#define K first
#define V second
#define M 1000000007 //998244353
#define N 110
#define GETR(x) (x < n ? x + 1 : 2 * n - x)

ll n, fuck[N], cock[N];
vector<pair<ll, pl>> v;

void doShit() {
    F(i, 0, 2 * n) if(cock[i] && cock[i] == fuck[i]) {
        v.emplace_back(cock[i], make_pair(GETR(i), i >= n ? 4 : 1));
        cock[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n; G(k)
    F(i, 0, n) cin >> fuck[i];
    F(i, 0, n) cin >> cock[i];
    F(i, 0, n) cin >> cock[2 * n - 1 - i];
    F(i, 0, n) cin >> fuck[2 * n - 1 - i];
    doShit();
    ll empt = *min_element(cock, cock + 2 * n);
    if(empt) EX(-1)
    while(1) {
        if(*max_element(cock, cock + 2 * n) == 0) break;
        doShit();
        F(i, 0, 2 * n) {
            ll nI = (i + 1) % (2 * n);
            if(cock[i] && !cock[nI]) {
                v.emplace_back(cock[i], make_pair(GETR(nI), nI >= n ? 3 : 2));
                swap(cock[i], cock[nI]);
                break;
            }
        }
    }
    cout << v.size() << '\n';
    for(auto a : v) cout << a.K << ' ' << a.V.V << ' ' << a.V.K << '\n';
}