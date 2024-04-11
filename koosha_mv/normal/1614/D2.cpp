#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define Add(x,y) x=(x+y)%mod;
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=2e7+9;
 
int n,t,sz,a[N],p[N],cnt[N],prime[N];
ll ans,dp[N];
 
int main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	f(i,2,N){
	   prime[i]^=1;
	   if(prime[i]){
	      p[sz++]=i;
	      for(int j=i*2;j<N;j+=i){
	         prime[j]=1;
	      }
	   }
	}
	cin>>n;
	f(i,0,n){
		int x;
		cin>>x;
		for(int j=1;j*j<=x;j++){
			if(x%j==0){
				a[j]++;
				if(j*j!=x){
					a[x/j]++;
				}
			}
		}
	}
	f_(i,N-1,1){
		if(a[i]){
			dp[i]=1ll*i*a[i];
			for(int j=0;i*p[j]<N && j<sz;j++){
			   int u=i*p[j];
				maxm(dp[i],dp[u]+1ll*i*(a[i]-a[u]));
			}
		}
	}
	cout<<dp[1];
}