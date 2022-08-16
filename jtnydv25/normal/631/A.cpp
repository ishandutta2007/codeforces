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


void gett()
{
	cerr<< (clock())/(double)cps<<endl;
}

const int maxn = 1e3+10;
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

int or1[maxn][maxn],or2[maxn][maxn];
int main()
{
	int a[maxn],b[maxn],n;
	cin>>n;
	for(int i = 1;i<=n;i++)
		cin>>a[i];
	for(int i = 1;i<=n;i++)
		cin>>b[i];
	for(int i = 1;i<=n;i++)
	{
		or1[i][i] = a[i];
		for(int j = i+1;j<=n;j++)
			or1[i][j] = or1[i][j-1]|a[j];
	}
	for(int i = 1;i<=n;i++)
	{
		or2[i][i] = b[i];
		for(int j = i+1;j<=n;j++)
			or2[i][j] = or2[i][j-1]|b[j];
	}
	ll mx = 0;
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=n;j++)
			mx = max(mx,0LL+or1[i][j]+or2[i][j]);
	cout<<mx<<endl;	
}