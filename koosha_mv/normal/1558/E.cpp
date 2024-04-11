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
 
const int N=1005,inf=1e9+9;
 
int n,m,t,u,v,x,a[N],b[N],vis[N],mark[N];
pair<int,int> E[2*N];
pair<int,int> par[N];
vector<int> g[N];
 
void pre(){
   u=v=0;
   par[1].S=x;
   f(i,2,n+1) vis[i]=0,par[i]=mp(0,0);
   f(i,1,n+1) g[i].clear();
   f(i,0,m){
   	int u=E[i].F,v=E[i].S;
   	if(mark[u]==0) u=1;
   	if(mark[v]==0) v=1;
   	if(u!=v){
     		g[u].pb(v);
     		g[v].pb(u);
   	}
   }
}
void dfs(int x){
   vis[x]=1;
   if(x>1) par[x].S=min(inf,par[par[x].F].S+b[x]);
   f(i,0,g[x].size()){
   	if(!mark[g[x][i]]) g[x][i]=1;
      if(par[x].S>a[g[x][i]] && par[x].F!=g[x][i]){
         if(!vis[g[x][i]]){
            par[g[x][i]].F=x;
            dfs(g[x][i]);
         }
         else if(u==0){
            u=x,v=g[x][i];
         }
      }
   }
}
void do_it(int u,int v){
   for(;u!=1 && mark[u];u=par[u].F){
      x+=b[u];
      minm(x,inf);
      mark[u]=0;
   }
   for(;v!=1 && mark[v];u=par[v].F){
      x+=b[v];
      minm(x,inf);
      mark[v]=0;
   }
}
bool check(int X){
	x=X;
	int mv=1;
   f(i,1,n+1) mark[i]=1;
   while(mv){
      pre();
      dfs(1);
      if(u==0) return 0;
      do_it(u,v);
      mv=0;
      f(i,2,n+1) mv|=mark[i];
   }
   return 1;
}
void solve(){
   cin>>n>>m;
   f(i,2,n+1) gett(a[i]);
   f(i,2,n+1) gett(b[i]);
   f(i,0,m){
      Gett(E[i].F,E[i].S);
   }
   int l=1,r=inf;
   while(l+1<r){
      int mid=(l+r)/2;
      if(check(mid)) r=mid;
      else l=mid;
   }
   cout<<r<<endl;
}
 
int main(){
   cin>>t;
   while(t--)
      solve();
}