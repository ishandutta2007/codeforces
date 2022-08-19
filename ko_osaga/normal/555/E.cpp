#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <utility>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
 
struct disj{
    int pa[200005];
    void init(int n){
        for(int i=1; i<=n; i++) pa[i] = i;
    }
    int find(int x){
        return pa[x] = (pa[x] == x ? x : find(pa[x]));
    }
    bool uni(int p, int q){
        p = find(p), q = find(q);
        if(p == q) return 0;
        pa[q] = p; return 1;
    }
}disj, disj2;
 
int n, m, k;
vector<pi> graph[200005];
int dfn[200005], low[200005], pivx, comp[200005], piv;
pi edges[200005];
 
struct edg{
    int s, e, x;
};
 
vector<edg> ret;
 
void dfs1(int x, int p){
    dfn[x] = low[x] = ++pivx;
    for(auto &i : graph[x]){
        if(i.second == p) continue;
        if(!dfn[i.first]){
            dfs1(i.first, i.second);
            low[x] = min(low[x], low[i.first]);
            if(low[i.first] <= dfn[x]){
                ret.push_back({x, i.first, i.second});
            }
        }
        else{
            if(dfn[x] < dfn[i.first]){
                ret.push_back({i.first, x, i.second});
            }
            else{
                ret.push_back({x, i.first, i.second});
            }
            low[x] = min(low[x], dfn[i.first]);
        }
    }
}
 
void color(int x, int c){
    comp[x] = c;
    for(auto &i : graph[x]){
        if(comp[i.first]) continue;
        if(low[i.first] > dfn[x]) color(i.first, ++piv);
        else color(i.first, c);
    }
}
 
vector<pi> tree[200005];
int par[200005][18], dep[200005];
int up[200005], down[200005], pae[200005];
 
void dfs2(int x, int p){
    par[x][0] = p;
    for(int i=1; i<18; i++){
        par[x][i] = par[par[x][i-1]][i-1];
    }
    for(auto &i : tree[x]){
        if(i.first == p) continue;
        dep[i.first] = dep[x] + 1;
        dfs2(i.first, x);
    }
}
 
int lca(int s, int e){
    if(dep[s] > dep[e]) swap(s, e);
    int dx = dep[e] - dep[s];
    for(int i=0; i<=17; i++){
        if((dx >> i) & 1) e = par[e][i];
    }
    for(int i=17; i>=0; i--){
        if(par[s][i] != par[e][i]){
            s = par[s][i];
            e = par[e][i];
        }
    }
    if(s == e) return s;
    return par[s][0];
}
 
void dfs3(int x, int p){
    for(auto &i : tree[x]){
        if(i.first == p) continue;
        pae[i.first] = i.second;
        dfs3(i.first, x);
        up[x] += up[i.first];
        down[x] += down[i.first];
    }
}
 
pi prnt[200005];
 
int main(){
    scanf("%d %d %d",&n,&m,&k);
    disj.init(n);
    disj2.init(n);
    for(int i=0; i<m; i++){
        int s, e;
        scanf("%d %d",&s,&e);
        edges[i] = pi(s, e);
        graph[s].push_back(pi(e, i));
        graph[e].push_back(pi(s, i));
        disj.uni(s, e);
        disj2.uni(s, e);
    }
    int q = 0;
    for(int i=2; i<=n; i++){
        if(disj2.uni(1, i)){
            graph[1].push_back(pi(i, --q));
            graph[i].push_back(pi(1, q));
        }
    }
    dfs1(1, -1);
    color(1, ++piv);
    for(int i=1; i<=n; i++){
        for(auto &j : graph[i]){
            if(comp[i] != comp[j.first]){
                int s = comp[i];
                int e = comp[j.first];
                tree[s].push_back(pi(e, j.second));
            }
        }
    }
    dfs2(1, 0);
    for(int i=0; i<k; i++){
        int s, e;
        scanf("%d %d",&s,&e);
        if(disj.find(s) != disj.find(e)){
            puts("No");
            return 0;
        }
        s = comp[s];
        e = comp[e];
        int l = lca(s, e);
        up[s]++;
        up[l]--;
        down[e]++;
        down[l]--;
    }
    dfs3(1, 0);
    for(int i=2; i<=piv; i++){
        if(up[i] && down[i]){
            puts("No");
            return 0;
        }
        if(pae[i] < 0) continue;
        int s = edges[pae[i]].first;
        int e = edges[pae[i]].second;
        if(dep[comp[s]] < dep[comp[e]]) swap(s, e);
        if(down[i]) swap(s, e);
        ret.push_back({s, e, pae[i]});
    }
    puts("Yes");
}