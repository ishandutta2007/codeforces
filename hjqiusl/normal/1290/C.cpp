//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 600005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,fa[N],w[N],cho[N],ans;
int mst[N];
vector<int>G[N];
int x;
string st;
int gf(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=gf(fa[x]);
}
void merge(int x,int y)
{
	x=gf(x),y=gf(y);
	if (x==y) return;
	w[y]+=w[x];
	w[x]=0;
	mst[y]|=mst[x];
	fa[x]=y;
}
signed main()
{	
	IOS;
	cin>>n>>m;
	cin>>st;
	st=' '+st;
	for (int i=1;i<=m;i++)
	{
		cin>>x;
		for (int j=1;j<=x;j++) 
		{
			int y;
			cin>>y;G[y].push_back(i);
		}
	}
	for (int j=1;j<=m;j++)
		fa[j]=j,w[j]=0,cho[j]=0,fa[j+m]=j+m,w[j+m]=1,cho[j+m]=0;
	for (int i=1;i<=n;i++)
	{
		if (G[i].size()==1)
		{
			int u=G[i][0];
			int x=gf(fa[u]),y=gf(fa[u+m]);
			if (cho[x]) ans-=w[x],cho[x]=0;
			if (cho[y]) ans-=w[y],cho[y]=0;
			if (st[i]=='0') ans+=w[y],cho[y]=1,mst[y]=1;
			else ans+=w[x],cho[x]=1,mst[x]=1;
		}
		else
		if (G[i].size()==2)
		{
			int u=G[i][0],v=G[i][1];
			int x=gf(u),xx=gf(u+m),y=gf(v),yy=gf(v+m);
			if (cho[x])
			{
				ans-=w[x];
				cho[x]=0;
			}
			if (cho[xx])
			{
				ans-=w[xx];
				cho[xx]=0;
			}
			if (cho[y])
			{
				ans-=w[y];
				cho[y]=0;
			}
			if (cho[yy])
			{
				ans-=w[yy];
				cho[yy]=0;
			}
			if (st[i]=='0')
			{
				merge(x,yy),merge(xx,y);
				x=gf(x),xx=gf(xx);
				if (mst[x])
				{
					ans+=w[x];
					cho[x]=1;
				} else
				if (mst[xx])
				{
					ans+=w[xx];
					cho[xx]=1;
				} else
				{
					if (w[x]>w[xx])
					{
						ans+=w[xx];
						cho[xx]=1;
					} else
					{
						ans+=w[x];
						cho[x]=1;
					}
				}
			} else
			{
				merge(x,y),merge(xx,yy);
				x=gf(x),xx=gf(xx);
				if (mst[x])
				{
					ans+=w[x];
					cho[x]=1;
				} else
				if (mst[xx])
				{
					ans+=w[xx];
					cho[xx]=1;
				} else
				{
					if (w[x]>w[xx])
					{
						ans+=w[xx];
						cho[xx]=1;
					} else
					{
						ans+=w[x];
						cho[x]=1;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
				
			
	
	
}	
/*

*/