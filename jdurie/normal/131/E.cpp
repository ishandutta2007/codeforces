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
#define N 300010

map<ll, set<ll>> r, c, d1, d2;
pl p[N];ll ans[9];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) G(m)
    F(i, 0, m) {
        G(x) G(y)
        p[i] = {x, y};
        r[x].insert(y);
        c[y].insert(x);
        d1[x + y].insert(x - y);
        d2[x - y].insert(x + y);
    }
    F(i, 0, m) {
        ll ct = 8, x = p[i].K, y = p[i].V;
        if(y == *r[x].begin()) ct--;
        if(y == *r[x].rbegin()) ct--;
        if(x == *c[y].begin()) ct--;
        if(x == *c[y].rbegin()) ct--;
        if(x - y == *d1[x + y].begin()) ct--;
        if(x - y == *d1[x + y].rbegin()) ct--;
        if(x + y == *d2[x - y].begin()) ct--;
        if(x + y == *d2[x - y].rbegin()) ct--;
        ans[ct]++;
    }
    F(i, 0, 9) cout << ans[i] << ' ';
    cout << '\n';
}