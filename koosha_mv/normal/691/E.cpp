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
 
const int N=105,mod=1e9+7,Lg=62;

ll n,k,ans,a[N];
int g[N][N],dp[N][N][Lg],last[N],lt[N];

bool check(ll x){
   int res=0;
   f(i,0,62){
      res+=(((1ll<<i)&x)>0);
   } 
   return (res%3==0);
}

int main(){
   cin>>n>>k;
   k--;
   f(i,1,n+1){
      cin>>a[i];
   }
   f(i,1,n+1)
      f(j,1,n+1)
         if(check(a[i]^a[j])){
            g[i][j]=1;
            dp[i][j][0]=1;
         }
         
   f(lg,1,Lg){
      f(i,1,n+1)
         f(j,1,n+1)
            f(k,1,n+1)
               Add(dp[i][k][lg],1ll*dp[i][j][lg-1]*dp[j][k][lg-1]%mod);
   }
   f(i,1,n+1) last[i]=1;
   f(lg,0,Lg){
      if(k&(1ll<<lg)){
         f(i,1,n+1) lt[i]=0;
         f(i,1,n+1)
            f(j,1,n+1)
               Add(lt[j],1ll*last[i]*dp[i][j][lg]%mod);
         f(i,1,n+1)
            last[i]=lt[i];
      }
   }
   f(i,1,n+1)
      Add(ans,last[i]);
   cout<<ans;
}