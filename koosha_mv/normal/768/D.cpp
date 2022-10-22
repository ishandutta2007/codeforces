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
 
const int N=1005;

long double e=0.0000001,dp[N];
int n,q,p,ans[N];

int main(){
   dp[0]=1;
   cin>>n>>q;
   f(t,1,N*N){
      f_(i,n,1) dp[i]=dp[i-1]*(n-i+1)/n+dp[i]*i/n;
      dp[0]=0;
      long double d=2000;
		while(p<N && dp[n]>(((long double)(p)-e)/d)){
			ans[p++]=t;
		}
		if(p>1002) break;
   }
   while(q--){
      int u;
      cin>>u;
      cout<<ans[u]<<endl;
   }
}