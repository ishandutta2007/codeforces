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
#define A(x) (x).begin(), (x).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 1010

ll n, a[N];
vector<ll> ans;

ll getMex() {
    set<ll> s;
    F(i, 0, n) s.insert(a[i]);
    ll mex = 0;
    while(s.count(mex)) mex++;
    return mex;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        ans.clear();
        cin >> n;
        F(i, 0, n) cin >> a[i];
        ll mex;
        while((mex = getMex()) < n) {
            ans.push_back(mex + 1);
            a[mex] = mex;
        }
        F(i, 0, n) if(a[i] - i) {
            bool ok = false;
            F(j, 0, n) if(a[j] == i) {
                ans.push_back(j + 1);
                ans.push_back(i + 1);
                a[j] = getMex(); a[i] = i;
                ok = true;
                break;
            }
            if(!ok) {
                ans.push_back(i + 1);
                a[i] = i;
            }
        }
        cout << ans.size() << '\n';
        for(ll k : ans) cout << k << ' ';
        cout << '\n';
    }
}