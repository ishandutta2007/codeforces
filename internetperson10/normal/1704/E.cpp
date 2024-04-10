#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll MOD = 998244353;

vector<ll> nums, ind;
vector<vector<ll>> adj;
vector<vector<pair<int, ll>>> inter;

void solve() {
    int n, m;
    cin >> n >> m;
    nums.resize(n);
    adj.resize(n);
    ind.resize(n, 0);
    inter.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        if(nums[i]) inter[i].push_back({0, nums[i]});
    }
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        ind[y]++;
    }
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(ind[i] == 0) q.push(i);
    }
    ll ans = 0;
    while(q.size()) {
        int x = q.front(); q.pop();
        vector<pair<int, ll>> inter2;
        if(inter[x].size()) {
            sort(inter[x].begin(), inter[x].end());
            pair<int, ll> curr = inter[x][0];
            for(int i = 1; i < inter[x].size(); i++) {
                auto p = inter[x][i];
                if(curr.first + curr.second < p.first) {
                    inter2.push_back(curr);
                    curr = p;
                }
                else {
                    curr.second += p.second;
                    if(curr.second > 2 * MOD) {
                        curr.second %= MOD;
                        curr.second += MOD;
                    }
                }
            }
            inter2.push_back(curr);
            if(adj[x].size() == 0) {
                ans = curr.first + curr.second;
            }
        }
        for(int y : adj[x]) {
            for(auto p : inter2) {
                inter[y].push_back({p.first + 1, p.second});
            }
            ind[y]--;
            if(ind[y] == 0) q.push(y);
        }
        vector<pair<int, ll>>().swap(inter2);
    }
    nums.clear();
    ind.clear();
    vector<vector<ll>>().swap(adj);
    vector<vector<pair<int, ll>>>().swap(inter);
    cout << ans % MOD << '\n';
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