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
 
const int N=2030,mod=998244353;
 
int n,m,ans,mv[N][N],C[2*N][2*N];

int K(int x,int y){
   return C[x][x+y];   
}

int main(){
   f(i,0,2*N){
      C[0][i]=1;
      f(j,1,i+1)
         C[j][i]=(C[j][i-1]+C[j-1][i-1])%mod;
   }
   cin>>n>>m;
   f(i,2,n+1){
      f(j,1,m){
         int res;
         res=1ll*K(j,n-i)*K(m-j-1,n-i+1)%mod;
         if(j>1) mv[i][j]=(1ll*K(i-2,m-j+1)*K(i-1,j-2)%mod+mv[i][j-1])%mod;
         Add(ans,1ll*res*mv[i][j]%mod);
      }
   }
   f(i,0,N) f(j,0,N) mv[i][j]=0;
   f(i,1,n+1)
      f(j,1,m+1)
         mv[i][j]=(mv[i-1][j]+1ll*K(i-1,m-j+1)*K(n-i,m-j))%mod;
   f(i,1,n+1){
      f(j,1,m){
         int res=1ll*K(i-1,j-1)*K(j,n-i)%mod;
         Add(ans,1ll*res*mv[i-1][j+1]);
      }
   }
   cout<<2ll*ans%mod<<endl;
}