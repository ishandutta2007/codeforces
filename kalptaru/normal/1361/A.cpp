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
//	cin>>test;
	while(test--)
	{
		int n,m;
		cin>>n>>m;
		vector<int> gra[n];
		int u,v;
		FOR(i,0,m)
		{
			cin>>u>>v;
			gra[u-1].pb(v-1);
			gra[v-1].pb(u-1);
		}
		pair<int,int> des[n];
		FOR(i,0,n)
		{
			cin>>des[i].first;
			des[i].second=i;
		}
		sort(des,des+n);
		int ch[n]={0};
		bool f=1;
		FOR(i,0,n)
		{
//			cout<<i<<' ';
			int o=des[i].second,p=des[i].first;
			ch[o]=p;
			bool c[p]={0};
			FOR(j,0,gra[o].size())
			{
				if(ch[gra[o][j]]>p)
				{
					continue;
				}
				else if(ch[gra[o][j]]==p)
				{
					f=0;
					break;
				}
				c[ch[gra[o][j]]]=1;
			}
			if(f==0)
			break;
			FOR(j,1,p)
			{
				if(c[j]==0)
				{
					f=0;
					break;
				}
			}
			if(f==0)
			break;
		}
		if(f==0)
		{
			cout<<-1;
		}
		else
		{
			FOR(i,0,n)
			cout<<des[i].second+1<<' ';
		}
	}
	return 0;
}