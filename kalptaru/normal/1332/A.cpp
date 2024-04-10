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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
	cin>>test;
	while(test--)
	{
		ll a,b,c,d;
		cin>>a>>b>>c>>d;
		ll x,y,x1,y1,x2,y2;
		cin>>x>>y>>x1>>y1>>x2>>y2;
		if(a>b)
		{
			if((x-x1)<(a-b))
			{
				cout<<"NO"<<'\n';
				continue;
			}
		}
		else if(a<b)
		{
			if((x2-x)<(b-a))
			{
				cout<<"NO"<<'\n';
				continue;
			}
		}
		else if((a+b)>0)
		{
			if(x==x1 && x==x2)
			{
				cout<<"NO"<<'\n';
				continue;
			}
		}
		if(d>c)
		{
			if((y2-y)<(d-c))
			{
				cout<<"NO"<<'\n';
				continue;
			}
		}
		else if(c>d)
		{
			if((y-y1)<(c-d))
			{
				cout<<"NO"<<'\n';
				continue;
			}
		}
		else if((c+d)>0)
		{
			if(y==y1 && y==y2)
			{
				cout<<"NO"<<'\n';
				continue;
			}
		}
		cout<<"YES"<<'\n';
		
	}
	return 0;
}