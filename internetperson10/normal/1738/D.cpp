#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<vector<int>> adj;

void solve() {
    int n;
    cin >> n;
    adj.clear();
    adj.resize(n+2);
    vector<int> o(n+2, 0);
    int k = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if(i <= x) k = i;
        adj[x].push_back(i);
        o[i]++;
    }
    stack<int> q;
    if(adj[0].size() == 0) q.push(n+1);
    else q.push(0);
    cout << k << '\n';
    while(q.size()) {
        int g = q.top();
        q.pop();
        if(g != 0 && g != n+1) {
            cout << g << ' ';
        }
        set<int> s;
        for(int x : adj[g]) {
            o[x]--;
            if(o[x] == 0) s.insert(x);
        }
        for(int x : s) {
            if(adj[x].size()) q.push(x);
        }
        for(int x : s) {
            if(adj[x].size() == 0) q.push(x);
        }
        s.clear();
    }
    cout << '\n';
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