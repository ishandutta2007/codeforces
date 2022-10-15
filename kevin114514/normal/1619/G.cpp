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
int x[200200],y[200200],t[200200];
vector<pii> vx[200200],vy[200200];
int fa[200200];
//vector<int> belong[200200];
int mn[200200];
int anc(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=anc(fa[x]);
}
void uni(int u,int v)
{
//	cout<<" # "<<u<<" "<<v<<endl;
	fa[anc(u)]=fa[anc(v)];
}
int main()
{
	int tt;
	cin>>tt;
	while(tt--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=0;i<n;i++)
		{
			fa[i]=i;
//			belong[i].clear();
			mn[i]=inf;
		}
		vector<int> vecx,vecy;
		for(int i=0;i<n;i++)
		{
			vx[i].clear();
			vy[i].clear();
			cin>>x[i]>>y[i]>>t[i];
			vecx.pb(x[i]);
			vecy.pb(y[i]);
		}
		srt(vecx);
		srt(vecy);
		for(int i=0;i<n;i++)
		{
			x[i]=lb(vecx,x[i]);
			y[i]=lb(vecy,y[i]);
			vx[x[i]].pb(mp(vecy[y[i]],i));
			vy[y[i]].pb(mp(vecx[x[i]],i));
		}
		for(int i=0;i<n;i++)
		{
			srt(vx[i]);
			srt(vy[i]);
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<sz(vx[i]);j++)
			{
				int p=lb(vx[i],mp(vx[i][j].first-k,0));
				uni(vx[i][j].second,vx[i][p].second);
				p=lb(vx[i],mp(vx[i][j].first+k+1,0))-1;
				uni(vx[i][j].second,vx[i][p].second);
			}
		for(int i=0;i<n;i++)
			for(int j=0;j<sz(vy[i]);j++)
			{
				int p=lb(vy[i],mp(vy[i][j].first-k,0));
				uni(vy[i][j].second,vy[i][p].second);
				p=lb(vy[i],mp(vy[i][j].first+k+1,0))-1;
				uni(vy[i][j].second,vy[i][p].second);
			}
		for(int i=0;i<n;i++)
		{
			mn[(anc(i))]=min(mn[anc(i)],t[i]);
//			cout<<i<<" "<<fa[i]<<endl;
		}
		vector<int> vect;
		for(int i=0;i<n;i++)
			if(mn[i]<inf)
				vect.pb(mn[i]);
		rsrt(vect);
		int ans=0;
		for(int i=0;i<sz(vect);i++)
			ans=max(ans,min(i,vect[i]));
		cout<<ans<<endl;
	}
	return 0;
}