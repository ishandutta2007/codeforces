#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
//ll mod=67280421310721;
ll mod=998244353;
ll INF=1e9;
struct node
{
	int l=-1,r=-1;
	int z=0,o=0;
};
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
int c=0;
vector<node> ma;
ll ti[31],in[31];
void dfs(ll a,int l,int v)
{
	if(l<0)
	{
		// cout<<v<<"VVV\n";
		return;
	}
	if(a&(1<<l))
	{
		ti[l]+=ma[v].z;
		ma[v].o++;
		if(ma[v].l==-1)
		{
			c++;
			ma[v].l=c;
			node tem;
			ma.pb(tem);
		}
		dfs(a,l-1,ma[v].l);
	}
	else
	{
		in[l]+=ma[v].o;
		ma[v].z++;
		if(ma[v].r==-1)
		{
			c++;
			ma[v].r=c;
			node tem;
			ma.pb(tem);
		}
		dfs(a,l-1,ma[v].r);
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("INPUT.txt", "r", stdin);
	freopen("OUTPUT.txt", "w", stdout);
	#endif
	int test=1;
	// cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		ll a;
		node tem;
		ma.pb(tem);
		FOR(i,0,n)
		{
			cin>>a;
			dfs(a,29,0);
		}
		ll o=0,cn=0;
		FOR(i,0,30)
		{
			// cout<<ti[i]<<' '<<in[i]<<'\n';
			if(in[i]>(ti[i]))
			{
				o+=(1<<i);
				cn+=(ti[i]);
			}
			else
			{
				cn+=in[i];
			}
		}
		cout<<cn<<' '<<o;
	}
	return 0;
}