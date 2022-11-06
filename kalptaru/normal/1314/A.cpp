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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		ll n;
		cin>>n;
		pair<ll,ll> a[n];
		FOR(i,0,n)
		{
			cin>>a[i].first;
			a[i].second=i;
		}
		
		ll t[n];
		FOR(i,0,n)
		cin>>t[i];
		sort(a,a+n);
		ll mv=0;
		multiset<int> ti;
		ll s=0;
		ll ans=0;
		FOR(i,0,n)
		{
			if(a[i].first==mv)
			{
				s+=t[a[i].second];
				ti.insert(t[a[i].second]);
			}
			else
			{
				while(ti.size()>0 && a[i].first!=mv)
				{
					s-=(*--ti.end());
					ti.erase(--ti.end());
					ans+=s;
					mv++;
				}
				mv=a[i].first;
				ti.insert(t[a[i].second]);
				s+=t[a[i].second];
			}
//			cout<<ans<<' ';
		}
		while(ti.size()>0)
		{
			s-=(*--ti.end());
			ti.erase(--ti.end());
			ans+=s;
			mv++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}