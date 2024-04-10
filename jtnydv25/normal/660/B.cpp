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

const int maxn = 1e6+10;
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

int num[105][4];
int main()
{
	int n,m;
	cin>>n>>m;
	memset(num,0,sizeof num);
	for(int i  = 1;(i<=m) && (i <= 2*n);i++)
	{
		if(i&1)
			num[(i+1)>>1][0]  = i;
		else
			num[(i+1)>>1][3] = i;
	}
	for(int i = 2*n+1;i<=m;i++)
	{
		if(i&1)
			num[(i-2*n+1)>>1][1] = i;
		else
			num[(i-2*n+1)>>1][2] = i;
	}
	for(int i = 1;i<=n;i++)
	{
		if(num[i][1])
			cout<<num[i][1]<<" ";
		if(num[i][0])
			cout<<num[i][0]<<" ";
		if(num[i][2])
			cout<<num[i][2]<<" ";
		if(num[i][3])
			cout<<num[i][3]<<" ";
	}
}