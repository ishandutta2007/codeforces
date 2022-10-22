#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<vector<pair<int, ll>>> adj;
vector<ll> sub;

ll calc(int n, int par = -1) {
    for(pair<int, ll> ch : adj[n]) {
        int x; ll w;
        tie(x, w) = ch;
        if(x == par) continue;
        sub[n] += (w + calc(x, n));
    }
    return sub[n];
}

ll dfs(int n, int par = -1) {
    ll tot = 0;
    for(pair<int, ll> ch : adj[n]) {
        int x; ll w;
        tie(x, w) = ch;
        if(x == par) continue;
        tot += (2 * (w + sub[x]));
    }
    ll ans = tot;
    for(pair<int, ll> ch : adj[n]) {
        int x; ll w;
        tie(x, w) = ch;
        if(x == par) continue;
        ans = min(ans, tot - w - 2 * sub[x] + dfs(x, n));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    adj.resize(n);
    sub.resize(n, 0);
    for(int i = 0; i < n-1; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--; y--;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    calc(0);
    cout << dfs(0) << '\n';
}