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
		if(n==1)
		{
			cout<<-1<<'\n';
		}
		else
		{
			if(n%3==1)
			{
				FOR(i,2,n)
				cout<<2;
				cout<<33<<'\n';
			}
			else
			{
				FOR(i,1,n)
				{
					cout<<2;
				}
				cout<<3<<'\n';
			}
		}
	}
	return 0;
}