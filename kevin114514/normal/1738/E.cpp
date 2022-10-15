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
#define longer __int128_t
void die(string S){puts(S.c_str());exit(0);}
//ll b[100100];
map<ll,int> Mp;
const ll mod=998244353;
ll fact[200100];
ll ksm(ll a,ll b)
{
	if(!b)
		return 1ll;
	if(b%2)
		return ksm(a*a%mod,b/2)*a%mod;
	return ksm(a*a%mod,b/2);
}
ll C(ll n,ll k)
{
	return fact[n]*ksm(fact[k],mod-2)%mod*ksm(fact[n-k],mod-2)%mod;
}
ll calc(ll a,ll b)
{
	ll sum=0;
	for(int i=0;i<=min(a,b);i++)
		sum=(sum+C(a,i)*C(b,i))%mod;
//	cerr<<a<<" "<<b<<" "<<sum<<endl;
	return sum;
}
ll Catalan(ll n)
{
	return C(n+n,n)*ksm(n+1,mod-2)%mod;
}
ll calc2(ll n)
{
	ll sum=0;
	for(int i=0;i<=n;i+=2)
		sum=(sum+C(n,i))%mod;
	for(int i=1;i<=n;i+=2)
		sum=(sum+C(n,i))%mod;
	return sum;
}
int main()
{
	fact[0]=1;
	for(int i=1;i<200100;i++)
		fact[i]=fact[i-1]*i%mod;
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		ll psum=0;
		Mp.clear();
		for(int i=1;i<=n;i++)
		{
			ll x;
			cin>>x;
			psum+=x;
			if(i<n)
				Mp[psum]++;
		}
		ll ans=1;
		for(auto pr:Mp)
		{
			if(pr.first*2<psum)
			{
				ans=ans*calc(pr.second,Mp[psum-pr.first])%mod;
			}
			else if(pr.first*2==psum)
			{
				ans=ans*calc2(pr.second)%mod;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}