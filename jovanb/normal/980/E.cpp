#include <bits/stdc++.h>
using namespace std;

int par[1000005][22];
int depth[1000005];
bool ima[1000005];
vector <int> graf[1000005];

void dfs(int v, int parent, int dpt){
    par[v][0] = parent;
    for(int i=1; i<=20; i++){
        par[v][i] = par[par[v][i-1]][i-1];
    }
    depth[v] = dpt;
    for(auto c : graf[v]){
        if(c != parent) dfs(c, v, dpt+1);
    }
}

int nadji(int v){
    for(int i=20; i>=0; i--){
        if(!ima[par[v][i]]) v = par[v][i];
    }
    return par[v][0];
}

int main(){
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    dfs(n, 0, 0);
    ima[n] = 1;
    ima[0] = 1;
    k = n-k-1;
    for(int i=n-1; i>=1; i--){
        if(ima[i]) continue;
        int x = nadji(i);
        if(depth[i]-depth[x] > k) continue;
        k -= depth[i]-depth[x];
        int j = i;
        while(j != x){
            ima[j] = 1;
            j = par[j][0];
        }
    }
    for(int i=1; i<=n; i++) if(!ima[i]) cout << i << " ";
    return 0;
}