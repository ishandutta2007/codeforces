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

typedef int ll;
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
#define N 500010

vector<ll> neow[N];
ll ans[N];
bool used[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n)
    F(i, 1, n + 1)
        for(ll x = 1; x * x <= i; x++) if(!(i % x)) {
            neow[x].push_back(i); 
            if(x - i / x) neow[i / x].push_back(i);
        }
    ll idx = n - 2;
    fill(ans, ans + N, 1);
    FD(i, N - 1, 1) {
        ll usedCt = 0, cock = neow[i].size() - 1;
        for(ll j : neow[i]) if(!used[j]) usedCt++;
        while(usedCt > 1) {
            ans[idx--] = i;
            while(used[neow[i][cock]]) cock--;
            used[neow[i][cock--]] = true;
            usedCt--;
        }
    }
    F(i, 0, n - 1) cout << ans[i] << ' ';
    cout << '\n';
}