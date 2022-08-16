#include <bits/stdc++.h>
using namespace std;

#define ll long long
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
#define vll vector<pll >
#define mii map<int,int>
#define mll map<ll,ll>
#define vvi vector<vi >
#define vvl vector<vll >
#define cps CLOCKS_PER_SEC

const int maxn = 1e5+10;
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

mii mymap,mymap2;
int par[maxn];
int val[maxn];

int main()
{
	int n;
	cin>>n;
	int x;
	mii::iterator it1,it2;
	int mx = 0,mn = 1e9+10;
	int maxi =1, mini = 1;
	for(int i = 1;i<=n;i++)
	{
		cin>>x;
		if(i == 1)
			mx = mn = x;
		val[i] = x;
		if(i>1)
		{
			if(x > mx)
			{
				par[i]  = maxi;
				maxi = i;
				mx = x;
			}
			else if(x<mn)
			{
				par[i] = mini;
				mini = i;
				mn = x;
			}
			else
			{
				it2 = mymap.upper_bound(x);
				int x = it2->S;
			//	cout<<i<<" "<<(it2->F)<<" ";
				it2 -- ;
			//	cout<<it2->F<<endl;
				int y = it2->S;
				par[i] = max(x,y);
			}
			cout<<val[par[i]]<<" ";
		}
		mymap[x] = i;
	}
	return 0;
}