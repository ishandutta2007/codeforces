#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define sz(Vector) (int)(Vector.size())
using namespace std;
const ll mod=1e9+7;
ll fact[400400];
ll fpw(ll a,ll b)
{
	if(!b)
		return 1ll;
	ll ret=a*(b%2)+1-(b%2);
	return ret*fpw(a*a%mod,b/2)%mod;
}
ll inv(ll x)
{
	return fpw(x,mod-2);
}
ll C(ll a,ll b)
{
	return fact[a]*inv(fact[b])%mod*inv(fact[a-b])%mod; 
}
int main()
{
//	cout<<inv(2)<<endl;
	fact[0]=1;
	for(int i=1;i<400400;i++)
		fact[i]=fact[i-1]*i%mod;
	int t;
	cin>>t;
	while(t--)
	{
		ll n,l,r;
		cin>>n>>l>>r;
		ll mxdelta=min(1-l,r-n);
		ll ans=mxdelta*C(n,n/2)*(1+n%2)%mod;
//		cout<<ans<<endl;
		for(ll delta=mxdelta+1;delta<=mxdelta+n;delta++)
		{
			ll mustadd=max(0ll,l+delta-1);
			ll mustminus=max(0ll,n-r+delta);
//			cout<<delta<<" "<<mustadd<<" "<<mustminus<<endl;
			if(mustadd+mustminus>n||mustadd>(n+1)/2||mustminus>(n+1)/2)
				break;
			ans+=C(n-mustadd-mustminus,n/2-mustadd);
			if(n%2)
				ans+=C(n-mustadd-mustminus,n/2+1-mustadd);
//			if(mustadd==mustminus&&n%2==0);
//			else	ans+=C(n-mustadd-mustminus,n/2-mustminus);
			ans%=mod; 
		}
		cout<<ans<<endl;
//		cout<<C(2,1)<<endl; 
	}
	return 0;
}