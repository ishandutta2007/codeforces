#include <bits/stdc++.h>
using namespace std;
#define int long long
struct SegTree{
    vector<pair<int,int>>arr;
    vector<int>val;
    int size;
    void build(int x, int lx, int rx){
        if(rx-lx==1){
            arr[x].second = lx;
            return;
        }
        int m = (lx+rx)/2;
        build(2*x+1,lx,m);
        build(2*x+2,m,rx);
        arr[x] = max(arr[2*x+1] , arr[2*x+2]);
    }
    void build(){
        build(0,0,size);
    }
    void pushdown(int x, int len){
        if(val[x]==0)return;
        arr[x].first+=val[x];
        if(len>1){
            val[2*x+1]+=val[x];
            val[2*x+2]+=val[x];
        }
        val[x] = 0;
    }
    void init(int n){
        size = 1;
        while(size<n)size*=2;
        arr.resize(size*2);
        val.resize(size*2);
    }
    void set(int l, int r, int v, int x, int lx, int rx){
        if(l>=rx||lx>=r){
            pushdown(x,rx-lx);
            return;
        }
        if(lx>=l&&rx<=r){
            val[x]+=v;
            pushdown(x,rx-lx);
            return;
        }
        pushdown(x,rx-lx);
        int m = (lx+rx)/2;
        set(l,r,v,2*x+1,lx,m);
        set(l,r,v,2*x+2,m,rx);
        arr[x] = max(arr[2*x+1],arr[2*x+2]);
    }
    void set(int l, int r, int v){
        set(l,r,v,0,0,size);
    }
    pair<int,int> query(int l, int r, int x, int lx, int rx){
        if(l>=rx||lx>=r){
            pushdown(x,rx-lx);
            return {-(int)2e9,0};
        }
        if(lx>=l&&rx<=r){
            pushdown(x,rx-lx);
            return arr[x];
        }
        pushdown(x,rx-lx);
        int m = (lx+rx)/2;
        pair<int,int> s1 = query(l,r,2*x+1,lx,m);
        pair<int,int> s2 = query(l,r,2*x+2,m,rx);
        return max(s1,s2);
    }
    pair<int,int> query(int l, int r){
        return query(l,r,0,0,size);
    }
};
int n,k;
int mxn = 200005;
vector<vector<int>>adj(mxn);
vector<int>sz(mxn);
vector<int>rev(mxn);
vector<int>loc(mxn);
vector<int>parent(mxn);
int timer = 0;
void dfs(int u, int p){
    timer++;
    sz[u] = 1;
    parent[u] = p;
    loc[u] = timer;
    rev[timer] = u;
    for(int nxt: adj[u]){
        if(nxt==p)continue;
        dfs(nxt,u);
        sz[u]+=sz[nxt];
    }
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 1; i<n; i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,0);
    int leaves = 0;
    for(int i = 2; i<=n; i++){
        if(sz[i]==1)leaves++;
    }
    if(k<=leaves){
        SegTree segtree;
        segtree.init(n+5);
        segtree.build();
        vector<bool>vis(n+5);
        for(int i = 1; i<=n; i++){
            //cout << sz[i] << " ";
            segtree.set(loc[i],loc[i]+sz[i],1);
            if(sz[i]!=1){
                segtree.set(loc[i],loc[i]+1,-(int)1e9);
            }
        }
       // cout << "\n";
        for(int j = 0; j<k; j++){
            pair<int,int>v = segtree.query(1,n+1);
            v.second = rev[v.second];
            int cur = v.second;
            //cout << cur << "\n";
            while(!vis[cur]&&cur>0){
                vis[cur] = true;
                segtree.set(loc[cur],loc[cur]+sz[cur],-1);
                cur = parent[cur];
            }
            segtree.set(loc[v.second],loc[v.second]+1,-(int)1e9);
        }
        int blue = 0;
        for(int i = 1; i<=n; i++){
            if(!vis[i])blue++;
        }
        //cout << blue << "\n";
        int ans = (int)1e18;
        for(int i = 0; i<=blue; i++){
            ans = min(ans,(n-i-k)*(k-i));
        }
        cout << ans << "\n";
    }
    else{
        int ans = 0;
        for(int i = leaves; i<=k; i++){
            ans = max(ans,(n-i)*i);
        }
        cout << ans << "\n";
    }
    return 0;
}