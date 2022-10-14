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

vector<ll> graph[N];
ll indeg[N], dp[N][26];
string s;

ll r(ll i, ll j) {
    if(~dp[i][j]) return dp[i][j];
    ll k = s[i] == 'a' + j ? 1 : 0, ans = k;
    for(ll z : graph[i]) ans = max(ans, k + r(z, j));
    return dp[i][j] = ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    G(n) G(m)
    cin >> s;s = "&" + s;
    while(m--) {
        G(a) G(b)
        graph[a].push_back(b);
        indeg[b]++;
    }
    vector<ll> topo;
    F(i, 1, n + 1)if(!indeg[i]) topo.push_back(i);
    F(i, 0, topo.size()) for(ll j : graph[topo[i]]) if(!--indeg[j]) topo.push_back(j);
    if(topo.size() < n) cout << "-1\n";
    else {
        ll ans = 0;
        F(i, 1, n + 1) F(j, 0, 26) ans = max(ans, r(i, j));
        cout << ans << '\n';
    }
}