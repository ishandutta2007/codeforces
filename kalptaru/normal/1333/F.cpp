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
//	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		bool p[n+1]={0};
		vector<ll> pr;
		FOR(i,2,n+1)
		{
			if(p[i]==0)
			{
				pr.pb(i);
				cout<<1<<' ';
				int o=2*i;
				while(o<=n)
				{
					p[o]=1;
					o+=i;
				}
			}
		}
		pr.pb(1000000);
		FOR(i,2,n)
		{
			int j=0;
			while((pr[j]*i)<=n && pr[j]<=i && (i%pr[j-1])!=0)
			{
				cout<<i<<' ';
				j++;
			}
		}
	}
	return 0;
}