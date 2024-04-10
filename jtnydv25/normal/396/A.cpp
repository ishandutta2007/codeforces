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
#define vi vector<int>
#define pb push_back
#define F first
#define S second

mii freq;
const int mod = 1e9+7;
const int MAXN = 1e9;
const int maxn = 4e4;
bool A[maxn];
vi primes;
void pre()
{	
	memset(A,0,sizeof A);
	for(int i = 2;i*i<maxn;i++)
		if(!A[i])
			for(int j = i*i;j<maxn;j+=i)
				A[j] = 1;
	for(int i = 2;i<maxn;i++)
		if(!A[i])
			primes.pb(i);		
}
void factorize(int n)
{
	int i = 0;
	int p = primes[0];
	while(p*p<=n)
	{
		if(n%p == 0)
		{
			int k = 0;
			while(n%p == 0)
			{
				n/=p;
				k++;
			}
			if(freq.find(p) == freq.end())
				freq[p] = k;
			else
				freq[p]+=k;
		}
		p = primes[++i];
	}
	if(n!=1)
	{
		if(freq.find(n) == freq.end())
			freq[n] = 1;
		else
			freq[n]++;
	}
}

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
ll inverse[1000];
void pre1()
{
	for(int i = 1;i<1000;i++)
		inverse[i] = inv((ll)i);
}
ll sm(int r, int n) // C(n+r-1,r-1)
{
	ll ret = 1;
	for(int i = 1;i<=r-1;i++)
	{
		ret = (ret*(n+i))%mod;
		ret = (ret*inverse[i])%mod;
	}
	return ret;
}
int main()
{	pre();
	pre1();
	int n,x;
	ll ans = 1;
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cin>>x;
		factorize(x);
	}
	for(mii::iterator it = freq.begin();it!=freq.end();it++)
	{
		int e = it->S;
		ans = (ans*sm(n,e))%mod;
	}
	cout<<ans;
}