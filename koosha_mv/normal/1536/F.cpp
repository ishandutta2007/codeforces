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

const int N=2e6+99,mod=1e9+7;

int fac[N],ifac[N];
ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}
void make_fac(){fac[0]=1; f(i,1,N) fac[i]=1ll*fac[i-1]*i%mod; ifac[N-1]=pow(fac[N-1],mod-2,mod);f_(i,N-2,0) ifac[i]=1ll*ifac[i+1]*(i+1ll)%mod;}
int C(int k,int n){if(k>n) return 0; return 1ll*fac[n]*ifac[n-k]%mod*ifac[k]%mod;}

int n,ans;
int T(int x,int y){
   y-=x*2-1;
   if(y<0) return 0;
   return C(x,x+y);
}
int G(int x,int y){
   if(x==1) return y;
   return (T(x,y)-T(x-2,y-4)+mod)%mod;
}

int main(){
   make_fac();
   if(n==1)
      return cout<<2,0;
   if(n==2)
      return cout<<4,0;
   if(n==3)
      return cout<<12,0;
   cin>>n;
   f(i,1,n/2+1)
      if((n&1)==(i&1)){
         int res=2ll*G(i,n)*fac[n-i]%mod;
         Add(ans,res);
      }
   if(n%2==0) Add(ans,2ll*fac[n]%mod);
   cout<<ans;
}