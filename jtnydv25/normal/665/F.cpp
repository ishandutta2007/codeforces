#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e7;
bool A[maxn];
int primepi[maxn];
#define vi vector<int>
#define pb push_back
#define vll vector<ll>
vll primes;
void pre()
{
	memset(A,0,sizeof A);
	for(int i = 2;i*i<maxn;i++)
		if(!A[i])
			for(int j = i*i;j<maxn;j+=i)
				A[j] = 1;
	primepi[1]=0;
	for(int i = 2;i<maxn;i++)
	{
		primepi[i] = primepi[i-1];
		if(!A[i]){
			primepi[i]++;
			primes.pb((ll)i);
		}
	}
}

map<ll,ll> myp;
ll ppi(ll n)
{
	if(n<maxn)
		return primepi[n];
	if(myp[n]!=0)
		return myp[n];
	vll sm,la;
	ll N = n;
	ll v = (ll)sqrt(n);
	for(ll i = 0;i<=v;i++)
	{
		sm.pb(i-1);
		if(i==0)
			la.pb(0);
		else
			la.pb(n/i-1);
	}
	for(ll p = 2;p<=v;p++)
	{
		if(sm[p-1] == sm[p])
			continue;
		ll p_cnt = sm[p-1];
		ll q = p*1ll*p;
		ll en = min(v,n/q);
		for(int i = 1;i<=en;i++)
		{
			ll d = p*1ll*i;
			if(d<=v)
			{
				la[i]-=la[d]-p_cnt;
			}
			else
			{
				la[i]-=sm[n/d]-p_cnt;
			}
		}
		for(int i = v;i>=q;i--)
		{
			sm[i]-=sm[i/p]-p_cnt;
		}
	}
	for(int i = 1;i<la.size();i++)
		myp[n/i] = la[i];
	return la[1];
}
int main()
{
	pre();
	ll n;
	cin>>n;
	ll x = max(0LL,(ll)pow(n,1./3)-100);
	while(x*x*x<=n)
		x++;
	x--;
	ll ret = ppi(x) ;
	for(int i = 0;primes[i]*primes[i+1]<=n;i++)
	{
		//cout<<primes[i]<<" ";
		// number of primes > primes[i] , and less than n/primes[i]
		ret += max(0LL,ppi(n/primes[i]) - (i+1));
	}
	cout<<ret<<endl;
}