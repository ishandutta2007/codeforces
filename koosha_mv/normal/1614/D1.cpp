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

const int N=5e6+99;

int n,t,a[N],cnt[N];
ll ans,dp[N];

int main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n;
	f(i,0,n){
		int x;
		cin>>x;
		cnt[x]++;
	}
	f(i,1,N){
		for(int j=i;j<N;j+=i){
			a[i]+=cnt[j];
		}
	}	
	f_(i,N-1,1){
		dp[i]=1ll*i*a[i];
		for(int j=i*2;j<N;j+=i){
			if(i==2 && j==6){
				//cout<<dp[j]<<" "<<i<<" "<<cnt[i]<<" "<<cnt[j]<<endl;
			}
			maxm(dp[i],dp[j]+1ll*i*(a[i]-a[j]));
		}
		//cout<<i<<" "<<a[i]<<" : "<<dp[i]<<endl;
		maxm(ans,dp[i]);
	}
	cout<<ans;
}