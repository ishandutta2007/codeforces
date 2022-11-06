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
		int ans[n];
		int p[11]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
		int c[11]={0};
		int o,co=1;
		FOR(i,0,n)
		{
			cin>>o;
			FOR(j,0,11)
			{
				if(o%p[j]==0)
				{
					ans[i]=j;
					if(c[j]==0)
					{
						c[j]=co;
						co++;
					}
					break;
				}
			}
		}
		cout<<co-1<<'\n';
		FOR(i,0,n)
		{
			cout<<c[ans[i]]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}