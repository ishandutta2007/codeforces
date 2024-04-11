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

const int N=1e6+99,inf=1e16;

int n,t,a[N],dp[N],pd[N];
string s;

void Main(){
	cin>>n>>s;
	s=' '+s;
	f(i,1,n+1) cin>>a[i];
	f(i,0,n+10){
		dp[i]=0;
		pd[i]=-inf;
	}
	f_(i,n,1){
		dp[i]=dp[i+1]+a[i]*(s[i]-'0');
		maxm(dp[i],pd[i+1]+a[i]);
		if(s[i]=='1'){
			pd[i]=dp[i+1];
			maxm(pd[i],pd[i+1]+a[i]);
		}
		//cout<<dp[i]<<" "<<pd[i]<<endl;
	}
	cout<<dp[1]<<'\n';
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
	}
}