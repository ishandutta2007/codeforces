#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define All(x) x.begin(),x.end()
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=5e5+9;
 
int n,t,u,b,a[N],mt[N],topo[N],mark[N]; //mt : mark time. Fuck
vector<int> g[N],fen[N];
vector<pair<int,int> > Fen[N];
 
void dfs(int x);
 
void Add(int x,int y,int val){
    while(y<sz(fen[x])){ fen[x][y]+=val; y+=(y&-y); }
}
int Get(int x,int y){
    int res=0;
    while(y){ res+=fen[x][y]; y-=(y&-y); }
    return res;
}
void add_Fen(int x,pair<int,int> p){
    while(x<N){
        Fen[x].pb(p);
        x+=(x&-x);
    }    
}
void read(){
    cin>>n;
    fill(mt,mt+N,n+1);
    f(i,1,n+1){
        gett(a[i]);
        if(a[i]<0) a[i]=n+1;
        mt[a[i]]=i;
    }
}
void make(){
    f(i,1,N) Fen[i].pb(mp(0,0));
    f(i,1,n+1)
        add_Fen(i,mp(mt[i],i));
    f(i,1,N){
        sort(All(Fen[i]));
        reverse(Fen[i].begin()+1,Fen[i].end());
    }
    f(i,1,N){
        while(fen[i].size()<(i&-i)+1)
            fen[i].pb(0);
        f(j,1,fen[i].size())
            Add(i,j,1);
    }
}
void find_and_mark(int x,pair<int,int> p){
    int l=0,r=Fen[x].size(),mid;
    while(l+1<r){
        mid=(l+r)/2;
        if(p<=Fen[x][mid]) l=mid;
        else r=mid;
    }
    Add(x,l,-1);
}
void set_mark(int x){
    mark[x]=1;
    pair<int,int> p=mp(mt[x],x);
    while(x<N){
        find_and_mark(x,p);
        x+=(x&-x);
    }
}
void dfs_adj(int x,int y,int u){
    // optimize It !
    int l=0,r=fen[x].size(),mid;
    while(l+1<r){
        mid=(l+r)/2;
        if(y<Fen[x][mid].F) l=mid;
        else r=mid;
    }
    int k=Get(x,l);
    while(k){
        int li=0,ri=l;
        while(li+1<ri){
            mid=(li+ri)/2;
            if(Get(x,mid)<1) li=mid;
            else ri=mid;
        }
        dfs(Fen[x][ri].S);
    	k=Get(x,l);
	}
}
void find_adj(int x,int y,int u){
    while(x){ dfs_adj(x,y,u);  x-=(x&-x); }
}
void dfs(int x){
    set_mark(x);
    find_adj(a[x]-1,x,x);
    if(!mark[mt[x]] && mt[x]!=n+1) dfs(mt[x]);
    topo[x]=++t;
}
void solve(){
    f(i,1,n+1)
        if(!mark[i])
            dfs(i);
    f(i,1,n+1) printf("%d ",topo[i]);
}
 
int main(){
    read();
    make();
    solve();
}