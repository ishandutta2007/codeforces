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
bool p[2000005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		int a[n];
		int c=0;
		FOR(i,0,n)
		{
			cin>>a[i];
			if(a[i]==1)
			c++;
		}
		FOR(i,2,2000005)
		{
			int t=2;
			if(p[i]==0)
			{
				while((t*i)<2000005)
				{
					p[i*t]=1;
					t++;
				}
			}
		}
		FOR(i,0,n)
		{
			if(a[i]!=1)
			{
				if(c>0)
				{
					if(p[a[i]+1]==0)
					{
						cout<<c+1<<'\n';
						FOR(j,0,c)cout<<1<<' ';
						cout<<a[i];
						return 0;
					}
				}
				if(c<2)
				{
					FOR(j,0,n)
					{
						if(i!=j && a[j]!=1 && p[a[j]+a[i]]==0)
						{
							cout<<2<<'\n'<<a[i]<<' '<<a[j];
							return 0;
						}
						
					}
				}
			}
		}
		if(c>0)
		{
			cout<<c<<'\n';
			FOR(i,0,c)cout<<1<<' ';
		}
		else
		{
			cout<<1<<'\n';
			cout<<a[0];
		}
	}
	return 0;
}