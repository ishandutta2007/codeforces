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
#define F(i, l, r) for(ll i = l; i < (r); i++)
#define FD(i, r, l) for(ll i = r; i > (l); i--)
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(a) (a).begin(), (a).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 200010

pair<string, ll> ops[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n)
    F(i, 0, 2 * n) {
        cin >> ops[i].K;
        if(ops[i].K == "-") cin >> ops[i].V;
    }
    vector<ll> v, ans;
    FD(i, 2 * n - 1, -1) {
        if(ops[i].K == "-") v.push_back(ops[i].V);
        else if(!v.size()) EX("NO")
        else ans.push_back(v.back()), v.pop_back();
    }
    reverse(A(ans));
    set<ll> cur;
    ll idx = 0;
    F(i, 0, 2 * n) {
        if(ops[i].K == "+") cur.insert(ans[idx++]);
        else if(*cur.begin() != ops[i].V) EX("NO")
        else cur.erase(cur.begin());
    }
    cout << "YES\n";
    for(ll a : ans) cout << a << ' ';
    cout << '\n';
}