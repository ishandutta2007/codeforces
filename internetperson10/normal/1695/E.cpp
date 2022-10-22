#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<set<pair<int, int>>> adj;
vector<bool> taken;
vector<vector<int>> dfses;
vector<pair<int, int>> bestPair;
vector<int> sizes;

void dfs(int x, int par = -1) {
    if(par != -1) dfses.back().push_back(x);
    for(auto it = adj[x].find(bestPair[x]); it != adj[x].end(); it++) {
        pair<int, int> p = *(it);
        bestPair[x] = p;
        int e, ch;
        tie(e, ch) = p;
        if(taken[e]) continue;
        taken[e] = true;
        if(e%2) taken[e-1] = true;
        else taken[e+1] = true;
        dfs(ch, x);
        dfses.back().push_back(x);
        it = adj[x].find(bestPair[x]);
    }
    if(par == -1) {
        if(dfses.back().size() == 0) dfses.pop_back();
        else sizes.push_back(dfses.back().size());
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    adj.resize(2*n);
    taken.resize(2*n, false);
    bestPair.resize(2*n);
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].insert({2*i, y});
        adj[y].insert({2*i+1, x});
    }
    for(int i = 0; i < 2*n; i++) {
        if(adj[i].size()) bestPair[i] = *(adj[i].begin());
    }
    for(int i = 0; i < 2*n; i++) {
        dfses.push_back(vector<int>());
        dfs(i);
    }
    bool ok = true;
    for(int g : sizes) {
        if(g == 2) ok = false;
    }
    if(!ok) {
        cout << "-1\n";
        return 0;
    }
    cout << n << ' ' << 2 << '\n';
    for(vector<int> v : dfses) {
        assert(v.size() % 2 == 0);
        for(int i = 0; i < v.size() / 2; i++) {
            cout << v[i] + 1 << ' ' << v[v.size() - 1 - i] + 1 << '\n';
        }
    }
    for(int g : sizes) {
        g /= 2;
        if(g % 2 == 1) {
            cout << "LR\n";
            for(int i = 1; i < g; i++) {
                if(i%2) cout << "UU\n";
                else cout << "DD\n";
            }
        }
        else {
            cout << "LR\n";
            for(int i = 0; i < g-2; i++) {
                if(i%2) cout << "DD\n";
                else cout << "UU\n";
            }
            cout << "LR\n";
        }
    }
    for(int g : sizes) {
        g /= 2;
        if(g % 2 == 1) {
            for(int i = 1; i < g; i++) {
                if(i%2) cout << "UU\n";
                else cout << "DD\n";
            }
            cout << "LR\n";
        }
        else {
            for(int i = 0; i < g; i++) {
                if(i%2) cout << "DD\n";
                else cout << "UU\n";
            }
        }
    }
}