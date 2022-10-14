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
#define A(x) (x).begin(), (x).end()
#define K first
#define V second
#define N 1000010

vector<ll> pos[256];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    G(n) GS(s)
    F(i, 0, n) pos[s[i]].push_back(i);
    ll ans = n;
    F(i, 0, n) {
        bool ok = true;
        ll mn = i;
        F(c, min('a', 'A'), max('Z', 'z') + 1) if(pos[c].size()) { if(i > pos[c].back()) ok = false; else mn = max(mn, *lower_bound(A(pos[c]), i)); }
        if(ok) ans = min(ans, mn - i  +1);
    }
    cout << ans << '\n';
}