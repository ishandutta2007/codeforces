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
#define N 1010
#define OK(r, c) (r >= 0 && c >= 0 && r < n && c < m)
#define MX -1

string gr[N];
int num[N][N];
vector<pl> qu;
ll dx[4] = {-1, 1, 0, 0};
ll dy[4] = {0, 0, -1, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    G(n) G(m) G(t)
    F(i, 0, n) cin >> gr[i];
    F(i, 0, n) F(j, 0, m) {
        num[i][j] = MX;
        if(i && gr[i - 1][j] == gr[i][j] ||
            i != n - 1 && gr[i + 1][j] == gr[i][j] ||
            j && gr[i][j - 1] == gr[i][j] ||
            j != m - 1 && gr[i][j + 1] == gr[i][j])
            qu.emplace_back(i, j);
    }
    
    for(ll s = 1;; s++) {
        if(qu.empty()) break;
        vector<pl> tempq;
        for(pl p : qu) if(num[p.K][p.V] == MX) {
            num[p.K][p.V] = s;
            for(ll k = 0; k < 4; k++) {
                ll rI = p.K + dx[k], cI = p.V + dy[k];
                if(OK(rI, cI) && num[rI][cI] == MX)
                    tempq.emplace_back(rI, cI);
            }
        }
        qu.clear();
        for(pl p : tempq) qu.push_back(p);
    }
    while(t--) {
        G(i) G(j) G(p)
        i--; j--;
        if(num[i][j] == MX || p < num[i][j] || (p - num[i][j]) % 2)
            cout << gr[i][j] << endl;
        else cout << '1' - gr[i][j] << endl;
    }
}