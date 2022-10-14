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
#define N 100010

ll a[N];
vector<ll> ans;

ll find(ll x) {
    ll i = 0;
    while(a[i] - x) i++;
    return i;
}

void swap(ll i) {
    ans.push_back(i + 1);
    reverse(a, a + i + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        ans.clear();
        G(n) bool ok = true;
        F(i, 0, n) {
            cin >> a[i];
            if((a[i] + 1 + i) & 1) ok = false;
        }
        if(!ok) cout << "-1\n";
        else {
            for(ll x = n; x > 1; x -= 2) {
                swap(find(x));
                swap(find(x - 1) - 1);
                swap(find(x - 1) + 1);
                swap(2);
                swap(x - 1);
            }
            cout << ans.size() << '\n';
            for(ll x : ans) cout << x << ' ';
            cout << '\n';
        }
    }
}