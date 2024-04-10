#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#define LL "%I64d"
#else
#define LL "%lld"
#endif

#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define si set<int>
#define sll set<ll>
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define mii map<int,int>
#define mll map<ll,ll>
#define vvi vector<vi >
#define vvl vector<vll >
#define cps CLOCKS_PER_SEC
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";
#define what_is(x) cerr << #x << " is " << x << endl;
#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))

void gett()
{
	cerr<< (clock())/(double)cps<<endl;
}

ll powr(ll a, ll b, ll mod)
{
	ll x = 1%mod;
	a %= mod;
	while(b)
	{
		if(b&1)
			x = (x*a)%mod;
		a = (a*a)%mod;
		b >>= 1;
	}
	return x;
}
ll inv(ll a, ll mod)
{
	return powr(a,mod-2,mod);
}

const int maxn = 1e6+10;
const ll mod = 1e9+7;
const int INF = 1e9+7;
ll fact[maxn];
ll C(int n,int k)
{
	if(n<k || k<0)
		return 0;
	if(n==k || k==0)
		return 1;
	return (fact[n]*inv((fact[k]*fact[n-k])%mod,mod))%mod;
}
int main()
{
	fact[0] = 1;
	for(int i = 1;i<maxn;i++)
		fact[i] = (fact[i-1]*i)%mod;
	int n,k,l,r;
	cin>>n>>k;
	vii vec;
	rep(i,0,n)
	{
		sd(l);
		sd(r);
		vec.eb(mp(l,0));
		vec.eb(mp(r,1));
	}
	sort(vec.begin(),vec.end());
	int cnt = 0,cnt1 = 0,cnt2 = 0;
	int j = 0;
	int present = vec[0].F;
	while(vec[j].F == vec[0].F && j<vec.size())
	{
		if(vec[j].S)
			cnt2++;//right
		else
			cnt1++;//left
		j++;
	}
	ll ret = 0;
	cnt += cnt1;
	ret += C(cnt,k);
	ret %= mod;
	present++;
	cnt-=cnt2;
	while(j<vec.size())
	{
		int x = j;
		cnt1 =0;
		cnt2 = 0;
		while(vec[j].F == vec[x].F&&j<vec.size())
		{
			if(vec[j].S)
				cnt2++;
			else
				cnt1++;
			j++;
		}
		j --;
		ret = (ret+ (vec[j].F - present)*1ll*C(cnt,k))%mod;
		cnt += cnt1;
		ret = (ret+C(cnt,k))%mod;
		present = vec[j].F + 1;
		cnt -= cnt2;
		j++;
	}
	cout<<ret<<endl;
}