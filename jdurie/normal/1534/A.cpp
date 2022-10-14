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
#define N 100

string inp[N];
char g1[N][N], g2[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    F(i, 0, N) F(j, 0, N)
        if((i + j) & 1) g1[i][j] = 'R', g2[i][j] = 'W';
        else g1[i][j] = 'W', g2[i][j] = 'R';
    G(tc) while(tc--) {
        G(n) G(m)
        F(i, 0, n) cin >> inp[i];
        bool ok1 = true, ok2 = true;
        F(i, 0, n) F(j, 0, m) if(inp[i][j] != '.') {
            if(inp[i][j] != g1[i][j]) ok1 = false;
            else ok2 = false;
        }
        if(!ok1 && !ok2) cout << "NO\n";
        else if(ok1) {
            cout << "YES\n";
            F(i, 0, n) {
                F(j, 0, m) cout << g1[i][j];
                cout << '\n';
            }
        } else {
            cout << "YES\n";
            F(i, 0, n) {
                F(j, 0, m) cout << g2[i][j];
                cout << '\n';
            }
        }
    }    
}