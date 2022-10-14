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
#define N 200010

ll a[N];
bool seen[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(n) G(q)
    F(i, 0, n) cin >> a[i];
    set<ll> ok;
    ll zs = 0;
    F(i, 0, n) if(a[i]) {
        if(seen[a[i]] && !ok.count(a[i])) EX("NO")
        while(!ok.empty() && *ok.rbegin() > a[i]) ok.erase(*ok.rbegin());
        ok.insert(a[i]);
        seen[a[i]] = true;
    } else zs++;
    if(!zs && !seen[q]) EX("NO")
    cout << "YES\n";
    if(!seen[q]) FD(i, n - 1, -1) if(!a[i]) { a[i] = q; break; }
    ll fst = 0, lst = 0;
    F(i, 0, n) if(a[i]) { fst = a[i]; break; }
    F(i, 0, n) 
        if(a[i]) {
            cout << a[i] << ' ';
            lst = a[i];
        } else if(lst) cout << lst << ' ';
        else if(fst) cout << fst << ' ';
        else cout << q << ' ';
    cout << '\n';
}