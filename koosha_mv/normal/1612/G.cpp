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

const int N=1e6+99,mod=1e9+7;

int n,t,now,ans,res=1,a[N],cnt[N],fac[N];

int G(int x,int y){
	return (1ll*y*(y+1)/2)%mod*x%mod;
}
int main(){
	fac[0]=1;
	f(i,1,N) fac[i]=1ll*fac[i-1]*i%mod;
	cin>>n;
	f(i,0,n){
		int x;
		cin>>x;
		cnt[x]++;
	}
	f_(i,N-1,2){
		res=1ll*res*fac[cnt[i]]%mod;
		Add(ans,1ll*now*cnt[i]%mod);
		Add(ans,G(i-1,cnt[i]));
		Add(now,1ll*cnt[i]*(i-1)%mod);
		cnt[i-2]+=cnt[i];
		//cout<<i<<" "<<ans<<endl;
	}
	//eror(ans);
	ans=2ll*ans%mod;
	f_(i,1,1){
		Add(ans,1ll*now*cnt[i]%mod);
		Add(ans,G(i-1,cnt[i]));
		Add(now,1ll*cnt[i]*(i-1)%mod);
	}
	res=1ll*res*res%mod*fac[cnt[1]]%mod;
	Add(ans,mod-now);
	cout<<ans<<" "<<res;
}