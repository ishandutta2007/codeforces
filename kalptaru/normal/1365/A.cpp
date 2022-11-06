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
		int n,m;
		cin>>n>>m;
		bool p;
		bool ch[m]={0},bh[n]={0};
		FOR(i,0,n)
		{
			FOR(j,0,m)
			{
				cin>>p;
				if(p)
				{
					ch[j]=1;
					bh[i]=1;
				}
			}
		}
		int a=0,b=0;
		FOR(i,0,n)
		{
			if(bh[i]==0)
			a++;
		}
		FOR(i,0,m)
		{
			if(ch[i]==0)
			b++;
		}
		a=min(a,b);
		if(a%2==0)
		{
			cout<<"Vivek"<<'\n';
		}
		else
		{
			cout<<"Ashish"<<'\n';
		}
		
	}
	return 0;
}