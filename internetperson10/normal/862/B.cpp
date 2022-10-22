#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool taken[100001];
vector<vector<int> > adj;

int dfs(int n, bool b) {
    if(taken[n]) return 0;
    // cout << n << ' ' << b << '\n';
    int ans = 0;
    taken[n] = true;
    for(int i = 0; i < adj[n].size(); i++) {
        ans += dfs(adj[n][i], !b);
    }
    if(b) return ans+1;
    return ans;
}

int main() {
    int n, x, y;
    cin >> n;
    for(int i = 0; i < n; i++) {
        adj.push_back(vector<int>());
    }
    for(int i = 1; i < n; i++) {
        cin >> x >> y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    long long int k = (long long)(dfs(0, true));
    cout << (n-k)*k - (n-1) << '\n';
}