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

const int N=707,mod=1e9+7;

int n,t,ans,a[N],dp[N][N],Pow[N];
string s;

void solve(int x){
	int cnt0=0,cnt1=0;
	f(i,0,N) f(j,0,N) dp[i][j]=0;
	f(i,0,n){
		f(j,0,i+2){
			int k=i+1-j;
			//cout<<k<<" "<<j<<endl;
			if(k>0){
				
				Add(dp[k][j],x*dp[k-1][j]);
			}
			if(j>0){
				Add(dp[k][j],(10-x)*dp[k][j-1]);
			}
		}
		f(j,0,s[i]-'0'){
			Add(dp[cnt0+(j<x)][cnt1+(j>=x)],1);
		}
		if(s[i]-'0'<x) cnt0++;
		else cnt1++;
	}
	Add(dp[cnt0][cnt1],1);
	f(i,0,n){
		int j=n-i;
		//cout<<x<<" "<<i<<" "<<j<<" : "<<dp[i][j]<<endl;
		Add(ans,Pow[j]*dp[i][j]%mod);
	}
}

main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	Pow[1]=1;
	f(i,2,N) Pow[i]=(10*Pow[i-1]+1)%mod;
	cin>>s;
	n=s.size();
	f(i,1,10){
		solve(i);
	}
	cout<<ans;
}