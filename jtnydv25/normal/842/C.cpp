#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d", &(x))
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define F first
#define S second
const int N = 2e5 + 10;
vi con[N];
int A[N], ans[N], g[N], G[N], par[N];
void add_edge(int a, int b){
    con[a].pb(b);
    con[b].pb(a);
}
void dfs1(int s, int p){
    g[s] = __gcd(g[p], A[s]);
    par[s] = p;
    for(int v : con[s]) if(v != p) dfs1(v, s);
}

void dfs2(int s, int p, int k){
    G[s] = __gcd(G[p], A[s]);
    ans[s] = max(ans[s], __gcd(G[s], k));
    for(int v : con[s]) if(v != p) dfs2(v, s, k);
}
int main(){
    int n;
    sd(n);
    for(int i = 1; i <= n; i++) sd(A[i]);
    for(int i = 1; i < n; i++){
        int u, v; sd(u); sd(v);
        add_edge(u, v);
    }
    dfs1(1, 0);
    for(int i = 1; i <= n; i++) ans[i] = g[i];
    for(int s = 1; s <= n; s++){
        if(s == 1 || g[s] <  g[par[s]]){
            ans[s] = max(ans[s], g[par[s]]);
            G[s] = 0;
            for(int v : con[s]) if(v != par[s]) dfs2(v, s, g[par[s]]);
        }
    }   
    for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
}