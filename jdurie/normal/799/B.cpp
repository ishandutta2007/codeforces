//ICPC Template
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pl;

#define G(x) ll x; cin >> x;
#define GS(s) string s; cin >> s;
#define F(i, l, r) for(ll i = l; i < (r); ++i)
#define K first
#define V second
#define N 1000010

set<pl> id[4];
ll prc[N];
pl col[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    G(n) F(i, 0, n) cin >> prc[i];
    F(i, 0, n) cin >> col[i].K;
    F(i, 0, n) cin >> col[i].V;
    F(i, 0, n) {
        id[col[i].K].insert({prc[i], i});
        id[col[i].V].insert({prc[i], i});
    }
    G(m) while(m--) {
        G(c)
        if(id[c].empty()) cout << "-1 ";
        else {
            ll i = id[c].begin()->V;
            F(j, 1, 4) id[j].erase({prc[i], i});
            cout << prc[i] << ' ';
        }
    }
    cout << '\n';
}