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
 
const int N=1e6+99,Lg=18;

int n,c,q,s[N],t[N],h[N],dp[N],par[Lg][N];
vector<int> g[N];

void dfs(int x){
   s[x]=++c;
   dp[x]=1;
   f(i,1,Lg)
      par[i][x]=par[i-1][par[i-1][x]];
   f(i,0,g[x].size()){
      if(g[x][i]!=par[0][x]){
         h[g[x][i]]=h[x]+1;
         par[0][g[x][i]]=x;
         dfs(g[x][i]);
         dp[x]+=dp[g[x][i]];
      }
   }
   t[x]=++c;
}
int main(){
   cin>>n;
   f(i,1,n){
      int u,v;
      Gett(u,v);
      g[u].pb(v);
      g[v].pb(u);
   }
   par[0][1]=1;
   dfs(1);
   cin>>q;
   f(qq,0,q){
      int u,v,lca,ck;
      Gett(u,v);
      ck=(h[u]==h[v]);
      if(h[u]<h[v]) swap(u,v);
      if((h[u]&1)!=(h[v]&1)){ cout<<0<<endl; continue;}
      if(u==v){ cout<<n<<endl; continue;}
      lca=u;
      f_(i,Lg-1,0){
         if(!(s[par[i][lca]]<=s[v] && s[v]<=t[par[i][lca]])){
            //cout<<i<<" "<<lca<<" "<<par[i][lca]<<endl;
            lca=par[i][lca];
         }
      }
      lca=par[0][lca];
      int mv=(h[u]+h[v]-h[lca]*2)/2,cmv;
      cmv=mv;
      f_(i,Lg-1,0){
         if((1<<i)<mv){
            mv-=(1<<i);
            u=par[i][u];
         }
      }
      if(ck){
         mv=cmv;
         f_(i,Lg-1,0){
            if((1<<i)<mv){
               mv-=(1<<i);
               v=par[i][v];
            }
         }
         cout<<n-dp[u]-dp[v]<<endl;
      }
      else{
         cout<<dp[par[0][u]]-dp[u]<<endl;
      }
   }
}