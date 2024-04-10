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
ll mod=10000000000000000;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		ll x0,y0,ax,ay,bx,by;
		cin>>x0>>y0>>ax>>ay>>bx>>by;
		ll xs,ys,t,x,y;
		cin>>xs>>ys>>t;
		vector<pair<ll,ll> > po;
		po.pb(mp(x0,y0));
		x=x0;
		y=y0;
		ll ma=0,ti,p=0;
		ll n=1;
		while(x<=(4*mod) && y<=(4*mod))
		{
			x=ax*x+bx;
			y=ay*y+by;
			po.pb(mp(x,y));
			n++;
//			cout<<x<<' '<<y<<'\n';			
		}
		ll ans=0;
		FOR(i,0,n-1)
		{
			p=0;
			bool f=0;
			ti=t;
			ti-=(abs(xs-po[i].first)+abs(ys-po[i].second));
			if(ti<0)
			continue;
			p++;
			for(ll j=i-1;j>=0;j--)
			{
				ti-=(abs(po[j+1].first-po[j].first)+abs(po[j+1].second-po[j].second));
				if(ti<0)
				break;
				p++;
			}
			if(ti<0)
			{
//				cout<<p+100<<'\n';
				ans=max(ans,p);
				continue;
			}
			ti-=(abs(po[i+1].first-po[0].first)+abs(po[i+1].second-po[0].second));
			if(ti<0)
			{
//				cout<<p+1000<<'\n';
				ans=max(ans,p);
				continue;
			}
			p++;
			for(ll j=i+1;j<n;j++)
			{
				ti-=(abs(po[j+1].first-po[j].first)+abs(po[j+1].second-po[j].second));
				if(ti<0)
				{
					f=1;
					break;
				}
				p++;
			}
//			cout<<p+10<<'\n';
			ans=max(ans,p);
//			if(f==0)cout<<ti<<'\n';
		}	
		cout<<ans;	
	}
	return 0;
}