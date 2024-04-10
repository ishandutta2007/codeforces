#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define ll long long
const int N = 1e5 + 10, logN = 17, mod = 1e9 + 7;

inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline int powr(int a, ll b){
    int x = 1 % mod;
    while(b){
        if(b & 1) x = mul(x, a);
        a = mul(a, a);
        b >>= 1;
    }
    return x;
}
inline int inv(int a){ return powr(a, mod - 2);}

int tree[N], vis[N], parcen[N];
vector<int> concen[N], con[N];
int par[logN][N],depth[N], prod[logN][N], black[logN][N];
vector<pair<int, int> > con2[N];

void dfs(int s, int d, int p){
    depth[s] = d;
    par[0][s] = p;
    for(int i = 0; i < con[s].size(); i++){
        int v = con[s][i];
        if(v != p){
            dfs(v, d + 1, s);
            prod[0][v] = con2[s][i].F;
            black[0][v] = con2[s][i].S;
        }
    }
}
void pre(int n){
    for(int j = 1;j<logN;j++)
        for(int i = 1;i<=n;i++){
            int parent = par[j - 1][i];
            par[j][i] = par[j-1][parent];
            prod[j][i] = mul(prod[j - 1][i], prod[j - 1][parent]);
            black[j][i] = black[j - 1][i] + black[j - 1][parent];
        }
}

// get lca, # black, prod of path from a to b
inline pair<int, pair<int, int> > get(int a, int b){
    int P = 1, B = 0, L = 0;

    if(depth[a]<depth[b]) swap(a,b);
    int l = depth[a]-depth[b];
    for(int i = 0;i < logN; i++){
        if(l&(1<<i)){
            P = mul(P, prod[i][a]);
            B += black[i][a];
            a = par[i][a];
        }
    }

    if(a == b) return {a, {P, B}};

    for(int i = logN-1; i >= 0; i--){
        if(par[i][a]!=par[i][b]){
            P = mul(P, mul(prod[i][a], prod[i][b]));
            B += black[i][a] + black[i][b];
            a = par[i][a];
            b = par[i][b];
        }
    }
    return {par[0][a], {mul(P, mul(prod[0][b], prod[0][a])), B + black[0][a] + black[0][b]}};
}
vector<int> subtree[N];
int ans = 1, _inv = 1, FREQ[N + 10];
vector<pair<int, pii> > vvec;
const int offset = 2 * N;

#define LSOne(S) (S & (-S))
int bit[4][4 * N];
int changes1[N << 5], changes2[N << 5], cntr1 = 0, cntr2 = 0;
void PRE(){
    for(int i = 0; i < 4 * N; i++) bit[0][i] = bit[2][i] = 1;
    for(int i = 0; i < N; i++) FREQ[i] = 1;
}

void insert1(int x, int y){
    x += offset;
    for (; x < 4 * N; x += LSOne(x)){
        bit[1][x]++;
        bit[0][x] = mul(bit[0][x], y);
        changes1[cntr1++] = x;
    }
}
void insert2(int x, int y){
    x += offset;
    for (; x < 4 * N; x += LSOne(x)){
        bit[3][x]++;
        bit[2][x] = mul(bit[2][x], y);
        changes2[cntr2++] = x;
    }
}
pii get1(int x){
    int sz = 0, P = 1; x += offset;
    for (; x; x -= LSOne(x)){
        sz += bit[1][x];
        P = mul(P, bit[0][x]);
    }
    return {P, sz};
}
pii get2(int x){
    int sz = 0, P = 1; x += offset;
    for (; x; x -= LSOne(x)){
        sz += bit[3][x];
        P = mul(P, bit[2][x]);
    }
    return {P, sz};
}
void clear(){
    for(int i = 0; i < cntr1; i++) bit[0][changes1[i]] = 1, bit[1][changes1[i]] = 0;
    for(int i = 0; i < cntr2; i++) bit[2][changes2[i]] = 1, bit[3][changes2[i]] = 0;
    cntr1 = cntr2 = 0;
}

int getSizes(int s, int p){
    tree[s] = 1;
    for(int v : con[s]) if(v != p && !vis[v]) tree[s] += getSizes(v, s);
    return tree[s];
}

int getcentroid(int s, int p, int n){
    for(int v : con[s]){
        if(v != p && !vis[v]){
            if(2 * tree[v] > n) return getcentroid(v, s, n);
        }
    }
    return s;
}

bool cmp(int a, int b){ return subtree[a].size() < subtree[b].size();}
int decompose(int s, int p){
    int root = getcentroid(s, p, getSizes(s, p)), node = root;
    subtree[root] = {root};
    vector<int> child;
    parcen[root] = p;
    if(p > 0) concen[p].pb(root), concen[root].pb(p);
    vis[root] = 1;
    for(int v : con[root]){
        if(!vis[v]){
            int root2 = decompose(v, root);
            child.push_back(root2);
            for(int x : subtree[root2]) subtree[root].pb(x);
        }
    }
    sort(child.begin(), child.end(), cmp);
    clear();
    insert1(0, 1);
    insert2(0, 1);
    for(int c : child){
        vvec.clear();
        for(int i : subtree[c]){
            pair<int, pii> v = get(i, root); vvec.push_back(v);
            int x1 = v.S.S, y1 = depth[i] + depth[node] - 2*depth[v.F] - x1;
            int P = v.S.F;
            pii Q1 = get1(2 * y1 - x1); // ratio <= 2
            pii Q2 = get2(y1 - 2 * x1 - 1); // ratio < 1/2
            int freq = Q1.S - Q2.S;
            ans = mul(ans,Q1.F);
            _inv = mul(_inv, Q2.F);
            FREQ[freq] = mul(FREQ[freq], P);
        }
        int cntr = 0;
        if(c != child.back())
        for(int i : subtree[c]){
            pair<int, pii> v = vvec[cntr++];
            int x1 = v.S.S, y1 = depth[i] + depth[node] - 2*depth[v.F] - x1;
            int P = v.S.F;
            insert1(x1 - 2 * y1, P);
            insert2(2 * x1 - y1, P);
        }
    }
    return root;
}

int main(){
    PRE();
    int n, u, v, x, c;
    sd(n);
    for(int i = 1; i < n; i++){
        sd(u), sd(v); sd(x); sd(c);
        con[u].pb(v); con[v].pb(u);
        con2[u].pb({x, c});
        con2[v].pb({x, c});
    }
    dfs(1, 0, 0);
    pre(n);
    decompose(1, 0);
    for(int i = 0; i < N; i++){
        ans = mul(ans, powr(FREQ[i], i));
    }
    printf("%d\n", mul(ans, inv(_inv)));
}