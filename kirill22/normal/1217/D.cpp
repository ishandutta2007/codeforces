#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<bool> used;
vector<vector<int > > g(6000);
vector<vector<int > > g1(6000);
vector<int> top_sortik;
vector<int> comp;
vector<int> ans;
void top_sort(int v){
    used[v]=true;
    for(int i=0;i<g[v].size();i++){
        int x=g[v][i];
        if (!used[x]){
            top_sort(x);
        }

    }
    top_sortik.push_back(v);
}
void dfs(int v,int color){
    used[v]=true;
    comp[v]=color;
    for(int i=0;i<g1[v].size();i++){
        int x=g1[v][i];
        if (!used[x]){
            dfs(x,color);
        }

    }
}
vector<vector<pair<int,int>>> g2(6000), g3(6000);
void D(int v) {
    used[v] = true;
    for (auto c : g2[v]) {
        if (comp[v] == comp[c.first] && ans[c.second] == 0) {
            ans[c.second] = 1;
        }
    }
    for (auto c : g3[v]) {
        if (comp[v] == comp[c.first] && ans[c.second] == 0) {
            ans[c.second] = 2;
        }
    }
}

signed main() {
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g1[y].push_back(x);
        g2[x].push_back({y, i});
        g3[y].push_back({x, i});
    }
    comp.resize(n,0);
    used.resize(n,false);
    for(int i=0;i<n;i++){
        if (! used[i]){
            top_sort(i);
        }
    }
    reverse(top_sortik.begin(),top_sortik.end());
    for(int i=0;i<n;i++){
        used[i]=false;
    }
    int co=0;
    for(int i=0;i<n;i++){
        if (!used[top_sortik[i]]){
            co++;
            dfs(top_sortik[i],co);
        }
    }
    if (co == n) {
            cout << 1 << endl;
       for (int i = 0; i < m; i++) {
        cout << 1 << " ";
       }
       return 0;
    }
    for(int i=0;i<n;i++){
        used[i]=false;
    }
    ans.resize(m, 0);
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            D(i);
        }
    }
    cout << 2 << endl;
    for (auto c : ans) {
        cout << max(c, 1ll) << " ";
    }
}