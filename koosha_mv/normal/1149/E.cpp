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

const int N=2e5+99;

int n,m,h[N],G[N],vis[N],mark[N],X[N];
vector<int> g[N];

void dfs(int x){
   vis[x]=1;
   f(i,0,g[x].size()){
      if(!vis[g[x][i]])
         dfs(g[x][i]);
   }
   f(i,0,g[x].size())
      mark[G[g[x][i]]]=1;
   f(i,0,N){
      if(!mark[i]){
         G[x]=i;
         break;
      }
   }
   f(i,0,g[x].size())
      mark[G[g[x][i]]]=0;
   X[G[x]]^=h[x];
}

int main(){
   cin>>n>>m;
   f(i,1,n+1){
      gett(h[i]);
   }
   f(i,0,m){
      int u,v;
      Gett(u,v);
      g[u].pb(v);
   }
   f(i,1,n+1)
      if(!vis[i])
         dfs(i);
   f_(i,1000,0){
      if(X[i]!=0){
         cout<<"WIN"<<endl;
         f(u,1,n+1){
            if(G[u]==i && (h[u]^X[i])<h[u]){
               h[u]^=X[i];
               f(j,0,g[u].size()){
                  h[g[u][j]]^=X[G[g[u][j]]];
                  X[G[g[u][j]]]=0;
               }
               f(i,1,n+1) cout<<h[i]<<" ";
               return 0;    
            }
         }
      }
   }
   cout<<"LOSE"<<endl;
}