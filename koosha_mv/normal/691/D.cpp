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
 
const int N=1e6+99,mod=1e9+7;

int n,m,a[N],mark[N];
vector<int> v,c,g[N];

void dfs(int x){
   mark[x]=1;
   v.pb(x);
   c.pb(a[x]);
   f(i,0,g[x].size())
      if(!mark[g[x][i]])
         dfs(g[x][i]);
}

int main(){
   cin>>n>>m;
   f(i,1,n+1) gett(a[i]);
   f(i,0,m){
      int u,v;
      Gett(u,v);
      g[u].pb(v);
      g[v].pb(u);
   }
   f(i,1,n+1){
      if(!mark[i]){
         v.clear();
         c.clear();
         dfs(i);
         sort(v.begin(),v.end());
         sort(c.begin(),c.end());
         reverse(c.begin(),c.end());
         f(j,0,v.size())
            a[v[j]]=c[j];
      }
   }
   f(i,1,n+1) cout<<a[i]<<" ";
}