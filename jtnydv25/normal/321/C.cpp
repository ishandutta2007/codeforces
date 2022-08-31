// Centroid Decomposition
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back
#define sd(x) scanf("%d", &(x))
const int N = 1e5 + 10, logN = 20;
int tree[N], vis[N], parcen[N];
vector<int> concen[N], con[N];

int getSizes(int s, int p){
    tree[s] = 1;
    for(int v : con[s]) if(v != p && !vis[v]) tree[s] += getSizes(v, s);
    return tree[s];
}

int gc(int s, int p, int n){
    for(int v : con[s]){
        if(v != p && !vis[v]){
            if(2 * tree[v] > n) return gc(v, s, n);
        }
    }
    return s;
}
char col[N];
int decompose(int s, int p, int l){
    int root = gc(s, p, getSizes(s, p));
    col[root] = (char)('A' + l);
    parcen[root] = p;
    if(p > 0) concen[p].pb(root), concen[root].pb(p);
    vis[root] = 1;
    for(int v : con[root]){
        if(!vis[v]) decompose(v, root, l + 1);
    }
    return root;
}
int main(){
    int n, u, v;
    sd(n);
    for(int i = 0; i < n - 1; i++){
        sd(u), sd(v);
        con[u].pb(v); con[v].pb(u);
    }
    int centroid = decompose(1, 0, 0);
    for(int i = 1; i <= n; i++) printf("%c ", col[i]);
}