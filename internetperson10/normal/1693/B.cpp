#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<int> l, r;
vector<vector<int>> adj;

pair<ll, int> dfs(int i) {
    if(adj[i].size() == 0) {
        return {r[i], 1};
    }
    pair<ll, int> ans = {0, 0};
    for(int ch : adj[i]) {
        pair<ll, int> p = dfs(ch);
        ans.first += p.first;
        ans.second += p.second;
    }
    if(ans.first < l[i]) {
        return {r[i], ans.second + 1};
    }
    return {min((ll)r[i], ans.first), ans.second};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        adj.resize(n);
        l.resize(n);
        r.resize(n);
        for(int i = 1; i < n; i++) {
            int x;
            cin >> x;
            x--;
            adj[x].push_back(i);
        }
        for(int i = 0; i < n; i++) {
            cin >> l[i] >> r[i];
        }
        cout << dfs(0).second << '\n';
        adj.clear();
        l.clear();
        r.clear();
    }
}