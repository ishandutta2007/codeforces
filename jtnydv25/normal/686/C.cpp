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

int main()
{
	ll n,m;
	cin>>n>>m;
	int np = 0,mp = 0;
	int x,y;
	if(n * m >= 7000000)
	{
		cout<<0<<endl;
		return 0;
	}
	x = n;
	y = m;
	while(powr(7,np) < n)
		np++;
	while(powr(7,mp)<m)
		mp++;
	np = max(np,1);
	mp= max(mp,1);
	bool cnt[10];
	ll ret = 0;
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<m;j++)
		{
			memset(cnt,0,sizeof cnt);
			x = i;
			y = j;
			int p;
			bool flag = 0;
			for(int k = 0;k<np;k++)
			{
				p = x%7;
				x/=7;
				if(cnt[p]){
					flag = 1;
					break;
				}
				else
					cnt[p] = 1;
			}
			if(!flag)
				for(int k = 0;k<mp;k++)
				{
					p = y%7;
					y/=7;
					if(cnt[p])
					{
						flag = 1;
						break;
					}
					else
						cnt[p] = 1;
				}	
			if(!flag)	
			{
				assert(x==0);
				assert(y == 0);
				ret++;
			}
		}
	}
	cout<<ret;
}