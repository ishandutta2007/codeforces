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
vector<pii> G[200200];
int color[200200];
vector<int> nG[200200];
void dfs1(int x,int co)
{
	if(color[x])
	{
		if(color[x]!=co)
			die("NO");
		return ;
	}
	color[x]=co;
	for(auto p:G[x])
		dfs1(p.first,3-co);
}
int A[200200],B[200200],C[200200];
int deg[200200],ans[200200];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		A[i]=a;
		B[i]=b;
		C[i]=c;
		G[b].pb(mp(c,a));
		G[c].pb(mp(b,a));
	}
	for(int i=1;i<=n;i++)
		if(!color[i])
			dfs1(i,1);
	for(int i=0;i<m;i++)
	{
		if(A[i]==1)
		{
			if(color[B[i]]==1)
			{
				nG[B[i]].pb(C[i]);
				deg[C[i]]++;
			}
			else
			{
				nG[C[i]].pb(B[i]);
				deg[B[i]]++;
			}
		}
		else
		{
			if(color[B[i]]==2)
			{
				nG[B[i]].pb(C[i]);
				deg[C[i]]++;
			}
			else
			{
				nG[C[i]].pb(B[i]);
				deg[B[i]]++;
			}
		}
	}
	int cnt=0;
	queue<int> q;
	for(int i=1;i<=n;i++)
		if(!deg[i])
			q.push(i);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		ans[x]=++cnt;
		for(auto v:nG[x])
		{
			deg[v]--;
			if(!deg[v])
				q.push(v);
		}
	}
	if(cnt<n)
		die("NO");
	puts("YES");
	for(int i=1;i<=n;i++)
	{
		if(color[i]==1)
			cout<<"L ";
		else	cout<<"R ";
		cout<<ans[i]<<endl;
	}
	return 0;
}