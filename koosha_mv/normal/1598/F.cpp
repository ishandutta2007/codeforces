#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
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

const int N=21,M=1e6+99;

int n,t,ans,sum[(1<<N)],dp[(1<<N)],cnt[N][M],mark[N][M],mn[M],mv[M];

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	f(i,0,n){
		string s;
		cin>>s;
		int sum=0;
		f(j,0,s.size()){
			if(s[j]=='(') sum++;
			else sum--;
			minm(mn[i],sum);
			if(sum<=0) mark[i][-sum]++;
			if(sum==mn[i]) cnt[i][-sum]++;
		}
		mv[i]=sum;
	}
	f(mask,1,(1<<n)){
		dp[mask]=-M;
		f(i,0,n){
			if(mask&(1<<i)){
				if(dp[mask^(1<<i)]>=0 && sum[mask^(1<<i)]+mn[i]>=0){
					maxm(dp[mask],dp[mask^(1<<i)]+mark[i][sum[mask^(1<<i)]]);
				}
				else{
					maxm(ans,dp[mask^(1<<i)]+cnt[i][sum[mask^(1<<i)]]);
				}
				sum[mask]=sum[mask^(1<<i)]+mv[i];
			}
		}
		maxm(ans,dp[mask]);
	}
	cout<<ans;
}