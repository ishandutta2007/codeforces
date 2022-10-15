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
#define uni(v) v.resize(unique(ALL(v))-v.begin())
void die(string S){puts(S.c_str());exit(0);}
ll fact[200200];
const ll mod=998244353;
ll ksm(ll a,ll b)
{
	if(!b)
		return 1ll;
	if(b%2)
		return ksm(a*a%mod,b/2)*a%mod;
	return ksm(a*a%mod,b/2);
}
ll C(int n,int k)
{
	if(k<0||n<k)
		return 0ll;
	return fact[n]*ksm(fact[n-k],mod-2)%mod*ksm(fact[k],mod-2)%mod;
}
ll ans[200200];
ll f[200200];
int main()
{
	fact[0]=1;
	for(int i=1;i<200200;i++)
		fact[i]=fact[i-1]*i%mod;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		f[i]=fact[i-1]*fact[n-i]%mod*C((n-1)/2,i-1)%mod;
	ll sum=0;
	for(int i=n;i>=1;i--)
	{
		ll x=f[i];
		f[i]=(f[i]-sum+mod)%mod;
		sum=(sum+x*ksm(i-1,mod-2)%mod)%mod;
	}
	for(int i=1;i<=n;i++)
		cout<<f[i]<<" ";
	return 0;
}