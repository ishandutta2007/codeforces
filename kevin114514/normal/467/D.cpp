#include<bits/stdc++.h>
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
#define int long long
void die(string S){puts(S.c_str());exit(0);}
map<string,int> Mp;
string to_lower(string s)
{
	for(int i=0;i<s.length();i++)
		if(s[i]<='Z')
			s[i]+=('a'-'A');
	return s;
}
pair<int,int> p[300300];
pair<int,int> sccp[300300];
int essay[100100];
int SCC[300300];
vector<int> G[300300],revG[300300],nG[300300];
int cnt;
int getNum(string s)
{
	s=to_lower(s);
	if(Mp[s])
		return Mp[s];
	else
	{
		cnt++;
		Mp[s]=cnt;
		int CNT=0;
		for(int i=0;i<s.length();i++)
			if(s[i]=='r')
				CNT++;
		p[cnt]=mp(CNT,s.length());
		return cnt;
	}
}
int out[300300];
int TIME;
bool used[300300];
void dfs1(int x)
{
	used[x]=true;
	TIME++;
	for(int i=0;i<sz(G[x]);i++)
		if(!used[G[x][i]])
			dfs1(G[x][i]);
	TIME++;
	out[x]=TIME;
}
int Count;
void dfs2(int x)
{
	used[x]=true;
	SCC[x]=Count;
	sccp[Count]=min(sccp[Count],p[x]);
	for(int i=0;i<sz(revG[x]);i++)
		if(!used[revG[x][i]])
			dfs2(revG[x][i]);
}
pair<int,int> node[300300];
pair<int,int> dp[300300];
pair<int,int> dfs3(int x)
{
	if(dp[x].first!=-1)
		return dp[x];
	dp[x]=sccp[x];
	for(int i=0;i<sz(nG[x]);i++)
		dp[x]=min(dfs3(nG[x][i]),dp[x]);
	return dp[x];
}
signed main()
{
	for(int i=0;i<300300;i++)
	{
		sccp[i]=mp(1e18,1e18);
		dp[i]=mp(-1,-1);
	}
	int m,n;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		string s;
		cin>>s;
		essay[i]=getNum(s);
	}
	cin>>n;
	while(n--)
	{
		string s,t;
		cin>>s>>t;
		G[getNum(s)].pb(getNum(t));
		revG[getNum(t)].pb(getNum(s));
	}
	for(int i=1;i<=cnt;i++)
		if(!used[i])
			dfs1(i);
	memset(used,0,sizeof(used));
	for(int i=1;i<=cnt;i++)
		node[i]=mp(out[i],i);
	sort(node+1,node+cnt+1);
	reverse(node+1,node+cnt+1);
	for(int i=1;i<=cnt;i++)
		if(!used[node[i].second])
		{
			Count++;
			dfs2(node[i].second);
		}
	for(int i=1;i<=cnt;i++)
		for(int j=0;j<sz(G[i]);j++)
			nG[SCC[i]].pb(SCC[G[i][j]]);
	pair<int,int> ans=mp(0,0);
	for(int i=0;i<m;i++)
	{
		pair<int,int> tmp=dfs3(SCC[essay[i]]);
		ans.first+=tmp.first;
		ans.second+=tmp.second;
	}
	cout<<ans.first<<" "<<ans.second<<endl;
	return 0;
}