#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
//#include <unordered_map>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
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
//			re%=mod;
		}
		a=(a*a);
//		a%=mod;
		b>>=1;
	}
	return re;
}
int main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		FOR(i,0,n)
		{
			FOR(j,0,n)
			{
				if(i==0 && j==0)
				cout<<"0 ";
				else if((j%2)==1)
				cout<<"0 ";
				else
				cout<<po(2,i+j-1)<<' ';
			}
			cout<<'\n';
		}
		int q;
		cin>>q;
		FOR(i,0,q)
		{
			int x=1,y=1;
			bool f=1;
			ll o;
			cin>>o;
			FOR(j,0,2*n-1)
			{
				cout<<x<<' '<<y<<'\n';
				if(f)
				{
					if((o%2)==1)
					{
						x++;
					}
					else
					{
						y++;
						f=0;
					}
				}
				else
				{
					if((o%2)==1)
					{
						y++;
						f=1;
					}
					else
					{
						x++;
					}
				}
				o>>=1;
			}
		}
	}
	return 0;
}