#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<vector<int>> adj;
vector<ll> sco;
map<pair<int, int>, ll> ans;

ll calc(int x, int k) {
    if(ans.count({x, k})) return ans[make_pair(x, k)];
    ll tot = sco[x] * k;
    int c = adj[x].size();
    if(c == 0) return ans[make_pair(x, k)] = tot;
    if(c == 1) return ans[make_pair(x, k)] = tot + calc(adj[x][0], k);
    vector<ll> ext;
    ext.reserve(c);
    for(int g : adj[x]) {
        ll a = calc(g, k / c);
        ll b = calc(g, 1 + k / c);
        ext.push_back(b - a);
        tot += a;
    }
    sort(ext.rbegin(), ext.rend());
    for(int i = 0; i < k % c; i++) {
        tot += ext[i];
    }
    return ans[make_pair(x, k)] = tot;
}

void solve() {
    int n, k;
    cin >> n >> k;
    adj.resize(n);
    sco.resize(n);
    for(int i = 1; i < n; i++) {
        int x;
        cin >> x;
        adj[x-1].push_back(i);
    }
    for(int i = 0; i < n; i++) {
        cin >> sco[i];
    }
    cout << calc(0, k) << '\n';
    adj.clear();
    sco.clear();
    ans.clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc_count;
    cin >> tc_count;
    while(tc_count--) {
        solve();
    }
}