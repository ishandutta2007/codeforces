//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int DIM = 5E5+7;
struct node{
    int u,v,c;
} Q[DIM];
int P[DIM],ans[DIM];
int F(int x){
    if (x==P[x])
        return x;
    return P[x] = F(P[x]);
}
int sz[DIM],col[DIM];
vector<pair<int,int> > G[DIM];
void calc(int v,int par){
    sz[v] = 1;
    for(auto [to,cl]:G[v]){
        if (to==par)
            continue;
        col[to] = col[v]^cl;
        calc(to,v);
        sz[v]+=sz[to];
    }
}
int CH[DIM],head[DIM],HP[DIM],ch_sz[DIM],ptr = 0,pos[DIM],depth[DIM];
vector<int> T[DIM],mod[DIM];
void hld(int v,int par,int chain){
    HP[v] = par;
    ++ch_sz[chain];
    pos[v] = ch_sz[chain];
    if (ch_sz[chain]==1)
        head[chain] = v;
    CH[v] = chain;
    int big = -1;
    for(auto [to,cl]:G[v]){
        if (to==par)
            continue;
        depth[to] = depth[v]+1;
        if (big==-1 || sz[big]<sz[to])
            big = to;
    }
    if (big!=-1) {
        hld(big, v, chain);
        for (auto [to,cl]:G[v]) {
            if (to == par || to == big)
                continue;
            hld(to, v, ++ptr);
        }
    }
}
void push(int t,int ind){
    if (mod[ind][t])
        mod[ind][t*2+1] = mod[ind][t*2+2] = T[ind][t*2+1] = T[ind][t*2+2] = 1;
    mod[ind][t] = 0;
}
void update(int t,int tl,int tr,int l,int r,int ind){
    if (tl>r || l>tr)
        return;
    if (l<=tl && tr<=r){
        T[ind][t] = mod[ind][t] = 1;
        return;
    }
    push(t,ind);
    int tm = (tl+tr)/2;
    update(t*2+1,tl,tm,l,r,ind);
    update(t*2+2,tm+1,tr,l,r,ind);
    T[ind][t] = max(T[ind][t*2+1],T[ind][t*2+2]);
}
int get(int t,int tl,int tr,int l,int r,int ind){
    if (l>tr || tl>r)
        return 0;
    if (l<=tl && tr<=r)
        return T[ind][t];
    push(t,ind);
    int tm = (tl+tr)/2;
    return max(get(t*2+1,tl,tm,l,r,ind),get(t*2+2,tm+1,tr,l,r,ind));
}
int get(int a,int b){
    int res = 0;
    while(CH[a]!=CH[b]){
        if (depth[head[CH[a]]]<depth[head[CH[b]]])
            swap(a,b);
        res = max(res,get(0,1,ch_sz[CH[a]],1,pos[a],CH[a]));
        a = HP[head[CH[a]]];
    }
    if (depth[a]>depth[b])
        swap(a,b);
    if (a!=b)
    res = max(res,get(0,1,ch_sz[CH[a]],pos[a]+1,pos[b],CH[a]));
    return res;
}
void paint(int a,int b){

    while(CH[a]!=CH[b]){
        if (depth[head[CH[a]]]<depth[head[CH[b]]])
            swap(a,b);
        update(0,1,ch_sz[CH[a]],1,pos[a],CH[a]);
        a = HP[head[CH[a]]];
    }
    if (depth[a]>depth[b])
        swap(a,b);
    if (a!=b)
    update(0,1,ch_sz[CH[a]],pos[a]+1,pos[b],CH[a]);

}
void solve(){
    int n,q;
    cin>>n>>q;
    for(int i = 1;i<=n;++i){
        P[i] = i;
    }
    for(int i = 1;i<=q;++i){
        cin>>Q[i].u>>Q[i].v>>Q[i].c;
        int u = Q[i].u,v = Q[i].v;
        if (F(u)!=F(v)){
            G[u].push_back({v,Q[i].c});
            G[v].push_back({u,Q[i].c});
            P[F(u)] = F(v);
            ans[i] = 1;
        }
    }
    for(int i = 1;i<=n;++i){
        if (sz[i]==0)
            calc(i,i);
    }
    for(int i = 1;i<=n;++i){
        if (CH[i]==0){
            hld(i,i,++ptr);
        }
    }
    for(int i = 1;i<=ptr;++i){
        T[i].resize(ch_sz[i]*4);
        mod[i].resize(ch_sz[i]*4);
        for(int j = 0;j<ch_sz[i]*4;++j)
            T[i][j] = 0,mod[i][j] = 0;
    }
    for(int i = 1;i<=n;++i)
        P[i] = i;
    for(int i = 1;i<=q;++i){
        int u = Q[i].u,v = Q[i].v,c = Q[i].c;
        if (ans[i]){
            cout<<"YES\n";
            P[F(u)] = F(v);
        }
        else{
            if (col[u]^col[v]^c==1 && !get(u,v))
                paint(u,v),cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    t = 1;
    while(t--)
        solve();
    return 0;
}