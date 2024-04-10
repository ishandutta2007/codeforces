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
struct edge
{
	int x,y,g,s;
	friend operator <(const edge &a,const edge &b)
	{
		return a.g<b.g;
	}
}E[50050];
vector<int> vg;
int Gr[220][220];
bool vis[220];
int fa[220];
int anc(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=anc(fa[x]);
}
int n,m;
bool dfs(int x,int tar)
{
	if(x==tar)
		return true;
	vis[x]=true;
	for(int i=1;i<=n;i++)
		if(!vis[i]&&Gr[x][i])
			if(dfs(i,tar))
				return true;
	return false;
}
int main()
{
	cin>>n>>m;
	ll G,S;
	cin>>G>>S;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
		cin>>E[i].x>>E[i].y>>E[i].g>>E[i].s;
	for(int i=1;i<=m;i++)
		vg.pb(E[i].g);
	sort(E+1,E+m+1);
	srt(vg);
	multiset<pair<int,pii> > ms;
	int silver=1e9+1;
	int p=1;
	ll ans=5e18;
	for(auto gold:vg)
	{
		while(p<=m&&E[p].g<=gold)
		{
			if(E[p].s<=silver)
			{
				ms.insert(mp(E[p].s,mp(E[p].x,E[p].y)));
				Gr[E[p].x][E[p].y]++;
				Gr[E[p].y][E[p].x]++;
				fa[anc(E[p].x)]=anc(E[p].y);
			}
			p++;
		}
		bool f=1;
		for(int i=1;i<=n;i++)
			if(anc(i)!=anc(1))
				f=0;
		if(!f)
			continue;
		auto I=ms.end();
		I--;
		silver=I->first;
		while(sz(ms))
		{
			auto it=ms.end();
			it--;
			Gr[it->second.first][it->second.second]--;
			Gr[it->second.second][it->second.first]--;
			memset(vis,0,sizeof(vis));
//			cout<<"%"<<it->second.first<<" "<<it->second.second<<" "<<Gr[it->second.second][it->second.first]<<endl;
			if(!dfs(it->second.first,it->second.second))
			{
				Gr[it->second.first][it->second.second]++;
				Gr[it->second.second][it->second.first]++;
				break;
			}
			else
			{
				ms.erase(it);
				it=ms.end();
				it--;
				silver=it->first;
			}
		}
//		cout<<gold<<" "<<silver<<endl;
		if(silver!=1e9+1)
			ans=min(ans,G*gold+S*silver);
	}
	if(ans==5e18)
		die("-1");
	cout<<ans<<endl;
	return 0;
}