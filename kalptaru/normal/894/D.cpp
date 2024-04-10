#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
//ll mod=67280421310721;
//ll mod=998244353;
//ll mod=163577857;
ll INF=1e18;
ll po(ll a,ll b)
{
	ll re=1;
	while(b)
	{
		if(b%2==1)
		{
			re=(re*a)%mod;
		}
		a=(a*a)%mod;
		b>>=1;
	}
	return re;
}
void dfs(int i,ll l[],int n,vector<ll> sub[])
{
	if(i>n)
	return;
	dfs(2*i,l,n,sub);
	dfs(2*i+1,l,n,sub);
	sub[i].pb(0);
	int j=0,k=0,n1=sub[2*i].size(),n2=sub[2*i+1].size();
	FOR(g,0,n1+n2)
	{
		if(j<n1)
		{
			if(k<n2)
			{
				if((sub[2*i][j]+l[2*i-1])<(sub[2*i+1][k]+l[2*i]))
				{
					sub[i].pb(sub[2*i][j]+l[2*i-1]);
					j++;
				}
				else
				{
					sub[i].pb(sub[2*i+1][k]+l[2*i]);
					k++;
				}
			}
			else
			{
				sub[i].pb(sub[2*i][j]+l[2*i-1]);
				j++;
			}
		}
		else
		{
			sub[i].pb(sub[2*i+1][k]+l[2*i]);
			k++;
		}
	}
	return;
}
ll sol(int i,ll h,vector<ll> sub[],vector<ll> pre[])
{
	int in=lower_bound(sub[i].begin(),sub[i].end(),h)-sub[i].begin();
//	FOR(j,0,sub[i].size())
//	cout<<sub[i][j]<<',';
//	cout<<':';
	if(in==0)return 0;
	return (in*h-pre[i][in-1]);
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
		ll l[n];
		FOR(i,1,n)
		cin>>l[i];
		vector<ll> sub[2*n+4];
		vector<ll> pre[n+1];
		dfs(1,l,n,sub);
		FOR(i,1,n+1)
		{
			pre[i].pb(0);
			FOR(j,1,sub[i].size())
			{
				pre[i].pb(pre[i][j-1]+sub[i][j]);
			}
		}
		ll a,h,rh,ans,no;
		FOR(i,0,m)
		{
			cin>>a>>h;
			rh=h;
			ans=sol(a,h,sub,pre);
			while(a>1 && h>0)
			{
				h-=l[a-1];
				no=a^1;
//				cout<<ans<<' ';
				ans+=sol(no,h-l[no-1],sub,pre);
				a>>=1;
				if(h>0)
				ans+=h;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}