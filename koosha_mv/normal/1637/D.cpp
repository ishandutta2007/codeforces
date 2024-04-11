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

const int N=105;

int n,t,a[N],b[N],dp[N][N*N];

void Main(){
	f(i,0,N) f(j,0,N*N) dp[i][j]=0;
	ll ans=0,sum=0;
	cin>>n;
	dp[0][0]=1;
	f(i,1,n+1){
		cin>>a[i];
		sum+=a[i];
		ans+=a[i]*a[i]*(n-2);
	}
	f(i,1,n+1){
		cin>>b[i];
		sum+=b[i];
		ans+=b[i]*b[i]*(n-2);
	}
	if(n==1){
		cout<<0<<'\n';
		return ;
	}
	f(i,1,n+1){
		f(j,1,i*N){
			dp[i][j]=0;
			if(j-a[i]>=0) dp[i][j]|=dp[i-1][j-a[i]];
			if(j-b[i]>=0) dp[i][j]|=dp[i-1][j-b[i]];
		}
	}
	f_(i,sum/2,1){
		if(dp[n][i]){
			ans+=i*i;
			ans+=(sum-i)*(sum-i);
			cout<<ans<<'\n';
			return ;
		}
	}
}

main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	cin>>t;
	while(t--){
		Main();
	}
}