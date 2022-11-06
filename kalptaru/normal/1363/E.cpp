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
void df(int i,int j,vector<int> tree[],int par[])
{
	par[i]=j;
	FOR(k,0,tree[i].size())
	{
		if(tree[i][k]!=j)
		df(tree[i][k],i,tree,par);
		
	}
//	cout<<'k';
	return;
}
ll ans=0;
bool ch[200001];
pair<int,int> co[200001];
pair<int,int> dfs(int i,vector<int> tree[],int par[])
{
	if(ch[i]==1)
	return co[i];
	pair<int,int> s=co[i],u;
	ch[i]=1;
	FOR(j,0,tree[i].size())
	{
		if(tree[i][j]!=par[i])
		{
			u=dfs(tree[i][j],tree,par);
			s.first+=u.first;
			s.second+=u.second;
		}
	}
	return s;
}
int main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		int b[n],c[n];
		pair<ll,int> a[n];
		int zo=0,oz=0;
		FOR(i,0,n)
		{
			cin>>a[i].first>>b[i]>>c[i];
			co[i]=mp(0,0);
			if(b[i]==0 && c[i]==1)
			{
				zo++;
				co[i]=mp(1,0);
			}
			else if(b[i]==1 && c[i]==0)
			{
				oz++;
				co[i]=mp(0,1);
			}
			a[i].second=i;
		}
//		cout<<zo<<' '<<oz<<'\n';
		if(zo!=oz)
		{
			cout<<-1;
			return 0;
		}
		sort(a,a+n);
		int u,v;
		vector<int> tree[n];
		FOR(i,1,n)
		{
			cin>>u>>v;
			tree[u-1].pb(v-1);
			tree[v-1].pb(u-1);
		}
		int par[n];
		df(0,-1,tree,par);
//		FOR(i,0,n)
		FOR(i,0,n)
		{
			int j=a[i].second;
//			cout<<j<<' ';
			co[j]=dfs(j,tree,par);
//			cout<<co[j].first<<' '<<co[j].second<<'\n';
			ll o=min(co[j].first,co[j].second);
			ans+=(2*a[i].first*o);
//			cout<<o<<' ';
			co[j].first-=o;
			co[j].second-=o;
			
		}
		cout<<ans;
	}
	return 0;
}