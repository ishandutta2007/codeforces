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

const int N=1005,inf=1e8;

int n,m,t,a[N][N],dp[N][N],pd[N][N];

void Main(){
	cin>>n>>m;
	f(i,0,n){
		f(j,0,m){
			cin>>a[i][j];
			dp[i][j]=-inf;
			pd[i][j]=inf;
		}
	}
	dp[0][0]=a[0][0];
	pd[0][0]=a[0][0];
	f(i,0,n){
		f(j,0,m){
			maxm(dp[i+1][j],dp[i][j]+a[i+1][j]);
			maxm(dp[i][j+1],dp[i][j]+a[i][j+1]);
			minm(pd[i+1][j],pd[i][j]+a[i+1][j]);
			minm(pd[i][j+1],pd[i][j]+a[i][j+1]);
		}
	}
	if(pd[n-1][m-1]<=0 && 0<=dp[n-1][m-1] && (n+m-1)%2==0){
		cout<<"YES"<<'\n';
	}
	else{
		cout<<"NO"<<'\n';
	}
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
	}
}