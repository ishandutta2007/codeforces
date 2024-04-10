#include <bits/stdc++.h>
using namespace std;

int dole[200005];
int sz[200005];
vector <pair <int, int>> graf[200005];
int res[200005];
int tr[200005];

int mn;

void dfs1(int v, int parent){
    sz[v] = 1;
    for(auto par : graf[v]){
        int c = par.first;
        int g = par.second;
        if(c == parent) continue;
        dole[v] += g;
        dfs1(c, v);
        dole[v] += dole[c];
        sz[v] += sz[c];
    }
}

void dfs2(int v, int parent){
    res[v] = dole[v] + tr[parent];
    tr[v] = res[v];
    mn = min(mn, res[v]);
    for(auto par : graf[v]){
        int c = par.first;
        int g = par.second;
        if(c == parent) continue;
        if(g == 0) tr[v]++;
        else tr[v]--;
        tr[v] -= dole[c];
        dfs2(c, v);
        if(g == 0) tr[v]--;
        else tr[v]++;
        tr[v] += dole[c];
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    int n;
    cin >> n;
    mn = n-1;
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back({b, 0});
        graf[b].push_back({a, 1});
    }
    dfs1(1, 0);
    dfs2(1, 0);
    cout << mn << "\n";
    for(int i=1; i<=n; i++){
        if(res[i] == mn) cout << i << " ";
    }
    return 0;
}