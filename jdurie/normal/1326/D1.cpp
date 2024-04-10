#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
#define N 5010

int isPal[N][N];
string s;

bool pal(ll l, ll r) {
    if(l == r || (r == l + 1 && s[l] == s[r])) return true;
    if(isPal[l][r] != -1) return isPal[l][r];
    return isPal[l][r] = s[l] == s[r] && pal(l + 1, r - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(T) while(T--) {
        cin >> s;
        ll n = s.size();
        F(i, 0, n + 6) F(j, 0, n + 6) isPal[i][j] = -1;
        string ends;
        ll ind = 0;
        while(ind < n - 2 - ind && s[ind] == s[n - 1 - ind]) ends += s[ind++];
        ll bestL = ind, bestR = n - 1 - ind;
        F(i, ind, n - ind) if(pal(ind, i)) bestL = i;
        FD(i, n - ind - 1, ind - 1) if(pal(i, n - 1 - ind)) bestR = i;
        cout << ends;
        if(bestL - ind > n - 1 - ind - bestR)
            F(i, ind, bestL + 1) cout << s[i];
        else F(i, bestR, n - ind) cout << s[i];
        reverse(ends.begin(), ends.end());
        cout << ends << endl;
    }
}