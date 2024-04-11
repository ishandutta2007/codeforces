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

const int N=1e6+9;

int n,m,c,s[N],t[N],ans[N],lazy[N];
pair<int,int> seg[N];
vector<int> g[N];
vector<pair<int,int> > query[N];

void shift(int,int,int);

pair<int,int> Min(pair<int,int> x,pair<int,int> y){
    if(y<x) swap(x,y);
    if(x.F == y.F) x.S+=y.S;
    return x;
}
void build(int id=1,int L=1,int R=n+1){
    seg[id].S=R-L;
    if(R<=L+1) return ;
    int mid=(L+R+1) >> 1;
    build(id*2+0, L, mid);
    build(id*2+1, mid, R);
}
void add(int id,int L,int R,int l,int r,int val){
    if(R<=l || r<=L) return ;
    if(l<=L && R<=r){
        lazy[id] += val;
        seg[id].F += val;
        return ;
    }
    int mid=(L+R+1)>>1;
    shift(id, L, R);
    add(id*2+0, L, mid, l, r, val);
    add(id*2+1, mid, R, l, r, val);
    seg[id]=Min(seg[id*2+0],seg[id*2+1]);
}
void shift(int id,int L,int R){
    int mid=(L+R+1) >> 1;
    add(id*2+0, L, mid, L, mid, lazy[id]);
    add(id*2+1, mid, R, mid, R, lazy[id]);
    lazy[id]=0;    
}
void DFS(int x,int par){
    f(i,0,query[x].size())
        add(1,1,n+1,query[x][i].F,query[x][i].S,1);
        
    f(i,0,g[x].size())
        if(g[x][i]!=par)
            DFS(g[x][i],x);
    ans[x]=n-(seg[1].F==0 ? seg[1].S : 0);
    
    f(i,0,query[x].size())
        add(1,1,n+1,query[x][i].F,query[x][i].S,-1);
}
void dfs(int x,int par){
    s[x]=++c;
    f(i,0,g[x].size())
        if(g[x][i]!=par)
            dfs(g[x][i],x);
    t[x]=c+1;
}

int main(){
    cin>>n>>m;
    f(i,1,n){
        int u,v;
        Gett(u,v);
        g[u].pb(v);
        g[v].pb(u);
    }
    build();
    dfs(1,0);
    
    f(i,0,m){
        int u,v;
        Gett(u,v);
        query[u].pb(mp(s[v],t[v]));
        query[u].pb(mp(s[u],t[u]));
        query[v].pb(mp(s[u],t[u]));
        query[v].pb(mp(s[v],t[v]));
    }
    
    DFS(1,0);
    f(i,1,n+1) cout<<ans[i]-(0<ans[i])<<" ";
}