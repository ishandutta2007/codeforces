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
vector<int> G[2000200],rG[2000200],Tree[400400],nG[2000200];
int depth[400400],fa[400400];
int deg[2000200],order[2000200];
void dfs(int u,int fat)
{
	depth[u]=depth[fat]+1;
	fa[u]=fat;
	for(auto v:Tree[u]) if(v!=fat)
		dfs(v,u);
}
vector<pair<pii,int>> vec[400400];
char buff[400400];
vector<int> cand[400400];
vector<int> dfn;
bool vis[2000200],vis2[2000200];
int belong[2000200];
void dfs2(int u)
{
	vis[u]=1;
	for(auto v:G[u]) if(!vis[v])
		dfs2(v);
	dfn.pb(u);
}
void dfs3(int u,int x)
{
	vis2[u]=1;
	belong[u]=x;
	for(auto v:rG[u]) if(!vis2[v])
		dfs3(v,x);
}
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		Tree[u].pb(v);
		Tree[v].pb(u);
	}
	dfs(1,0);
	for(int i=1;i<=q;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		scanf("%s",buff);
		int len=strlen(buff);
		vector<int> vp(len);
		int ulen=(len-1+depth[u]-depth[v])/2;
		vp[0]=u;
		for(int i=0;i<ulen;i++)
		{
			u=fa[u];
			vp[i+1]=u;
		}
		int vlen=len-1-ulen;
		for(int i=0;i<vlen;i++)
		{
			vp[len-i-1]=v;
			v=fa[v];
		}
//		for(int i=0;i<len;i++)
//			cout<<vp[i]<<" ";
//		puts("");
		for(int ii=0;ii<len;ii++)
			vec[vp[ii]].pb(mp(mp(buff[ii]-'a',buff[len-ii-1]-'a'),i));
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<26;j++)
		{
			int cnt=0;
			for(auto p:vec[i])
				if(p.first.first==j||p.first.second==j)
					cnt++;
//			cout<<i<<" "<<j<<" "<<cnt<<endl;
			if(cnt==sz(vec[i]))
				cand[i].pb(j);
		}
		while(sz(cand[i])<2)
			cand[i].pb(26);
		for(int j=0;j<2;j++)
			for(auto p:vec[i])
			{
				if(cand[i][j]!=p.first.first)
				{
					G[i+i+j-1].pb((p.second+n)*2);
					G[(p.second+n)*2-1].pb(i+i-j);
				}
//				else
//				{
//					G[i+i+j-1].pb((p.second+n)*2-1);
//					G[(p.second+n)*2-1].pb(i+i+j-1);
//				}
				if(cand[i][j]!=p.first.second)
				{
					G[i+i+j-1].pb((p.second+n)*2-1);
					G[(p.second+n)*2].pb(i+i-j);
				}
				if(cand[i][j]==26)
					G[i+i+j-1].pb(i+i-j);
//				else
//				{
//					G[i+i+j-1].pb((p.second+n)*2);
//					G[(p.second+n)*2].pb(i+i+j-1);
//				}
			}
	}
	int m=(n+q)*2;
	for(int i=1;i<=m;i++)
		for(auto v:G[i])
			rG[v].pb(i);
	for(int i=1;i<=m;i++) if(!vis[i])
		dfs2(i);
	int cnt=0;
	rev(dfn);
	for(auto x:dfn) if(!vis2[x])
		dfs3(x,++cnt);
	for(int i=1;i<=m;i++)
		for(auto v:G[i]) if(belong[i]!=belong[v])
		{
			nG[belong[i]].pb(belong[v]);
//			cout<<belong[i]<<" "<<belong[v]<<endl;
			deg[belong[v]]++;
		}
//	cout<<cnt<<endl;
	queue<int> que;
	int ccnt=0;
	for(int i=1;i<=cnt;i++)
		if(!deg[i])
		{
			que.push(i);
			order[i]=++ccnt;
		}
	while(!que.empty())
	{
		int x=que.front();
		que.pop();
		for(auto y:nG[x])
		{
			deg[y]--;
			if(!deg[y])
			{
				que.push(y);
				order[y]=++ccnt;
			}
		}
	}
	string ans;
	for(int i=1;i<=n;i++)
		if(order[belong[i+i-1]]==order[belong[i+i]])
		{
//			puts("NO");
			die("NO");
		}
		else if(order[belong[i+i-1]]<order[belong[i+i]])
			ans+=(char)(cand[i][1]+'a');
		else	ans+=(char)(cand[i][0]+'a');
	puts("YES");
	puts(ans.c_str());
//	puts("----");
//	for(int i=1;i<=n;i++)
//		cout<<cand[i][0]<<" "<<cand[i][1]<<endl;
//	for(int i=1;i<=m;i++)
//		cout<<order[belong[i]]<<" ";
//	puts("");
//	for(int i=1;i<=m;i++)
//		for(auto v:G[i])
//			cout<<i<<" "<<v<<endl;
	return 0;
}