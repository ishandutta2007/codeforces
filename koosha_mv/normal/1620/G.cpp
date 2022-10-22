#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
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

const int N=23,Z=26,mod=998244353;
 
int n,t,a[N][Z],dp[(1<<N)],Min[(1<<N)][Z];
ll ans;

int fb(int x){
	f(i,0,N){
		if(x&(1<<i)){
			return i;
		}
	}	
	eror("FI");
}
 
main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n;
	f(i,0,n){
		string s;
		cin>>s;
		f(j,0,s.size()){
			a[i][s[j]-'a']++;
		}
	}
	f(i,0,Z){
		Min[0][i]=(1<<N);
	}
	f(mask,1,(1<<n)){
		int x=fb(mask);
		f(i,0,Z) Min[mask][i]=min(a[x][i],Min[mask^(1<<x)][i]);
		if(nb(mask)&1) dp[mask]=1;
		else dp[mask]=mod-1;
		f(i,0,Z) dp[mask]=(1ll*dp[mask]*(Min[mask][i]+1))%mod;
	}
	f(i,0,n){
		f(mask,0,(1<<n)){
			if((mask&(1<<i))==0){
				Add(dp[mask^(1<<i)],dp[mask]);
			}
		}
	}
	f(mask,1,(1<<n)){
		int sum=0;
		f(i,0,n){
			if(mask&(1<<i)){
				sum+=i+1;
			}
		}
		ans^=1ll*dp[mask]*nb(mask)*sum;
	}
	cout<<ans;
}