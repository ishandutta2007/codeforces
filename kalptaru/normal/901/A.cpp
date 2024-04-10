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
		}
		a=(a*a);
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
		int h,b=-1;
		cin>>h;
		int a[h+1];
		FOR(i,0,h+1)
		cin>>a[i];
		FOR(i,0,h)
		{
			if(a[i]!=1 && a[i+1]!=1)
			{
				b=i+1;
				break;
			}
		}
		if(b<0)
		cout<<"perfect";
		else
		{
			cout<<"ambiguous"<<'\n';
			int p=0;
			FOR(i,0,h+1)
			{
				FOR(j,0,a[i])
				{
					cout<<p<<' ';
				}
				p+=a[i];
			}
			cout<<'\n';
			p=0;
			FOR(i,0,h+1)
			{
				if(i==b)
				{
					FOR(j,1,a[i])
					{
						cout<<p<<' ';
					}
					cout<<p-1<<' ';
					p+=a[i];
				}
				else
				{
					FOR(j,0,a[i])
					{
						cout<<p<<' ';
					}
					p+=a[i];
				}
			}
			cout<<'\n';
		}
	}
	return 0;
}