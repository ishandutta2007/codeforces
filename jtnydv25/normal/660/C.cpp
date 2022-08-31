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

const int maxn = 3e5+10;
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

int cnt[maxn];
int binsearch(int k, int n)
{
	if(cnt[n] <= k)
		return n + 1;
	int a = 0, b = n;
	while(a<b)
	{
		int mid  = (a+b)/2;
		if(cnt[mid] > k)
			b = mid;
		else
			a = mid + 1;
	}
	return a;
}
int a[maxn];
int main()
{
	cnt[0] = 0;
	int n,k,x;
	cin>>n>>k;
	for(int i = 1;i<=n;i++)
	{
		cnt[i] = cnt[i-1];
		cin>>x;
		a[i] = x;
		if(x == 0)
			cnt[i]++;
	}
	pii p;
	p.F = 0;
	p.S = 0;	
	int mxsz = 0;
	for(int i = 1;i<=n;i++)
	{
		// search for min j, s.t. cnt[j] > cnt[i-1] + k
		int ind = binsearch(cnt[i-1] + k, n);
		int sz = ind - i ;
		if(sz > mxsz)
		{
			mxsz = sz;
			p.F = i;
			p.S = ind - 1;
		}
	}
	cout<<mxsz<<"\n";
	if(p.F == 0)
	{
		for(int i = 1;i<=n;i++)
			cout<<a[i]<<" ";
		return 0;
	}
	for(int i = 1;i<p.F;i++)
		cout<<a[i]<<" ";
	for(int i = p.F;i<=p.S;i++)
		cout<<1<<" ";
	for(int j = p.S+1;j<=n;j++)
		cout<<a[j]<<" ";
}