#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
const int N=2009,mod=1e9+7;
ll p,k,x,mark[N],n,fac[N],y,g,ans,h;
ll xgcd(ll a, ll b, ll &x, ll &y){if(b==0){x=1;y=0;return a;}ll x1,y1,gcd=xgcd(b,a%b,x1,y1);x=y1;y=x1- (long long)(a/b)*y1;return gcd;}
ll entekhab(ll r,ll n){if(r==0)return 1;ll ans=1;ans=fac[n];x=1,y=1,g=xgcd(fac[r],mod,x,y);ans=(ans*((x+mod)%mod))%mod;x=1,y=1,g=xgcd(fac[n-r],mod,x,y);ans=((ans*((x+mod)%mod)))%mod;return ans;}
int main(){
	fac[0]=1;
	f(i,1,N) fac[i]=(fac[i-1]*i)%mod;
	cin>>p;
	f(i,1,p+1){
		cin>>x;
		if(x==-1){
			n++;
			mark[i]++;
		}
		else mark[x]++;
		k+=(mark[x]==2)+(mark[i]==2);
	}
	k=n-k;
	ans=fac[n];
	f(i,1,k+1){
		if(i%2==0)
			ans=(ans+((entekhab(i,k)*fac[n-i])%mod))%mod;
		else
			ans=(ans+mod-((entekhab(i,k)*fac[n-i])%mod))%mod;
	}
	cout<<ans;
}