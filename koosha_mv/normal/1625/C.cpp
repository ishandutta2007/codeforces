#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=505,inf=1e10+99;

int n,l,k,ans=inf,a[N],d[N],dp[N][N];

main(){
	cin>>n>>l>>k;
	f(i,1,n+1) cin>>d[i];
	f(i,1,n+1) cin>>a[i];
	if(k==n-1){
		minm(ans,l*a[1]);
	}
	f(i,0,N) f(j,0,N) dp[i][j]=inf;
	dp[1][1]=0;
	f(i,2,n+1){
		f(j,1,n+1){
			f(k,1,i){
				minm(dp[i][j],dp[k][j-1]+(d[i]-d[k])*a[k]);
			}
			if(j>=n-k){
				minm(ans,dp[i][j]+(l-d[i])*a[i]);
			}
		}
	}
	cout<<ans;
}