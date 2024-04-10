#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
//#include <unordered_map>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
//ll mod=67280421310721;
//ll mod=998244353;
ll INF=1e18;
ll po(ll a,ll b)
{
	ll re=1;
	while(b)
	{
		if(b%2==1)
		{
			re=(re*a);
			re%=mod;
		}
		a=(a*a);
		a%=mod;
		b>>=1;
	}
	return re;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		int n,m,q;
		cin>>n>>m>>q;
		int j=m-n;
		ll a[n],b[m],s=0;
		set<ll> fak;
		FOR(i,0,n)
		{
			cin>>a[i];
		}
		FOR(i,0,m)
		{
			cin>>b[i];
		}
		ll sa=0;
		FOR(i,0,n)
		{
			if(i%2==1)
			{s+=b[i];sa+=a[i];}
			else
			{s-=b[i];sa-=a[i];}
		}
		fak.insert(s);
		ll mas=s;
		ll mis=s;
		FOR(i,n,m)
		{
			s+=(b[i-n]);
			s*=-1;
			if(n%2==1)
			{
				s-=b[i];
			}
			else
			s+=b[i];
			mas=max(mas,s);
			mis=min(mis,s);
			fak.insert(s);
		}
		ll mi,ans=INF;
		if(sa<mas)
		{
			mi=*(fak.upper_bound(sa));
			ans=abs(mi-sa);
		}
		if(sa>=mis)
		{
			mi=*(--fak.upper_bound(sa));
			ans=min(ans,abs(mi-sa));
		}
		cout<<ans<<'\n';
		int l,r;
		ll x;
		FOR(i,0,q)
		{
			ans=INF;
			cin>>l>>r>>x;
			if(r%2==1)
			{
				sa-=x;
			}
			if(l%2==0)
			{
				sa+=x;
			}
			if(sa<mas)
			{
				mi=*(fak.upper_bound(sa));
				ans=abs(mi-sa);
			}
			if(sa>=mis)
			{
				mi=*(--fak.upper_bound(sa));
				ans=min(ans,abs(mi-sa));
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}