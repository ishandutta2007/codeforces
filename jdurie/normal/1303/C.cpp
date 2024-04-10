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
#define P(a, n) { cout << "{ "; F(_, 0, n) cout << a[_] << " "; cout << "}\n"; }
#define EX(x) { cout << x << '\n'; exit(0); }
#define A(x) (x).begin(), (x).end()
#define K first
#define V second
#define M 1000000007 //998244353
#define N 100010

char ans[200];
bool used[26];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        GS(s)
        fill_n(ans, 200, 0);
        fill_n(used, 26, 0);
        ll pos = 100;
        string ok = "YES\n";
        for(char c : s)
            if(ans[pos - 1] == c) pos--;
            else if(ans[pos + 1] == c) pos++;
            else if(used[c - 'a']) { ok = "NO\n"; break; }
            else if(!ans[pos - 1]) ans[--pos] = c, used[c - 'a'] = true;
            else if(!ans[pos + 1]) ans[++pos] = c, used[c - 'a'] = true;
            else { ok = "NO\n"; break; }
        cout << ok;
        if(ok[0] == 'Y') {
            F(i, 0, 200) if(ans[i]) cout << ans[i];
            F(i, 0, 26) if(!used[i]) cout << (char)(i + 'a');
            cout << '\n';
        }
    }
}