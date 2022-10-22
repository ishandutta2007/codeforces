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

const int N=1e5+99,mod=998244353;

int n,m,ans,a[N],G[N],dp[2][(1<<10)];

int32_t main(){
	f(i,0,10) f(j,0,10) G[i]|=(1<<j);
	cin>>n>>m;
	f(i,0,m){
		int u,v;
		cin>>u>>v;
		G[u]^=(1<<v);
		G[v]^=(1<<u);
	}
	f(id,0,n){
		int s=id&1;
		dp[s][(1<<10)-2]++;
		f(mask,0,(1<<10)) dp[s^1][mask]=0;
		f(mask,1,(1<<10)){
			int task=mask;
			f_(i,9,0){
				if(bit(task,i+1)) task^=(1<<(i+1));
				if(bit(mask,i)==0) continue ;
				Add(dp[s^1][task|G[i]],dp[s][mask]);
			}
		}
	}
	dp[n&1][0]++;
	f(mask,0,(1<<10)) Add(ans,dp[n&1][mask]);
	cout<<ans;
}