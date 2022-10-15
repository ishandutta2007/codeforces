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
#define lb(v,x) (int)(lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (int)(upper_bound(ALL(v),x)-v.begin())
#define uni(v) v.resize(unique(ALL(v))-v.begin())
void die(string S){puts(S.c_str());exit(0);}
ll fact[400200];
const ll mod=1e9+7;
int a[200200];
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
	if(n<k||k<0)
		return 0;
	return fact[n]*ksm(fact[k],mod-2)%mod*ksm(fact[n-k],mod-2)%mod;
}
int main()
{
	fact[0]=1;
	for(int i=1;i<400200;i++)
		fact[i]=fact[i-1]*i%mod;
	int n;
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
	{
		scanf("%d",a+i);
		a[i]--;
	}
	if(a[0]<0)
		die("0");
	ll ans=0;
	for(int i=0;i<=n;i++)
		ans+=C(i+a[i],i),ans%=mod;
	for(int i=1;i<=n;i++)
		for(int j=a[i]+1;j<=a[i-1];j++)
			ans+=C(i-1+j,i-1),ans%=mod;
	for(int j=0;j<=a[n];j++)
		ans+=C(n+j,n),ans%=mod;
	cout<<(ans-1+mod)%mod<<endl;
	return 0;
}