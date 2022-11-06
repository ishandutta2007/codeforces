#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod1=1000000007;
ll mod2=67280421310721;
ll mod3=998244353;
ll INF=1e18;
ll po(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b%2==1)
		{
			res*=a;
			res%=mod3;
		}
		a*=a;
		a%=mod3;
		b>>=1;
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
//	cin>>test;
	ll fac[100],faci[100];
	fac[1]=1;
	fac[0]=1;
	faci[1]=1;
	FOR(i,2,100)
	{
		fac[i]=(i*fac[i-1])%mod3;
		faci[i]=po(fac[i],mod3-2);
	}
	while(test--)
	{
		ll d;
		cin>>d;
		ll o=d;
		vector<ll> pr;
		for(ll i=2;(i*i)<d;i++)
		{
			if(o%i==0)
			{
				pr.pb(i);
				while(o%i==0)
				{
					o/=i;
				}
			}
		}
		if(o>1)
		pr.pb(o);
		int q;
		cin>>q;
		ll u,v,n,co;
		FOR(i,0,q)
		{
			ll ans=1;
			cin>>u>>v;
			co=__gcd(u,v);
			n=u/co;
//			cout<<n<<' ';
			int s=0;
			FOR(j,0,pr.size())
			{
				if(n%pr[j]==0)
				{
					
					int c=0;
					while(n%pr[j]==0)
					{
						c++;
						n/=pr[j];
					}
//					cout<<pr[j]<<':'<<c<<' ';
					s+=c;
					ans*=faci[c];
					ans%=mod3;
					if(n==1)
					break;
				}	
			}
			ans*=fac[s];
			ans%=mod3;
			n=v/co;
			s=0;
			FOR(j,0,pr.size())
			{
				if(n%pr[j]==0)
				{
					
					int c=0;
					while(n%pr[j]==0)
					{
						c++;
						n/=pr[j];
					}
//					cout<<pr[j]<<':'<<c<<' ';
					s+=c;
					ans*=faci[c];
					ans%=mod3;
					if(n==1)
					break;
				}	
			}
			ans*=fac[s];
			ans%=mod3;
			cout<<ans<<'\n';
		}
	}
	return 0;
}