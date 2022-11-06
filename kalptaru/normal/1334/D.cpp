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
		int n;
		ll l,r;
		cin>>n>>l>>r;
		int u=2*n-2;
		int f=1;
		while(l>u && u>0)
		{
			l-=u;
			r-=u;
			u-=2;
			f++;
		}
		if(f==n)
		f=1;
		int s=l/2;
		FOR(i,l,r+1)
		{
//			cout<<s<<':';
			if(f==n)
			f=1;
			if(i%2==1)
			{
				cout<<f<<' ';
				s++;
			}
			else
			{
				cout<<f+s<<' ';
//				s++;
				if((s+f)==n)
				{
					f++;
					s=0;
				}
			}
		}
		cout<<'\n';
	}
	return 0;
}