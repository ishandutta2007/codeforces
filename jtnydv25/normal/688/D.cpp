#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define vi vector<int>
#define pb push_back
#define mp make_pair
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


#define forn(i, n) for (int i = 0; i < int(n); i++)
#define nfor(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())

#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))

void gett()
{
	cerr<< (clock())/(double)cps<<endl;
}
	
const ll mod = 1e9+7;

ll powr(ll a, ll b)
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
ll inv(ll a)
{
	return powr(a,mod-2);
}

const int maxn = 1e6+10;
int factor[maxn];
vi primes;
vi val2(100,0);
vi val1;
int num;
int main()
{
	memset(factor,0,sizeof factor);
	for(int i = 2;i*i<maxn;i++)
		if(!factor[i])
			for(int j = i*i;j<maxn;j+=i)
				factor[j] = i;
	for(int i = 0;i<maxn;i++)	
		if(!factor[i])
			factor[i] = i;	
	int n,k;
	cin>>n>>k;
	int k1 = k;
	if(k == 1)
	{
		cout<<"Yes\n";
		return 0;
	}
	while(k1 != 1)
	{
		int t = 0;
		int p = factor[k1];
		while(k1%p == 0)
		{
			k1/=p;
			t++;
		}
		primes.pb(p);
		val1.pb(t);
	}

	for(int i = 0;i<n;i++)
	{
		scanf("%d",&num);
		for(int j = 0;j<primes.size();j++)
		{
			int t =0,p = primes[j];
			while(num%p == 0)
			{
				num/=p;
				t++;
			}
			val2[j] = max(val2[j],t);
		}
	}
	for(int i = 0;i<primes.size();i++)
	{
		if(val1[i]>val2[i])
		{
			cout<<"No\n";
			return 0;
		}
	}
	cout<<"Yes\n";
}