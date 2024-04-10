#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define lb(v,x) (lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (upper_bound(ALL(v),x)-v.begin())
void die(string S){puts(S.c_str());exit(0);}
vector<int> V;
vector<int> G[200200];
int md[200200];
void dfs1(int u,int fa)
{
	md[u]=1;
	for(auto v:G[u]) if(v!=fa)
	{
		dfs1(v,u);
		md[u]=max(md[v]+1,md[u]);
	}
}
void dfs2(int u,int fa,int len)
{
	int mx=-1;
	for(auto v:G[u]) if(v!=fa)
		mx=max(mx,md[v]);
	if(mx<0)
	{
		V.pb(len);
		return ;
	}
	bool flg=0;
	for(auto v:G[u]) if(v!=fa)
	{
		if(mx==md[v]&&!flg)
		{
			flg=1;
			dfs2(v,u,len+1);
		}
		else	dfs2(v,u,1);
	}
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs1(1,0);
	dfs2(1,0,1);
	int m=sz(V);
	rsrt(V);
	if(k>=m)
	{
		if(m>n/2)
			cout<<1ll*(n-m)*m<<endl;
		else if(k>=n/2)
			cout<<1ll*(n-n/2)*(n/2)<<endl;
		else	cout<<1ll*k*(n-k)<<endl;
	}
	else
	{
		int b=n;
		for(int i=0;i<k;i++)
			b-=V[i];
		if(b<n/2)
			cout<<1ll*(n-b-k)*(k-b)<<endl;
		else	cout<<1ll*(n-k)*(k)-1ll*(n-n/2)*(n/2)<<endl;
	}
	return 0;
}