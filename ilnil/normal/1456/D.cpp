#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define ff(i,a,b)for(int i=a,_e=b;i<_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define cls(x) memset(x,0,sizeof x)
#define cpy(x,y) memcpy(x,y,sizeof y)
#define pb push_back
#define P pair<int,int>
#define fi first
#define se second
#define ll long long
#define ul unsigned ll
#define ui unsigned int
#define db double
#define ldb long double
#define bit(x,y)((x)>>(y)&1)
using namespace std;
const int N=5005;
int n;
ll dp[N],x[N],t[N],d[N];
bool can[N];
ll fabs(ll x){return x>0?x:-x;}
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	scanf("%d",&n);
	fo(i,1,n)scanf("%I64d%I64d",&t[i],&x[i]),dp[i]=1e9+1,d[i-1]=fabs(x[i]-x[i-1]);
	fo(i,0,n){
		if(dp[i]<=1e9){
			fo(j,i+1,n){
				if(dp[i]+fabs(x[j]-x[i])*2<=t[i])can[j-1]=1;
				if(t[j-1]+d[j-1]>t[j])break;
			}
			if(dp[i]+d[i]<=t[i+1])
				dp[i+1]=min(dp[i+1],max(t[i],dp[i]+d[i]));
			fo(j,i+2,n){
				if(max(dp[i]+fabs(x[j]-x[i]),t[i])+fabs(x[j]-x[i+1])<=t[i+1])can[j-1]=1;
				if(t[j-1]+d[j-1]>t[j])break;
			}
		}
		if(can[i]){
			if(t[i]+fabs(x[i+2]-x[i])<=t[i+2])
				dp[i+2]=min(dp[i+2],max(t[i+1],t[i]+fabs(x[i+2]-x[i])));
			fo(j,i+3,n){
				if(max(t[i]+fabs(x[j]-x[i]),t[i+1])+fabs(x[j]-x[i+2])<=t[i+2])can[j-1]=1;
				if(t[j-1]+d[j-1]>t[j])break;
			}
		}
	}
	printf(can[n-1]||dp[n]<=1e9?"YES":"NO");
}