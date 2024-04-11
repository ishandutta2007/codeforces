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

const int N=1e5+99;

int n,m,c,deg[N],mark[N];
vector<int> V,g[N],G[N];


bool ask(int u,int v){
   bool ans;
   cout<<"? "<<u<<" "<<v<<endl;
   cin>>ans;
   //cout<<ans<<endl;
   return ans;
}
void del(int u){
   f(i,0,G[u].size()){
      if(--deg[G[u][i]]==0){
         V.pb(G[u][i]);
      }
   }
}
void dfs(int x){
   mark[x]=1;
   f(i,0,g[x].size()){
      if(!mark[g[x][i]] || mark[g[x][i]]==2){
         deg[g[x][i]]++;
         G[x].pb(g[x][i]);
      }
      if(!mark[g[x][i]]){
         dfs(g[x][i]);
      }
   }
   mark[x]=2;
}


int main(){
   cin>>n>>m;
   f(i,0,m){
      int u,v;
      Gett(u,v);
      g[u].pb(v);
   }
   f(i,1,n+1)
      if(!mark[i])
         dfs(i);
   f(i,1,n+1){
      if(deg[i]==0){
         //eror(i);
         V.pb(i);
      }
   }
   while(V.size()>1){
      int v,u=V.back();
      V.pop_back();
      v=V.back();
      V.pop_back();
      if(ask(u,v)){
         V.pb(u);
         //cout<<v<<endl;
         del(v);
      }
      else{
         V.pb(v);
         //cout<<u<<endl;
         del(u);
      }
   }
   cout<<"! "<<V[0]<<endl;
}