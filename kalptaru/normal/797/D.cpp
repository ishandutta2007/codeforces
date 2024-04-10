#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
multiset<ll> a,b;
map<ll,int> val;
void dfs(int i,ll v[],int l[],int r[])
{
	if(i==-2)
	return;
	if(val[v[i]]==0)
	{
		if((v[i]<*a.begin() || a.size()==0) && (b.size()==0 || v[i]>*(--b.end())))
		{
			val[v[i]]=1;
			if(b.size()>0);
//			cout<<v[i]<<' '<<*a.begin()<<' '<<*(--b.end())<<'\n';
		}
	}
	a.insert(v[i]);
	dfs(l[i]-1,v,l,r);
	auto q=a.find(v[i]);
	a.erase(q);
	b.insert(v[i]);
	dfs(r[i]-1,v,l,r);
	auto g=b.find(v[i]);
	b.erase(g);
	return;
}
int main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	ll t=1;
//	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int ans=0;
		ll v[n];
		int l[n],r[n],root;
		bool ro[n]={0};
		FOR(i,0,n)
		{
			cin>>v[i]>>l[i]>>r[i];
			if(l[i]>0)ro[l[i]-1]=1;
			if(r[i]>0)ro[r[i]-1]=1;
		}
		FOR(i,0,n)
		{
			if(ro[i]==0)
			root=i;
		}
		dfs(root,v,l,r);
//		cout<<root<<'y';
		FOR(i,0,n)
		{
			if(val[v[i]]==0)
			ans++;
		}
		cout<<ans;
	}
	return 0;
}