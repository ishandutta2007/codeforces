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
void die(string S){puts(S.c_str());exit(0);}
vector<pii> G[1010];
bool kill[1010];
bool choose[1010];
void dfs(int u,int fa,int &cnt)
{
//	cout<<u<<" "<<fa<<" "<<cnt<<endl;
	if(!cnt)
		return ;
	for(int i=0;i<sz(G[u])&&cnt;i++) if(G[u][i].first!=fa)
	{
		if(!kill[G[u][i].second])
		{
			choose[G[u][i].second]=1;
			cnt--;
			dfs(G[u][i].first,u,cnt);
		}
		else
		{
			dfs(G[u][i].first,u,cnt);
		}
	}
}
pii edge[1010];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		G[u].pb(mp(v,i));
		G[v].pb(mp(u,i));
		edge[i]=mp(u,v);
	}
	int tot=n-1;
	int ans=0;
	cout<<"? "<<n<<" ";
	for(int i=1;i<=n;i++)
		cout<<i<<" ";
	puts("");
	fflush(stdout);
	cin>>ans;
//	int cnt=1;
	while(tot>1)
	{
		memset(choose,0,sizeof(choose));
		int cnt=tot/2;
		dfs(1,0,cnt);
		set<int> s;
		for(int i=1;i<n;i++)
			if(choose[i])
			{
				s.insert(edge[i].first);
				s.insert(edge[i].second);
			}
//		if(cnt==12)
//			exit(114514);
		cout<<"? "<<sz(s)<<" ";
		for(auto u:s)
			cout<<u<<" ";
		puts("");
//		cnt++;
		int aans=0;
		fflush(stdout);
		cin>>aans;
		if(aans==ans)
		{
			for(int i=1;i<n;i++)
				if(!choose[i])
					kill[i]=1;
		}
		else for(int i=1;i<n;i++)
			if(choose[i])
				kill[i]=1;
		tot=0;
		for(int i=1;i<n;i++)
			if(!kill[i])
				tot++;
	}
	for(int i=1;i<n;i++)
		if(!kill[i])
		{
			cout<<"! "<<edge[i].first<<" "<<edge[i].second<<endl;
			fflush(stdout);
			return 0;
		}
	return 0;
}