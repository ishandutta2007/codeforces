#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
//#include <unordered_map>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
//ll mod=1000000007;
//ll mod=67280421310721;
ll mod=998244353;
ll INF=1e18;
ll po(ll a,ll b)
{
	ll re=1;
	while(b)
	{
		if(b%2==1)
		{
			re=(re*a);
			re%=mod;
		}
		a=(a*a);
		a%=mod;
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
	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		int p[2*n];
		FOR(i,0,2*n)
		{
			cin>>p[i];
		}
		int c=1,pr=p[0];
		vector<int> seg;
		FOR(i,1,2*n)
		{
			if(p[i]>pr)
			{
				pr=p[i];
				seg.pb(c);
				c=1;
			}
			else
			{
				c++;
			}
		}
		seg.pb(c);
		bool ch[n+1]={0};
		ch[0]=1;
		FOR(i,0,seg.size())
		{
//			cout<<seg[i]<<' ';
			FORD(j,n+1,0)
			{
				if(ch[j] && (j+seg[i])<=n)
				ch[(j+seg[i])]=1;
			}
		}
		if(ch[n])
		cout<<"YES\n";
		else
		cout<<"NO\n";
	}
	return 0;
}