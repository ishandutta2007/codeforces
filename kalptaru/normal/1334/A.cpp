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
		int p=0,c=0,u,v;
		bool f=1;
		FOR(i,0,n)
		{
			cin>>u>>v;
			if((u-p)<(v-c) || u<p || v<c)
			f=0;
			p=u;
			c=v;
		}
		if(f)
		cout<<"YES\n";
		else
		cout<<"NO\n";
	}
	return 0;
}