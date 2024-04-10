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
//#define N 100010

ll ct[256];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(tc) while(tc--) {
        memset(ct, 0, sizeof ct);
        GS(s) sort(A(s)); ll n = s.size();
        for(char c : s) ct[c]++;
        bool done = false;
        F(c, 'a', 'z' + 1) if(ct[c] == 1 && !done) {
            done = true;
            cout << (char)c;
            for(char d : s) if(d - c) cout << d;
            cout << '\n';
        }
        char a = 'a';
        while(!ct[a]) a++;
        if(ct[a] == n && !done) {
            done = true;
            cout << s << '\n';
        }
        if(!done) {
            if(2 * ct[a] - 2 <= s.size()) {
                ll idx = 0;
                while(s[idx] == a) idx++;
                cout << a << a;
                ct[a] -= 2;
                while(idx < n) {
                    cout << s[idx];
                    if(ct[a]) { cout << a; ct[a]--; }
                    idx++;
                }
                cout << '\n';
            } else {
                char b = a + 1;
                while(!ct[b]) b++;
                if(ct[a] + ct[b] == n) {
                    cout << a;
                    F(i, 0, ct[b]) cout << b;
                    F(i, 0, ct[a] - 1) cout << a;
                    cout << '\n';
                } else {
                    char c = b + 1;
                    while(!ct[c]) c++;
                    cout << a << b;
                    F(i, 0, ct[a] - 1) cout << a;
                    cout << c;
                    ct[b]--; ct[c]--;
                    F(x, b, 'z' + 1) F(j, 0, ct[x]) cout << (char)x;
                    cout << '\n';
                }
            }
        }
    }    
}