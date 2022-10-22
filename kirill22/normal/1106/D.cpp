#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set <int> g[100001],s;
bool vis[100001];
int main(){
    int j,k,n,m,u,v;
    cin >> n >> m;
    for(int i=1;i<=m;i++) {
            cin >> u >> v;
            g[u].insert(v);
            g[v].insert(u);
    }
    s.insert(1);
    while(s.size()){
        u=*s.begin();
        vis[u] = 1;
        cout << u <<" ";
        s.erase(s.begin());
        for(auto v:g[u]) {
                if(!vis[v]) {
                        s.insert(v);
                }
        }
    }
}