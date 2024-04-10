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

ll n, y[N];

void solve() {
    F(i, 2, n + 1) {
        vector<ll> v;
        F(j, 2, n + 1) if((y[j] - y[1]) * (i - 1) != (y[i] - y[1]) * (j - 1)) v.push_back(j);
        if(v.size()) {
            bool ok = true;
            F(j, 1, v.size()) if((y[v[j]] - y[v[0]]) * (i - 1) != (y[i] - y[1]) * (v[j] - v[0])) ok = false;
            if(ok) { cout << "Yes\n"; exit(0); }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    F(i, 1, n + 1) cin >> y[i];
    solve();
    reverse(y + 1, y + n + 1);
    solve();
    cout << "No\n";
}