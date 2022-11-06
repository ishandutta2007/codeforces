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
		int b[n];
		set<int> rem;
		int a[2*n];
		FOR(i,0,2*n)
		{
			rem.insert(i+1);
		}
		FOR(i,0,n)
		{
			cin>>b[i];
			rem.erase(b[i]);
		}
		bool f=0;
		FOR(i,0,n)
		{
			if(rem.upper_bound(b[i])==rem.end())
			{
				f=1;
				break;
			}
			a[2*i+1]=*rem.upper_bound(b[i]);
			rem.erase(a[2*i+1]);
			a[2*i]=b[i];
		}
		if(f)
		{
			cout<<-1<<'\n';
			continue;
		}
		FOR(i,0,2*n)
		{
			cout<<a[i]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}