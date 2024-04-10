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
int d[1010];
bool vis[1010];
int fa[1010];
int anc(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=anc(fa[x]);
}
int query(int x)
{
	cout<<"? "<<x<<"\n";
	fflush(stdout);
	int y;
	cin>>y;
	return y;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			fa[i]=i,vis[i]=0;
		for(int i=1;i<=n;i++)
			cin>>d[i];
		int tot=0;
		vector<pii> vec;
		for(int i=1;i<=n;i++)
			vec.pb(mp(d[i],i));
		rsrt(vec);
		for(auto pr:vec) if(!vis[pr.second])
		{
			int u=pr.second;
			int de=d[u];
			vis[u]=1;
			if(de)
				while(--de)
				{
					int v=query(u);
					fa[anc(u)]=anc(v);
					if(vis[v])
						break;
					vis[v]=1;
				}
		}
		cout<<"! ";
		for(int i=1;i<=n;i++)
			cout<<anc(i)<<" ";
		cout<<'\n';
		fflush(stdout);
	}
	return 0;
}