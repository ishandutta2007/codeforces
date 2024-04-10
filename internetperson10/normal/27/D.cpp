#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

bool ok = true;

vector<pair<int, int>> nums;
vector<int> assign;
vector<vector<int>> adj;

void dfs(int x) {
    for(int ch : adj[x]) {
        if(assign[ch] != -1) {
            if(assign[x] == -1) assign[x] = 1 - assign[ch];
            if(assign[x] + assign[ch] != 1) ok = false;
        }
    }
    for(int ch : adj[x]) {
        if(assign[ch] == -1) dfs(ch);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    nums.resize(m);
    adj.resize(m);
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        if(x > y) swap(x, y);
        nums[i] = {x, y};
    }
    for(int i = 0; i < m; i++) {
        for(int j = i+1; j < m; j++) {
            int v[4];
            v[0] = nums[i].first;
            v[1] = nums[i].second;
            v[2] = nums[j].first;
            v[3] = nums[j].second;
            sort(v, v+4);
            pair<int, int> p1 = {v[0], v[2]};
            if((p1 == nums[i] || p1 == nums[j]) && !(v[0] == v[1] || v[1] == v[2] || v[2] == v[3])) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    assign.resize(m, -1);
    for(int i = 0; i < m; i++) {
        if(assign[i] == -1) {
            assign[i] = 0;
            dfs(i);
        }
    }
    if(!ok) {
        cout << "Impossible\n";
        return 0;
    }
    for(int g : assign) {
        if(g) cout << 'i';
        else cout << 'o';
    }
}