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
//ll mod=1000000007;
//ll mod=67280421310721;
ll mod=998244353;
ll INF=1e18;
ll po(ll a,ll b)
{
	ll re=1;
	while(b)
	{
		if(b%2==1)
		{
			re=(re*a);
//			re%=mod;
		}
		a=(a*a);
//		a%=mod;
		b>>=1;
	}
	return re;
}
vector<ll> pri;
bool p[100001];
int main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int test=1;
	FOR(i,2,100001)
	{
		if(p[i]==0)
		{
			pri.pb(i);
			for(int j=2*i;j<1001;j+=i)
			p[j]=1;
		}
	}
	cin>>test;
	while(test--)
	{
		ll q,x=1,r=1000000000,g,g2;
		int j=0,pj=0;
		vector<ll> oc;
		int i=0;
		while(1)
		{
			q=1;
			pj=j;
			while(q<1e15)
			{
				q*=pri[j];
				j++;
			}
			cout<<"? "<<q<<'\n';
			cin>>g;
			i++;
			if(i==22)
			break;
			q=1;
			FOR(k,pj,j)
			{	
				if(g%pri[k]==0)
				{
					oc.pb(pri[k]);
					if(q==1)
					{
						q=po(pri[k],(log(r)/log(pri[k])));
					}
					else
					{
						q*=po(pri[k],(log(r)/log(pri[k])));
						cout<<"? "<<q<<'\n';
						cin>>g2;
						i++;
						if(i==22)
						break;
						q=1;
						x*=g2;
						r/=g2;
					}
					
				}
			}
			if(i>=22)
			break;
			if(q>1)
			{
				cout<<"? "<<q<<'\n';
				cin>>g2;
				i++;
				if(i==22)
				break;
				q=1;
				x*=g2;
				r/=g2;
			}
		}
		ll ans=1,ni=9;
		FOR(i,0,oc.size())
		{
			int c=1;
			while(x%oc[i]==0)
			{
				c++;
				x/=oc[i];
			}
			ans*=c;
		}
		cout<<"! "<<max(ans*2,ans+7)<<'\n';
	}
	return 0;
}