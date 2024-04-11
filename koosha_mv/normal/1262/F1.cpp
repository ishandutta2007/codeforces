#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
ll kn[200009],sum=0,kabe[200009],g,x,y,ff,mod= 998244353,fac[200009],sa=0,a1[200009];
ll xgcd(ll a, ll b, ll &x, ll &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	ll x1,y1,gcd=xgcd(b,a%b,x1,y1);
	x=y1;
	y=x1- (long long)(a/b)*y1;
	return gcd;
}
ll entekhab(ll r,ll n){
	if(r==0)
		return 1;
	ll ans=1;
	ans=fac[n];
	//cout<<ans<<" ";
	x=1,y=1,g=xgcd(fac[r],mod,x,y);
	ans=(ans*((x+mod)%mod))%mod;//cout<<ans<<" ";
	x=1,y=1,g=xgcd(fac[n-r],mod,x,y);
	ans=((ans*((x+mod)%mod)))%mod;//cout<<ans<<endl;
	return ans;
}
int main()  
{
	ll a=2,b=7,n,k,tavan=0,nm=0;
	ll g=xgcd(a,b,x,y);
	cin>>n>>k;
	fac[0]=1;kabe[0]=1;kn[0]=1;
	f(i,1,n+2){ kabe[i]=(kabe[i-1]*(k-2))%mod;kn[i]=(kn[i-1]*k)%mod;}
	f(i,1,100009){
		fac[i]=(fac[i-1]*i)%mod;
	}
	cin>>a1[0];
	sa++;
	f(i,1,n){
		cin>>x;
		if(x==a1[sa-1])
			tavan++;
		else{
			a1[sa]=x;
			sa++;
		}
	}
	if(a1[0]==a1[sa-1])
		tavan++;
	n-=tavan;
	for(ll i=0;i<=n;i+=2){
		nm=0;
		nm+=entekhab(i,n)*entekhab(i/2,i);
		//cout<<" nm :"<<nm;
		nm=nm%mod;
		//cout<<" kabe :"<<kabe[n-i]<<endl;
		nm=(nm*kabe[n-i])%mod;
		//cout<<" nm : "<<nm<<endl;
		sum+=nm;
		sum=sum%mod;
	}
	x=1,y=1;
	g=xgcd(2,mod,x,y);
	x=(x+mod)%mod;
	cout<<((((((kn[n]+mod)-sum)%mod)*kn[tavan])%mod)*x)%mod;
}