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
int fa[300300];
int son[300300];
vector<int> G[300300];
int indeg[300300];
int p[300300];
int dep[300300];
int anc(int x)
{
	if(!fa[x])
		return x;
	return fa[x]=anc(fa[x]);
}
vector<int> ans;
bool vis[300300];
void output(int x)
{
	if(!x)
		return ;
	ans.pb(x);
	output(son[x]);
}
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	while(k--)
	{
		int x,y;
		cin>>x>>y;
		if(son[x]||fa[y])
			die("0");
		son[x]=y;
		fa[y]=x;
	}
	for(int i=1;i<=n;i++) if(!fa[i])
		for(int j=i,d=0;j;j=son[j],d++)
			if(vis[j])
				die("0");
			else
			{
				dep[j]=d;
				vis[j]=1;
			}
	if(*min_element(vis+1,vis+n+1)==0)
		die("0");
	for(int i=1;i<=n;i++)
		if(p[i])
		{
			int f=anc(p[i]),x=anc(i);
			if(f==x)
			{
				if(dep[p[i]]>dep[i])
					die("0");
			}
			else
			{
				G[f].pb(x);
				indeg[x]++;
			}
		}
	queue<int> q;
	for(int i=1;i<=n;i++)
		if(!fa[i]&&!indeg[i])
			q.push(i);
	while(!q.empty())
	{
		int x=q.front();
		output(x);
		q.pop();
		for(auto y:G[x])
		{
			indeg[y]--;
			if(!indeg[y])
				q.push(y);
		}
	}
	if(sz(ans)<n)
		die("0");
	for(auto x:ans)
		cout<<x<<" ";
	return 0;
}