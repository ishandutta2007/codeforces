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
#define lb(v,x) (int)(lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (int)(upper_bound(ALL(v),x)-v.begin())
#define uni(v) v.resize(unique(ALL(v))-v.begin())
#define longer __int128_t
void die(string S){puts(S.c_str());exit(0);}
int a[300300];
vector<int> G[300300];
bool cmp(int x,int y){return a[x]<a[y];}
int dfn[300300];
int exi[300300];
int ord[300300];
int depth[300300];
int cur,edt;
void dfs(int u)
{
	dfn[u]=++cur;
	for(auto v:G[u])
	{
		depth[v]=depth[u]+1;
		dfs(v);
	}
	exi[u]=++edt;
	ord[edt]=u;
}
int curmx;
bool used[300300];
int dfn2[300300];
void dfs2(int u)
{
	if(used[u])
		return ;
	dfn2[u]=++curmx;
	for(auto v:G[u])
		dfs2(v);
}
int posa[300300];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		posa[a[i]]=i;
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		G[u].pb(v);
	}
	for(int i=1;i<=n;i++)
		sort(ALL(G[i]),cmp);
	dfs(1);
	int p=1;
	while(a[ord[p]]==p)
	{
		used[ord[p]]=1;
		dfn2[ord[p]]=p;
		p++;
	}
	ll sum=0;
	for(int i=1;i<=min(p,n);i++)
		sum+=depth[posa[i]];
	if(p<=n)
	{
		int pos=0;
		for(int i=1;i<=n;i++)
			if(a[i]==p)
				pos=i;
		while(pos!=ord[p]&&sz(G[pos]))
		{
			for(auto np:G[pos])
				if(a[np]>a[pos])
				{
					swap(a[np],a[pos]);
					pos=np;
					break;
				}
		}
		if(exi[pos]!=p)
			die("NO");
		dfn2[pos]=p;
		used[pos]=1;
		curmx=p;
		dfs2(1);
		for(int i=1;i<=n;i++)
			if(dfn2[i]!=a[i])
				die("NO");
	}
	cout<<"YES\n";
	cout<<sum<<endl;
	for(int i=1;i<=n;i++)
		cout<<dfn[i]<<" ";
	return 0;
}