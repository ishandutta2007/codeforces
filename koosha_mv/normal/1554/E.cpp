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

const int N=1e5+99,mod=998244353;

bool ok;
int n,t,sum,res,ans[N];
vector<int> g[N];

int dfs(int x,int par,int k){
   int t=0;
   f(i,0,g[x].size())
      if(g[x][i]!=par)
         t+=dfs(g[x][i],x,k);
   t=t%k;
   if((t!=0 && t!=k-1) || (t==k-1 && x==1)) ok=0;
   if(t==0)
      return 1;
   return 0;
}

void solve(){
   sum=0,res=1;
   cin>>n;
   ans[n]=0;
   f(i,1,n+1)
      g[i].clear();
   f(i,1,n){
      int u,v;
      Gett(u,v);
      g[u].pb(v);
      g[v].pb(u);
   }
   for(int i=n;i>1;i--){
      ans[i]=0;
      if((n-1)%i==0){
         ok=1;
         dfs(1,0,i);
         ans[i]=ok;
         for(int j=i*2;j<n;j+=i)
            ans[i]-=ans[j];
         sum+=ans[i];
      }
   }
   f(i,1,n)
      res=2ll*res%mod;
   cout<<(res-sum+mod)%mod<<" ";
   f(i,2,n+1)
      cout<<ans[i]<<" ";
   cout<<endl;
}

int main(){
   cin>>t;
   while(t--)
      solve();
}