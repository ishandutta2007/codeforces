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
 
const int N=5e5;

int n,m,lt,c,deg[N],mark[N];
vector<int> v;
set<pair<int,int> > g[N];
map<pair<int,int>,int> t;

void dfs(int u){
   while(g[u].size()){
      pair<int,int> v=*g[u].begin();
      g[u].erase(v);
      g[v.F].erase(mp(u,v.S));
      dfs(v.F);
   }
   v.pb(u);
}

int main(){
   ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
   cin>>n>>m;
   f(i,0,m){
      int u,v;
      cin>>u>>v;
      g[u].insert(mp(v,c));
      g[v].insert(mp(u,c++));
      deg[u]^=1;
      deg[v]^=1;
   }
   f(i,1,n+1){
      if(deg[i]==1){
         if(lt==0) lt=i;
         else{
            g[lt].insert(mp(i,c));
            g[i].insert(mp(lt,c++));
            m++;
            lt=0;
         }
      }
   }
   
   if(m&1){
      g[1].insert(mp(1,c));
      g[1].insert(mp(1,c++));
   }
   dfs(1);
   cout<<v.size()-1<<endl;
   for(int i=1;i<v.size();i+=2)
      cout<<v[i-1]<<" "<<v[i]<<endl<<v[(i+1)]<<" "<<v[i]<<endl;
}