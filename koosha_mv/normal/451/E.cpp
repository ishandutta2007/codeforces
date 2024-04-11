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
#define int ll

const int N=22,mod=1e9+7;

int n,t,ans;
ll s,a[N],ifac[N];

ll pow(ll x,ll y,ll mod){return(!y?1:pow(x*x%mod,y/2,mod)*(y&1?x:1))%mod;}

int C(ll x,ll y){
	int ans;
	x--;
	ans=ifac[x];
	f_(i,x+y,y+1){
		ans=1ll*ans*(i%mod)%mod;
	}
	return ans;
	
}
main(){
	ifac[0]=1;
	f(i,1,N){
		ifac[i]=1ll*ifac[i-1]*pow(i,mod-2,mod)%mod;
	}
	cin>>n>>s;
	f(i,0,n) cin>>a[i];
	f(mask,0,(1<<n)){
		ll sum=s;
		f(i,0,n){
			if(mask&(1<<i)){
				sum-=a[i]+1;
			}
		}
		if(sum>=0){
			int res=C(n,sum);
			if(nb(mask)&1){
				Add(ans,mod-res);
			}	
			else{
				Add(ans,res);
			}
		}
	}
	cout<<ans;
}