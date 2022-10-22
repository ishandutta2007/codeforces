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

const int N=2e6+99,M=20,mod=1e9+7;

int n,t,ans,dp[N],Pow[N];

int main(){
	Pow[0]=1;
	f(i,1,N){
		Pow[i]=2ll*Pow[i-1]%mod;
	}
	cin>>n;
	f(i,0,n){
		int x;
		cin>>x;
		dp[x]++;
	}
	f(i,0,M){
		f(mask,0,(1<<M)){
			if((mask^(1<<i))<mask){
				dp[mask^(1<<i)]+=dp[mask];
			}
		}
	}
	f(mask,0,(1<<M)){
		int res=Pow[dp[mask]]-1;
		if(nb(mask)&1){
			Add(ans,mod-res);
		}	
		else{
			Add(ans,res);
		}
	}
	cout<<ans;
}