#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d", &(x))

const int N = 100005, mod = 1e9 + 7, logN = 18;
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}

vector<int> con[N];
int par[logN][N],depth[N], st[N], en[N], t = 0, a[N], b[N], c[N], d[N];
vector<int> queries[N];
pair<int, int> Q[N];
int tree1[N << 2], tree2[N << 2], lazy[N << 2];
map<int, int> mp[N];

void ADD(int & a, int b){
    a += b;
    if(a >= mod) a -= mod;
}
void go(int s, int e, int ind){
    int l = lazy[ind], num = e - s + 1;
    int x = mul(l, num);
    ADD(tree2[ind], add(mul(l, x), mul( add(l, l), tree1[ind])));
    ADD(tree1[ind], x);
    lazy[ind] = 0;
    if(s == e) return;
    ADD(lazy[ind << 1], l);
    ADD(lazy[(ind << 1) | 1], l);
}
void update(int s, int e, int ind, int l, int r, int k){
    go(s, e, ind);
    if(l > e || s > r) return;
    if(s >= l && e <= r){
        ADD(lazy[ind], k);
        go(s, e, ind);
        return;
    }
    int mid = (s + e) >> 1;
    update(s, mid, ind << 1, l, r, k);
    update(mid + 1, e, (ind << 1) | 1, l, r, k);
    tree1[ind] = add(tree1[ind << 1], tree1[(ind << 1) | 1]); 
    tree2[ind] = add(tree2[ind << 1], tree2[(ind << 1) | 1]);
}
int get(int s, int e, int ind, int l, int r){
    if(l > e || s > r) return 0;
    go(s, e, ind);
    if(s >= l && e <= r) return tree2[ind];
    int mid = (s + e) >> 1;
    return add(get(s, mid, ind << 1, l, r), get(mid + 1, e, (ind << 1) | 1, l, r)); 
}

void dfs(int s, int D, int p){
    st[s] = ++t;
    depth[s] = D;
    par[0][s] = p;
    for(int ind : con[s]){
        int v = a[ind] ^ b[ind] ^ s;
        if(v!=p){
            d[v] = add(d[s], c[ind]);
            dfs(v, D + 1, s);
            update(1, N, 1, st[v], st[v], d[v]);
        }
    }
    en[s] = t;
}
int val[N];
void dfs2(int s, int p){
    for(int v : queries[s]){
        int x = get(1, N, 1, st[v], en[v]);
        if(v == 1) val[s] = x;
        else mp[s][v] = x;
    }
    for(int ind : con[s]){
        int v = a[ind] ^ b[ind] ^ s;
        if(v != p){
            update(1, N, 1, 1, N, c[ind]);
            update(1, N, 1, st[v], en[v], sub(0, mul(2, c[ind])));
            dfs2(v, s);
            update(1, N, 1, 1, N, sub(0, c[ind]));
            update(1, N, 1, st[v], en[v], mul(2, c[ind]));
        }
    }
}
inline int GET(int s, int v){
    if(v == 1) return val[s];
    return mp[s][v];
}
int main(){
    int n, q, u, v;  
    sd(n); 
    for(int i = 1; i < n; i++){
        sd(a[i]); sd(b[i]); sd(c[i]);
        con[a[i]].push_back(i);
        con[b[i]].push_back(i);
    }
    dfs(1, 0, 0);
    sd(q);
    for(int i = 0; i < q; i++){
        sd(u); sd(v);
        queries[u].push_back(v);
        queries[u].push_back(1);
        Q[i] = {u, v};
    }
    dfs2(1, 0);
    for(int i = 0; i < q; i++){
        int u = Q[i].first, v = Q[i].second;
        int ans = sub(mul(2, GET(u, v)), GET(u, 1));
        printf("%d\n", ans);
    }
}