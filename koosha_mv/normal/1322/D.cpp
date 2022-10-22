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

const int N=5555,inf=1e9;

int n,m,ans,a[N],c[N],dp[N][N],w[N*2];

int main(){
   cin>>n>>m; m=5005;
   f(i,1,n+1) cin>>a[i];
   f(i,1,n+1) cin>>c[i];
   f(i,1,n+m+1) cin>>w[i];
	
	f(i,0,N){
		f(j,0,N){
			dp[i][j]=(j==0 ? 0 : -inf);
		}
	}
	f_(i,n,1){
		int x=a[i],cost=c[i];
		f_(mask,m,0){
			int res=dp[x][mask]-cost;
			f(j,0,N){
				res+=w[x+j];
				if((mask&(1<<j))==0) break;
			}
			maxm(dp[x][mask+1],res);
		}
		int R=N-1;
		f(j,x,m+1){
			f(k,0,R+1){
				maxm(dp[j+1][k/2],dp[j][k]);
			}
			R/=2;
		}
	}
	
	f(i,0,N){
		f(j,0,N){
			maxm(ans,dp[i][j]);
		}
	}
	cout<<ans;
}