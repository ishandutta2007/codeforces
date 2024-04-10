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

ll a[N], b[N], c[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n)
    F(i, 1, n + 1) cin >> a[i];
    F(i, 1, n + 1) 
        b[i] = b[i - 1] + (a[i] == 0)
;















    for(ll i = n; i; i--)
        c[i] = c[i + 1] + (a[i] == 1);
           ll ans = max(b[n], c[1]);
        F(i, 1, n)
        ans = max(ans, b[i] + c[i + 1]);
        cout << ans << '\n';
    }