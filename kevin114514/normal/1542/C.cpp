#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
void die(string S){puts(S.c_str());exit(0);}
const ll mod=1e9+7;
ll GCD(ll a,ll b)
{
	if(!b)
		return a;
	return GCD(b,a%b);
}
ll LCM(ll a,ll b)
{
	return a/GCD(a,b)*b;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll x=1;
		ll ans=0;
		for(ll i=2;n;i++)
		{
			ll j=i/GCD(i,x);
			ans+=i*(n-n/j)%mod;
			ans%=mod;
			n/=j;
			x=LCM(x,i);
		}
		cout<<ans<<endl;
	}
	return 0;
}