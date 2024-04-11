#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<x.F<<" , "<<x.S<<"}"<<endl
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

const int N=505,inf=1e15;

int n,t,a[N],b[N],k[N],dp[N][N];

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n;
	f(i,1,n+1) cin>>a[i]>>b[i]>>k[i];
	vector<int> vec(n);
	iota(all(vec),1);
	sort(all(vec),[&](int u,int v){ return b[u]>b[v] ;});
	f(i,0,N) f(j,0,N) dp[i][j]=-inf;
	int ans=0;
	dp[0][0]=0;
	f(i,0,n){
		int A=a[vec[i]],B=b[vec[i]],K=k[vec[i]];
		f(j,0,i+1){
			maxm(ans,dp[i][j]);
			maxm(dp[i+1][j],dp[i][j]);
			maxm(dp[i+1][j],dp[i][j]+A-B*K);
			maxm(dp[i+1][j+1],dp[i][j]+A-B*min(j,K));
		}
	}
	f(i,0,n+1) maxm(ans,dp[n][i]);
	cout<<ans;
}