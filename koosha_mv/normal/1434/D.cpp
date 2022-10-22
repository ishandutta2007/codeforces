#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=5e5+99;
 
int n,m,c,rt,fa,q[N],ans[N],h[N],a[N],s[N],t[N],w[N],edge[N][2];
vector<pair<int,int> > g[N];
int lazy[4*N];
pair<int,int> seg[4*N];
 
void shift(int ,int ,int );
 
void build(int id=1,int L=1,int R=n+1){
    if(R<=L) return ;
    if(L+1==R){
        seg[id].S=0;
        seg[id].F=h[a[L]];
        if(w[a[L]]) swap(seg[id].F,seg[id].S);
        return ;
    }
    int mid=(L+R+1)>>1;
    build(id*2+0,L,mid);
    build(id*2+1,mid,R);
    seg[id].F = max(seg[id*2+0].F,seg[id*2+1].F);
    seg[id].S = max(seg[id*2+0].S,seg[id*2+1].S);
}
void swich(int id,int L,int R,int l,int r){
    if(R<=l || r<=L) return ;
    if(l<=L && R<=r){
        lazy[id] ^= 1;
        swap(seg[id].F,seg[id].S);
        return ;
    }
    int mid=(L+R+1)>>1;
    shift(id, L, R);
    swich(id*2+0, L, mid, l, r);
    swich(id*2+1, mid, R, l, r);
    seg[id].F = max(seg[id*2+0].F,seg[id*2+1].F);
    seg[id].S = max(seg[id*2+0].S,seg[id*2+1].S);
}
void shift(int id,int L,int R){
    int mid=(L+R+1) >> 1;
    if(lazy[id]==0) return ;
    swich(id*2+0,L,mid,L,mid);
    swich(id*2+1,mid,R,mid,R);
    lazy[id]=0;    
}
 
//muy
 
void dfs1(int x,int dist,int par=0){
    if(fa<dist) fa=dist,rt=x;
    f(i,0,g[x].size())
        if(g[x][i].F!=par)
            dfs1(g[x][i].F,dist+1,x);
}
void dfs2(int x,int dist,int par,int S){
    h[x]=dist;
    a[++c]=x;
    s[x]=c;
    f(i,0,g[x].size())
        if(g[x][i].F!=par)
            dfs2(g[x][i].F,dist+1,x,S^g[x][i].S);
    t[x]=c+1;
    w[x]=S;
}
void solve(int rt){
    f(i,0,4*N) seg[i].F=seg[i].S=lazy[i]=0;
    c=0;
    dfs2(rt,0,0,0);
    build();
    f(i,0,m){
        int u;
        if(h[edge[q[i]][1]]<h[edge[q[i]][0]]) u=edge[q[i]][0];
        else u=edge[q[i]][1];
        swich(1,1,n+1,s[u],t[u]);
        maxm(ans[i],seg[1].F);
    }
}
 
int main(){
    cin>>n;
    f(i,1,n){
        int u,v,t;
        Gett(u,v);
        gett(t);
        edge[i][0]=u;
        edge[i][1]=v;
        g[u].pb(mp(v,t));
        g[v].pb(mp(u,t));
    }
    cin>>m;
    f(i,0,m)
        cin>>q[i];
        
    fa=0;
    dfs1(1,0);
    solve(rt);
    
    fa=0;
    dfs1(rt,0);
    solve(rt);
    
    f(i,0,m) cout<<ans[i]<<'\n';
}