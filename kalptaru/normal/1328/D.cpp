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
		cin>>n;
		int t[n];
		int ans[n];
		FOR(i,0,n)
		cin>>t[i];
		int c=-1;
		bool o=1;
		FOR(i,0,n)
		{
			if(t[i]==t[(i+1)%n])
			{
				c=i;
			}
			else
			{
				o=0;
			}
		}
		if(o)
		{
			cout<<1<<'\n';
			FOR(i,0,n)cout<<1<<' ';
		}
		else if(n%2==1)
		{
			if(c==-1)
			{
				cout<<3<<'\n';
				cout<<3;
				FOR(i,1,n)
				{
					cout<<' '<<(i%2)+1;
				}
			}
			else
			{
				cout<<2<<'\n';
				FOR(i,0,c+1)
				{
					cout<<(i%2)+1<<' ';
				}
				FOR(i,c+1,n)
				{
					cout<<((i+1)%2)+1<<' ';
				}
			}
		}
		else
		{
			cout<<2<<'\n';
			FOR(i,0,n)
			{
				cout<<(i%2)+1<<' ';
			}
		}
		cout<<'\n';
	}
	return 0;
}