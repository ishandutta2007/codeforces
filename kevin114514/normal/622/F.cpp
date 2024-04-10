#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
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
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define lb(v,x) (lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (upper_bound(ALL(v),x)-v.begin())
void die(string S){puts(S.c_str());exit(0);}
const ll mod=1e9+7;
ll ksm(ll a,ll b)
{
	if(!b)
		return 1ll;
	if(b%2)
		return ksm(a*a%mod,b/2)*a%mod;
	return ksm(a*a%mod,b/2);
}
ll fact[1001000];
int main()
{
	fact[0]=1;
	for(int i=1;i<=1000020;i++)
		fact[i]=fact[i-1]*i%mod;
	int n,k;
	cin>>n>>k;
	if(n<=k+2)
	{
		ll ans=0;
		for(int i=1;i<=n;i++)
			ans=(ans+ksm(i,k))%mod;
		cout<<ans<<endl;
	}
	else
	{
		ll ans=0;
		ll sum=0;
		ll f1=1;
		for(int i=1;i<=k+2;i++)
			f1=f1*(n-i)%mod;
		for(int i=1;i<=k+2;i++)
		{
			sum=(sum+ksm(i,k))%mod;
			ans+=ksm(fact[i-1]*fact[k+2-i]%mod%mod*ksm(mod-1,k+2-i)%mod,mod-2)*f1%mod*sum%mod*ksm(n-i,mod-2)%mod;
			ans%=mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}