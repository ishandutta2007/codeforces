#include <bits/stdc++.h>
#include<algorithm>
#include <iostream>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);																																														
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
using namespace std;
const int mod=1e9+7,N=1e6+5;
//math
ll x,y,g,n,fac[N],m,ans=1,t,p,ans2,dp1[100],dp2[100],k;
ll xgcd(ll a, ll b, ll &x, ll &y){if(b==0){x=1;y=0;return a;}ll x1,y1,gcd=xgcd(b,a%b,x1,y1);x=y1;y=x1- (long long)(a/b)*y1;return gcd;}
ll entekhab(ll r,ll n){if(r>n) return 0;if(r==0)return 1;ll ans=1;ans=fac[n];x=1,y=1,g=xgcd(fac[r],mod,x,y);ans=(ans*((x+mod)%mod))%mod;x=1,y=1,g=xgcd(fac[n-r],mod,x,y);ans=((ans*((x+mod)%mod)))%mod;return ans;}
ll tavan(ll x,ll y){ll p;if(y==0) return 1;if(y%2==0){p=tavan(x,y/2);return (p*p)%mod;}return (tavan(x,y-1)*x)%mod;}

int main(){
	fac[0]=1;
	f(i,1,N) fac[i]=(fac[i-1]*i)%mod;
	cin>>n;
	while((1<<(m+1))<=n)
		m++;
	t=n;
	f_(i,m,0){
		p=((n/(1<<i))+1)/2;
		ans=ans*entekhab(p-1,t-1)%mod*fac[p]%mod;
		t-=p;
	}
	t=n;
	if((1<<(m-1))*3<=n){																																													
		(ans*=2)%=mod;
		f(i,1,m){
			ans2=1,k=2;
			t=n-1;
			f_(j,m-1,i){
				p=(((n/(1<<j-1))+1)/2+1)/3;
				k+=((n/(1<<j-1))+1)/2-(((n/(1<<j-1))+1)/2+1)/3;
				ans2=(((ans2*entekhab(p-1,t-1))%mod)*fac[p])%mod;
				t-=p;
			}
			p=k;
			ans2=(ans2*entekhab(p-1,t-1)%mod*fac[p])%mod;
			t-=p;
			f_(j,i-2,0){
				p=((n/(1<<j))+1)/2;
				ans2=ans2*entekhab(p-1,t-1)%mod*fac[p]%mod;
				t-=p;
			}
			ans=(ans+ans2)%mod;
		}	
	}
	cout<<ans<<endl;
}