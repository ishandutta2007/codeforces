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
 
const int N=1e6+9,mod=998244353,d=mod/2+1;

int n,e,ans,dp[N],pd[N];

ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}
int calc(int n){
   int ans=0;
   Add(ans,1ll*dp[n-1]*(dp[n-1]+1)%mod*(dp[n-1]+2)%mod*e%mod);
   Add(ans,1ll*dp[n-1]*(dp[n-1]+1)%mod*d%mod);
   Add(ans,1ll*dp[n-1]);
   return ans;
}

int main(){
   e=pow(6,mod-2,mod);
   cin>>n;
   if(n==1) return cout<<5,0;
   dp[0]=1;
   f(i,1,n){
      dp[i]=(1+dp[i-1]+(1ll*dp[i-1]*(dp[i-1]+1)%mod*d%mod))%mod;
   }
   Add(ans,(2ll*(calc(n)-calc(n-1))-1)%mod);
   f_(i,n-1,1)
      dp[i]=1ll*dp[i-1]*(dp[i-1]+1)%mod*d%mod;
   dp[0]=0;
   f_(i,n-1,1)
      dp[i]=(dp[i]-dp[i-1]+mod)%mod;
   f(i,1,n){
      pd[i]=(pd[i-1]+dp[i])%mod;
      Add(ans,1ll*pd[i]*dp[n-i-1]%mod);
   }
   cout<<ans;
}