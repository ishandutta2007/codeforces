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


 
const int N=505;

int mod,fac[N],ifac[N];
ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}
void make_fac(){fac[0]=1; f(i,1,N) fac[i]=1ll*fac[i-1]*i%mod; ifac[N-1]=pow(fac[N-1],mod-2,mod);f_(i,N-2,0) ifac[i]=1ll*ifac[i+1]*(i+1ll)%mod;}
int C(int k,int n){if(k>n) return 0; return 1ll*fac[n]*ifac[n-k]%mod*ifac[k]%mod;}

int n,m;
pair<int,int> G[N],dp[N][N];

pair<int,int> merge(int n,int m,pair<int,int> u,pair<int,int> v){
   pair<int,int> ans=mp(1ll*u.F*v.F%mod,(1ll*u.F*v.S%mod+1ll*u.S*v.F%mod)%mod);
   ans.F=1ll*ans.F*C(n,n+m)%mod;
   ans.S=1ll*ans.S*C(n,n+m)%mod;
   return ans;
}
void do_it(){
   G[0]=mp(1,0);
   f(k,1,n+1){
      f(j,0,k){
         int i=k-j-1;
         pair<int,int> u;
         u=merge(i,j,G[i],G[j]);
         u.S=(1ll*u.S*(i+j+2)+1ll*u.F*(i*(i+1)/2+j*(j+1)/2))%mod;
         u.F=1ll*u.F*(i+j+2)%mod;
         Add(G[i+j+1].F,u.F);
         Add(G[i+j+1].S,u.S);
      }
   }
}
void solve(){
   dp[0][0]=mp(1,0);
   f(i,0,n+1){
      pair<int,int> u;
      if(i){
         f(j,0,i+1){
            Add(dp[i][j].F,dp[i-1][j].F);
            Add(dp[i][j].S,dp[i-1][j].S);
         }
      }
      f(j,0,i+1){
         if(i==0) u=mp(1,0);
         else u=dp[i-1][j];
         f(k,1,n-i+1){
            Add(dp[i+k][j+k].F,merge(j,k,u,G[k]).F);
            Add(dp[i+k][j+k].S,merge(j,k,u,G[k]).S);
         }
      }
   }
   cout<<dp[n][m].S;
}

int main(){
   cin>>n>>m>>mod;
   make_fac();
   do_it();
   solve();
}