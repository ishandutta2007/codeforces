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
#define int ll

const int N=1e6+99,mod=998244353;

int n,t,a[N],dp[N],pd[N],mark[N];


void Main(){
	int ans=0;
	dp[0]=1;
	//pd[1]=1;
	cin>>n;
	f(i,1,n+1){
		cin>>a[i];
		a[i]++;
	}
	f(i,1,n+1){
		int x;
		pd[a[i]-1]=2ll*pd[a[i]-1]%mod;
		pd[a[i]+1]=2ll*pd[a[i]+1]%mod;
		//eror(pd[1]);
		if(a[i]>1) Add(pd[a[i]-1],dp[a[i]-2]);
		//eror(pd[1]);
		x=(dp[a[i]-1]+dp[a[i]]);
		Add(dp[a[i]],x);
		//Add(pd[a[i]+1],x);
		//Add(pd[a[i]+2],x);
	}
	f(i,1,n+3){
		//cout<<dp[i]<<" "<<pd[i]<<endl;
		Add(ans,dp[i]);
		Add(ans,pd[i]);
	}
	cout<<(ans+mod)%mod<<endl;
	f(i,0,n+10) mark[i]=dp[i]=pd[i]=0;
}

main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin>>t;
	while(t--){
		Main();
	}
}