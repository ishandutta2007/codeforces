#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e5+99,sq=500;
const ll inf =1e16;

int n,t;
ll a[N],dp[N][sq];

int Main(){
	cin>>n;
	f(i,1,n+1){
		cin>>a[i];
	}
	reverse(a+1,a+1+n);
	dp[0][0]=inf;
	f(i,1,sq)
		dp[0][i]=0;
	f(i,1,n+1){
		a[i]+=a[i-1];
		f(j,0,sq){
			dp[i][j]=dp[i-1][j];
		}
		f(j,1,min(sq,i+1)){
			if(dp[i-j][j-1]>a[i]-a[i-j]){
				maxm(dp[i][j],a[i]-a[i-j]);
			}
			//cout<<i<<" "<<j<<" : "<<dp[i][j]<<endl;
		}
	}
	int ans=0;
	f(i,1,sq){
		if(dp[n][i]){
			ans=i;
		}
	}
	cout<<ans<<endl;
	return 0;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		Main();
	}
}