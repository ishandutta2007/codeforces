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

const int N=1e6+99;

int n,m,ans,a[N];
string t[N];

void solve(int s){
	vector<vector<int> > dp(n);
	f(i,0,n) f(j,0,m) dp[i].pb(0);
	f(i,0,n) dp[i][m-1]=((i^m^1)&1)==s && t[i][m-1]=='1';
	f_(j,m-2,0){
		f(i,0,n){
			dp[i][j]=dp[i][j+1];
			if(i>0) maxm(dp[i][j],dp[i-1][j+1]);
			if(i<n-1) maxm(dp[i][j],dp[i+1][j+1]);
			if(((i^j)&1)==s && t[i][j]=='1'){
				maxm(dp[i][j],dp[i][j+1]+1);
			}
		}
	}
	int res=0;
	f(i,0,n){
		maxm(res,dp[i][0]);
	}
	ans+=res;
}

int main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T=0;
	cin>>T;
	while(T--){
		ans=0;
		cin>>n>>m;
		f(i,0,n){
			cin>>t[i];
		}
		solve(0);
		solve(1);
		cout<<ans<<'\n';
	}
}