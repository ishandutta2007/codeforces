//#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 1e5+7;
const int LOG = 18;
int A[N],tin[N],tout[N],P[N][LOG],in_pos[N],timer = 0;
vector<int> G[N];
ll T[N*2],mod[N*2];

void dfs(int v,int par){
    tin[v] = ++timer;
    P[v][0] = par;
    for(int i = 1;i<LOG;++i)
        P[v][i] = P[P[v][i-1]][i-1];
    in_pos[timer] = v;

    for(int to:G[v]){
        if (to==par)
            continue;
        dfs(to,v);
    }
    tout[v] = timer;
}
void push(int t,int tl,int tr){
    int tm = (tl+tr)>>1;
    T[t+1]+=mod[t]*(tm+1-tl);
    mod[t+1]+=mod[t];
    T[t+(tm-tl+1)*2]+=mod[t]*(tr-tm);
    mod[t+(tm-tl+1)*2]+=mod[t];
    mod[t] = 0;
}
void buildtree(int t,int tl,int tr){
    if (tl==tr){
        T[t] = A[in_pos[tl]];
        return;
    }
    int tm = (tl+tr)>>1;

    buildtree(t+1,tl,tm);
    buildtree(t+(tm-tl+1)*2,tm+1,tr);
    T[t] = T[t+1]+T[t+(tm-tl+1)*2];
}
void update(int t,int tl,int tr,int l,int r,ll delta){
    if (l>tr || tl>r)
        return;
    if (l<=tl && tr<=r){
        T[t] += delta*(tr-tl+1);
        mod[t] += delta;
        return;
    }
    push(t,tl,tr);
    int tm = (tl+tr)>>1;
    update(t+1,tl,tm,l,r,delta);
    update(t+(tm-tl+1)*2,tm+1,tr,l,r,delta);
    T[t] = T[t+1]+T[t+(tm-tl+1)*2];
}
ll get(int t,int tl,int tr,int l,int r){
    if (tl>r || l>tr)
        return 0;
    if (l<=tl && tr<=r){
        return T[t];
    }
    push(t,tl,tr);
    int tm = (tl+tr)>>1;
    return get(t+1,tl,tm,l,r)+get(t+(tm-tl+1)*2,tm+1,tr,l,r);
}
int is_par(int a,int b){
    return tin[a]<=tin[b] && tout[b]<=tout[a];
}
int lca(int a,int b){
    if (is_par(a,b))
        return a;
    for(int i = LOG-1;i>=0;--i)
        if (!is_par(P[a][i],b))
            a = P[a][i];
        return P[a][0];
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i = 1;i<=n;++i)
        cin>>A[i];
    for(int i = 1;i<n;++i){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,1);
    buildtree(0,1,n);
    int root = 1;
    while(q--){
        int type;
        cin>>type;
        if (type==1){
            cin>>root;
        }
        if (type==2){
            int u,v,delta;
            cin>>u>>v>>delta;
            int par = lca(u,v);
            if (is_par(par,lca(u,root)))
                par = lca(u,root);
            if (is_par(par,lca(v,root)))
                par = lca(v,root);

            if (is_par(par,root)) {
                update(0,1,n,1,n,delta);
                int sub = root;
                for(int i = LOG-1;i>=0;--i){
                    if (!is_par(P[P[sub][i]][0],par))
                        sub = P[sub][i];
                }
                if (!is_par(P[sub][0],par))
                    sub = P[sub][0];
                if (par!=root)
                    update(0,1,n,tin[sub],tout[sub],-delta);
            }
            else{
                update(0,1,n,tin[par],tout[par],delta);
            }
        }
        if (type==3){
            int v;
            cin>>v;
            if (is_par(v,root)){
                int sub = root;
                for(int i = LOG-1;i>=0;--i){
                    if (!is_par(P[P[sub][i]][0],v))
                        sub = P[sub][i];
                }
                if (!is_par(P[sub][0],v))
                    sub = P[sub][0];
                cout<<get(0,1,n,1,n)-(v!=root?get(0,1,n,tin[sub],tout[sub]):0)<<endl;
            }
            else{
                cout<<get(0,1,n,tin[v],tout[v])<<endl;
            }
        }
    }
    return 0;
}