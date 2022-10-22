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
 
const int N=5e5+9,mod=1e9+7;

int n,c,ck,ans=1,sum,cnt,a[N],b[N],s[N],t[N],deg[N],par[N],fac[N],d[N],ft[N],lt[N],vis[N];
vector<int> g[N];
vector<pair<int,int> > V[N];
map<pair<int,pair<int,int> >,int> mark;

void kill(){
   cout<<0;
   exit(0);
}
void check(int x){
   f(i,0,V[x].size()){
      pair<int,int> p=V[x][i];
      if(a[p.F]!=-1 || b[p.S]!=-1){
         kill();
      }
      a[p.F]=p.S,b[p.S]=p.F;
   }
   int u=0;
   f(q,0,N){
      if(q==N-1) kill();
      if(u==n+1 && g[x].size()+1!=q) kill();
      if(u==-1) break;
      u=a[u];
   }
   f(i,0,g[x].size()){
      if(!vis[g[x][i]]){
         vis[g[x][i]]=1;
         for(int u=a[g[x][i]];u!=-1;u=a[u]){
            vis[u]=1;
            if(u==g[x][i]){
               kill();
            }
         }
      }
   }
   a[0]=b[n+1]=-1;
   f(i,0,g[x].size()){
      vis[g[x][i]]=0;
      a[g[x][i]]=b[g[x][i]]=-1;
   }
}
void addedge(int x,int u,int v){
   //cout<<x<<" "<<u<<" "<<v<<endl;
   if(mark[mp(x,mp(u,v))]++)
      kill();
   V[x].pb(mp(u,v));
}
void dfs1(int x){
   s[x]=c++;
   f(i,0,g[x].size()){
      if(g[x][i]!=par[x]){
         par[g[x][i]]=x;
         dfs1(g[x][i]);
      }
   }
   t[x]=c;
}
int main(){
   fac[0]=1;
   f(i,1,N) fac[i]=1ll*fac[i-1]*i%mod;
   cin>>n;
   f(i,1,n){
      int u,v;
      Gett(u,v);
      deg[u]++,deg[v]++;
      g[u].pb(v);
      g[v].pb(u);
      if(u==48435 && v==486590) ck=1;
   }
   f(i,1,n+1){
      int x;
      gett(x);
      cnt+=(x==0);
      if(x) a[x]=i;
      if(x==i) return cout<<0,0;
   }
   
   dfs1(1);
   f(i,1,n+1){
      if(a[i]){
         int u=i,v=a[i];
         vector<int> v1,v2;
         while(!(s[u]<=s[v] && s[v]<t[u])){
            deg[u]--;
            v1.pb(u);
            u=par[u];
         }
         deg[u]--;
         v1.pb(u);
         while(v!=u){
            deg[v]--;
            v2.pb(v);
            v=par[v];
         }
         reverse(v2.begin(),v2.end());
         f(j,0,v2.size()) v1.pb(v2[j]);
         
         ft[v1[0]]=v1[1];
         lt[v1[v1.size()-1]]=v1[v1.size()-2];
         addedge(v1[0],0,v1[1]);
         addedge(v1.back(),v1[v1.size()-2],n+1);
         f(i,1,v1.size()-1){
            addedge(v1[i],v1[i-1],v1[i+1]);
         }
         sum+=(v1.size()-1);
         if(sum>n*2) kill();
      }
   }
   fill(a,a+N,-1);
   fill(b,b+N,-1);
   f(i,1,n+1)
      check(i);
   if(cnt==0 && sum!=2*(n-1))
      kill();
   f(i,1,n+1){
      ans=1ll*ans*fac[max(1,deg[i])]%mod;
   }
   cout<<ans;
}