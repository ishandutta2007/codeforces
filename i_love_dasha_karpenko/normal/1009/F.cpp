//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

const int N = 1E6+7;
vector<int> G[N];
int tin[N],tout[N],timer = 0,depth[N],val[N],sz[N],ans[N];
struct tnode{
    int lnode,rnode,val;
};
tnode T[N*8];
int ptr = 0,n;
int new_node(){
    T[++ptr] = {-1,-1,0};
    return ptr;
}

void update(int t,int tl,int tr,int pos,int val){
    if (tl>pos || tr<pos)
        return;
    if (tl==tr){
        T[t].val++;
        return;
    }
    if (T[t].lnode==-1)
        T[t].lnode = new_node();
    if (T[t].rnode==-1)
        T[t].rnode = new_node();
    int tm = (tl+tr)/2;
    update(T[t].lnode,tl,tm,pos,val);
    update(T[t].rnode,tm+1,tr,pos,val);
    T[t].val = max(T[T[t].lnode].val,T[T[t].rnode].val);
}
ll get(int t,int tl,int tr,int val){
    if (T[t].val<val)
        return n;
    if (tl==tr)
        return tl;
    if (T[t].lnode==-1)
        T[t].lnode = new_node();
    if (T[t].rnode==-1)
        T[t].rnode = new_node();
    int tm = (tl+tr)/2;
    int p1 = get(T[t].lnode,tl,tm,val);
    if (p1!=n)
        return p1;
    return get(T[t].rnode,tm+1,tr,val);
}

void dfs(int v,int par,int root){
    tin[v] = ++timer;
    val[timer] = v;
    depth[v] = depth[par]+1;
    int big = -1;
    for(auto to:G[v]){
        if (to==par)
            continue;
        if (big==-1 || sz[to]>sz[big])
            big = to;
    }
    if (big!=-1){
        dfs(big,v,root);
        for(auto to:G[v]){
            if (to==big || to==par)
                continue;
            int vl = new_node();
            dfs(to,v,vl);
            ptr = vl-1;
            for(int i = tin[to];i<=tout[to];++i){
                update(root,1,n,depth[val[i]],1);
            }
        }
        update(root,1,n,depth[v],1);
        ans[v] = get(root,1,n,T[root].val)-depth[v];
    }
    else{
        update(root,1,n,depth[v],1);
    }
    tout[v] = timer;
}
void calcsz(int v,int par){
    sz[v] = 1;
    for(auto to:G[v]){
        if (to==par)
            continue;
        calcsz(to,v);
        sz[v]+=sz[to];
    }
}
void solve(){

    cin>>n;
    for(int i = 1;i<n;++i){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    calcsz(1,1);

    dfs(1,1,new_node());
    for(int i = 1;i<=n;++i)
        cout<<ans[i]<<endl;
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t;
    t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}