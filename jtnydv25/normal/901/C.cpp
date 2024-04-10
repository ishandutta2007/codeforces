#include <bits/stdc++.h>
using namespace std;

#define VI vector<int>
#define PB push_back
#define sd(n) scanf("%d", &(n))
#define ll long long
const int N = 300005, M = N * 21 * 2;
VI tree[N],g[N];//edge list representation of graph
int U[N],V[N],vis[N],arr[N],T,dsu[N];
bool isbridge[N]; // if i'th edge is a bridge edge or not
int adj(int u,int e) {
    return U[e]^V[e]^u;
}
int f(int x) {
    return dsu[x]=(dsu[x]==x?x:f(dsu[x]));
}
void merge(int a,int b) {
    dsu[f(a)]=f(b);
}
int dfs0(int u,int edge) { //mark bridges
    vis[u]=1;
    arr[u]=T++;
    int dbe = arr[u];
    for(auto e : g[u]) {
        int w = adj(u,e);
        if(!vis[w])dbe = min(dbe,dfs0(w,e));
        else if(e!=edge)dbe = min(dbe,arr[w]);
    }
    if(dbe == arr[u] && edge!=-1)isbridge[edge]=true;
    else if(edge!=-1)merge(U[edge],V[edge]);
    return dbe;
}
void buildBridgeTree(int n,int m) {
    for(int i=1; i<=n; i++)dsu[i]=i;
    for(int i=1; i<=n; i++)if(!vis[i])dfs0(i,-1);
}
int comp[N];
map<int, int> compress;

int nxt[N];
vector<int> vec[N];

int brute(int l, int r){
    int ans =0 ;
    for(int i = l; i <= r; i++) ans += min(r + 1, nxt[i]) - i;
    return ans;
}

int lft[M], rgt[M];
ll val[M];
int cnt;
struct persistent_segtree{
    int root[N];
    persistent_segtree(){root[0] = 0;}  
    void add(int v, int V, int rt, int newrt, int s = 0, int e = N){
        val[newrt] = val[rt] + V;
        if(s == e){
            return;
        }
        int mid = (s + e) >> 1;
        if(v <= mid){
            // right remains same
            rgt[newrt] = rgt[rt];
            lft[newrt] = ++cnt;
            add(v, V, lft[rt], lft[newrt], s, mid);
        }
        else{
            // left remains same
            lft[newrt] = lft[rt];
            rgt[newrt] = ++cnt;
            add(v, V, rgt[rt], rgt[newrt], mid + 1, e);
        }
    }
    void add(int i, int v, int V){
        root[i] = ++cnt;
        add(v, V, root[i - 1], root[i]);
    }
    
    ll get(int l, int r, int rt, int s = 0, int e = N){
        if(!rt || l > e || s > r) return 0LL;
        if(s >= l && e <= r) return val[rt];
        int mid = (s + e) >> 1;
        return get(l, r, lft[rt], s, mid) + get(l, r, rgt[rt], mid + 1, e);
    }
    ll GET(int l, int r, int x, int y){
        return get(x, y, root[r]) - get(x, y, root[l - 1]);
    }
} tree1, tree2;
ll sm(int n){
    return (n * 1ll * (n + 1)) / 2;
}
ll getV(int l, int r){
    ll sub = sm(r) - sm(l - 1);
    ll sum1 = tree2.GET(l, r, r + 2, N);
    ll sum2 = tree1.GET(l, r, 0, r+1);
    return sum2 + sum1 * (r + 1) - sub;
}
set<int> st;
int main(){
    int n, m, q;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++){
        scanf("%d %d", U + i, V + i);
        g[U[i]].PB(i);
        g[V[i]].PB(i);
    }
    buildBridgeTree(n, m);
    int CNT = 0;
    for(int i = 1; i <= n; i++) st.insert(f(i));
    for(int x : st) compress[x] = ++CNT;
    for(int i = 1; i <= n; i++){
        comp[i] = compress[f(i)];
        vec[comp[i]].PB(i);
        nxt[i] = n + 1;
    }
    for(int i = 1; i <= CNT; i++){
        if(vec[i].size() > 1)nxt[vec[i][0]] = vec[i].back();
    }
    for(int i = n-1; i >= 1; i--) nxt[i] = min(nxt[i], nxt[i + 1]);
    for(int i = 1; i <= n; i++){
        tree1.add(i, nxt[i], nxt[i]);
        tree2.add(i, nxt[i], 1);
    }
    sd(q);
    while(q--){
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%lld\n", getV(l, r));
    }
}