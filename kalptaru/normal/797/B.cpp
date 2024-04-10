#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) ;for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
int dep[200002];
int parent[200002];
int dfs(int i,int j,vector<int> tree[],int d)
{
	int n=i,no;
	int md=d;
	dep[i]=d;
	parent[i]=j;
	FOR(k,0,tree[i].size())
	{
		if(tree[i][k]!=j)
		{
			no=dfs(tree[i][k],i,tree,d+1);
			if(dep[no]>md)
			{
				md=dep[no];
				n=no;
			}	
		}
	}
	return n;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
//	cin>>t;
	while ( t-- ) 
	{
		int n;
		cin>>n;
		ll y;
		ll s=0,ts=0;
		vector<int> a;
		FOR(i,0,n)
		{
			cin>>y;
			if((y+100000)%2==1)
			a.pb(y);
			else if(y>0)
			s+=y;
			
		}
		sort(a.begin(),a.end());
		ll m=-mod;
		for(int i=a.size()-1;i>=0;i--)
		{
			ts+=a[i];
//			cout<<ts<<' ';
			if((a.size()-i)%2==1)
			{
				m=max(ts,m);
			}
		}
		cout<<m+s;
	}
	return 0;
}