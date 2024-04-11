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

const int N=3030,mod=1e9+7;

int n,m,a[N][N],dp0[N][N],dp1[N][N];

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>m;
	f(i,1,n+1){
		f(j,1,m+1){
			char c;
			cin>>c;
			if(c=='.') a[i][j]=1;
		}
	}
	if(a[1][2]) dp0[1][2]=1;
	if(a[2][1]) dp1[2][1]=1;
	f(i,1,n+1) f(j,1,m+1){
		if(a[i][j]==0) continue ;
		Add(dp0[i][j],(dp0[i-1][j]+dp0[i][j-1])%mod);
		Add(dp1[i][j],(dp1[i-1][j]+dp1[i][j-1])%mod);
		//cout<<i<<" "<<j<<" -> "<<dp0[i][j]<<" "<<dp1[i][j]<<endl;
	}
	cout<<(1ll*dp0[n-1][m]*dp1[n][m-1]-1ll*dp0[n][m-1]*dp1[n-1][m]%mod+mod)%mod;
}