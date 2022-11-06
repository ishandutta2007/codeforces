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
		int a;
		vector<int> e,o;
		FOR(i,0,2*n)
		{
			cin>>a;
			if((a%2)==0)
			e.pb(i);
			else
			o.pb(i);
		}
		int ne=e.size(),no=o.size();
		if((ne%2)==0)
		{
			if(ne==0)
			no-=2;
			else
			ne-=2;
		}
		else
		{
			ne--;
			no--;
		}
		for(int i=0;i<ne;i+=2)
		{
			cout<<e[i]+1<<' '<<e[i+1]+1<<'\n';
		}
		for(int i=0;i<no;i+=2)
		{
			cout<<o[i]+1<<' '<<o[i+1]+1<<'\n';
		}
		
	}
	return 0;
}