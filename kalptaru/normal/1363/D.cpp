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
	cin>>test;
	while(test--)
	{
		int n,k;
		cin>>n>>k;
		string s;
		vector<int> a[k];
		int c,o;
		FOR(i,0,k)
		{
			cin>>c;
			FOR(j,0,c)
			{
				cin>>o;
				a[i].pb(o);
			}
		}
		int m,h;
		cout<<"? "<<n;
		FOR(i,0,n)
		cout<<' '<<i+1;
		cout<<'\n';
		cin>>m;
		int l=0,r=k-1;
		int mid;
		vector<int> ou;
		while(l<r)
		{
			mid=(l+r)/2;
			FOR(i,l,mid+1)
			{
				FOR(j,0,a[i].size())
				ou.pb(a[i][j]);
			}
			cout<<"? "<<ou.size();
			FOR(i,0,ou.size())
			cout<<' '<<ou[i];
			cout<<'\n';
			cin>>h;
			if(h==m)
			{
				r=mid;
			}
			else
			l=mid+1;
			ou.clear();
		}
		bool fi[n]={0};
		FOR(i,0,a[l].size())
		{
			fi[a[l][i]-1]=1;
		}
		cout<<"? "<<n-a[l].size();
		FOR(i,0,n)
		{
			if(fi[i]==0)
			cout<<' '<<i+1;
		}
		cout<<'\n';
		cin>>h;
		cout<<"! ";
		FOR(i,0,k)
		{
			if(i==l)
			cout<<' '<<h;
			else
			cout<<' '<<m;
		}
		cout<<'\n';
		cin>>s;
		if(s[0]!='C')
		return 0;
	}
	return 0;
}