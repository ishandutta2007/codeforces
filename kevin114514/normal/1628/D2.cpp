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
const ll mod=1000000007;
ll fact[3003000];
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
int main()
{
	cin.tie();
	cout.tie();
	ios_base::sync_with_stdio(false);
	fact[0]=1;
	for(int i=1;i<3003000;i++)
		fact[i]=fact[i-1]*i%mod;
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,k;
		cin>>n>>m>>k;
		ll ans=0;
		for(int i=n-m;i<=n;i++)
		{
			int j=i+m-n;
			ll x=1ll*k*(m-j)%mod;
			ll ways=C(max(0,i-1),j);
			ways%=mod;
			ans+=x*ksm(ksm(2,mod-2),i)%mod*ways%mod;
			ans%=mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}