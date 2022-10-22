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

const int N=1e6+99,M=9000;

int n,t,a[N],dp[N];
vector<int> ans;
vector<int> v[M];

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	fill(dp,dp+N,M-1);
	dp[0]=0;
	f(i,1,M)
		v[i].pb(i);
	cin>>n;
	f(i,0,n){
		int x;
		cin>>x;
		f(j,0,v[x].size()){
			//eror(2);
			while(dp[v[x][j]]>x){
				v[dp[v[x][j]]].pb(v[x][j]^dp[v[x][j]]);
				dp[v[x][j]]--;
				//eror(1);
			}
			//eror(3);
		}
		v[x].clear();
	}		
	f(i,0,M) if(dp[i]<M-1) ans.pb(i);
	cout<<ans.size()<<endl;
	f(i,0,ans.size()) cout<<ans[i]<<" ";
}