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

int t,n,m,l[N],r[N],ans[N],dp[N],pd[N];

void calc(int x){
   int k=m/x;
   dp[0]=1;
   f(i,1,k+1) dp[i]=1;
   f(i,0,n){
      int L=(l[i]+x-1)/x,R=r[i]/x;
      if(L>R){ ans[x]=0; return; }
      f(j,1,k+1){
      	 pd[j]=0;
    	 if(j-L>=0) pd[j]=dp[j-L];
         if(j-R-1>=0)
            Add(pd[j],mod-dp[j-R-1]);
      }
      dp[0]=0;
      f(i,1,k+1) dp[i]=(dp[i-1]+pd[i])%mod;
   }
   ans[x]=dp[k];
}

int main(){
   cin>>n>>m;
   f(i,0,n) cin>>l[i]>>r[i];
   f_(i,N-1,1){
      calc(i);
      for(int j=i*2;j<N;j+=i) Add(ans[i],mod-ans[j]);
   }
   cout<<ans[1]<<endl;
}