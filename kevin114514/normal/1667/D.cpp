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
#define uni(v) v.resize(unique(ALL(v))-v.begin())
void die(string S){puts(S.c_str());exit(0);}
vector<int> G[200200];
vector<int> nG[200200];
int faedge[200200];
int indeg[200200];
int fat[200200];
bool fl;
void dfs(int u,int fa)
{
	fat[u]=fa;
	faedge[u]=(sz(G[u])+1)/2;
	for(auto v:G[u]) if(v!=fa)
	{
		dfs(v,u);
		faedge[u]-=faedge[v];
	}
	if(u==1&&faedge[u]==1)
	{
		fl=0;
		return ;
	}
	if(faedge[u]>1||faedge[u]<0)
	{
		fl=0;
		return ;
	}
	vector<int> od,ev;
	if(u>1)
	{
		if(faedge[u])
			od.pb(u);
		else	ev.pb(u);
	}
	for(auto v:G[u]) if(v!=fa)
	{
		if(faedge[v])
			od.pb(v);
		else	ev.pb(v);
	}
	if(sz(ev)==sz(od))
		swap(ev,od);
	else if(sz(ev)+1!=sz(od))
	{
		fl=0;
		return ;
	}
	for(int i=0;i<sz(ev);i++)
	{
		nG[od[i]].pb(ev[i]);
		indeg[ev[i]]++;
	}
	for(int i=1;i<sz(od);i++)
	{
		nG[ev[i-1]].pb(od[i]);
		indeg[od[i]]++;
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<=n;i++)
		{
			G[i].clear();
			nG[i].clear();
			indeg[i]=0;
		}
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			G[u].pb(v);
			G[v].pb(u);
		}
		fl=1;
		dfs(1,0);
		if(!fl)
		{
			puts("NO");
		}
		else
		{
			puts("YES");
			queue<int> que;
			for(int i=2;i<=n;i++)
				if(!indeg[i])
					que.push(i);
			while(!que.empty())
			{
				int x=que.front();
				que.pop();
				cout<<x<<" "<<fat[x]<<endl;
				for(auto y:nG[x])
				{
					indeg[y]--;
					if(!indeg[y])
						que.push(y);
				}
			}
		}
	}
	return 0;
}