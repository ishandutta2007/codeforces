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
ll mod=1000000007;
//ll mod=67280421310721;
//ll mod=998244353;
ll INF=1e18;
ll po(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b%2==1)
		{
			res*=a;
			res%=mod;
		}
		a*=a;
		a%=mod;
		b>>=1;
	}
	return res;
}
int mi;
int dfs(int i,int j,vector<int> tree[],bool l[])
{
	bool o=0,e=0;
	FOR(k,0,tree[i].size())
	{
		if(tree[i][k]!=j)
		{
			if(dfs(tree[i][k],i,tree,l)%2==0)
			{
				e=1;
			}
			else
			{
				o=1;
			}
		}
	}
	if(e)
	{
		if(o)
		{
			mi=3;
		}
		return 1;
	}
	else
	{
		return 0;
	}
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
		int n;
		cin>>n;
		bool l[n]={0};
		vector<int> tree[n];
		int u,v,no;
		FOR(i,1,n)
		{
			cin>>u>>v;
			u--;
			v--;
			if(tree[u].size()>0)
			{
				l[u]=1;
				no=u;	
			}
			if(tree[v].size()>0)
			l[v]=1;
			tree[u].pb(v);
			tree[v].pb(u);
		}
		int ma=n-1;
		FOR(i,0,n)
		{
			int c=0;
			FOR(j,0,tree[i].size())
			{
				if(l[tree[i][j]]==0)
				c++;
			}
			ma-=(max(c-1,0));
		}
		mi=1;
		dfs(no,0,tree,l);
		cout<<mi<<' '<<ma<<'\n';
	}
	return 0;
}