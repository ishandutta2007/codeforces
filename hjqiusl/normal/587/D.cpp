//~~.
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
#define N 500005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
struct edg
{
	int t,w,id;
	edg(){t=0,w=0,id=0;}
	edg(int x,int y,int z){t=x,w=y,id=z;}
};
map<int,vector<edg>>E[N];
vector<edg>EE[N];
int W[N];
int dfn[N],low[N],sta[N],tp,ins[N],SCC_tot,dfn_Id;
int nod;
int n,m;
int SCC[N];
pa Ed[N];
int id[N][2];
vector<int>G[N];
void ad(int x,int y)
{
	// cout<<"ad "<<x<<" "<<y<<endl;
	G[x].push_back(y);
}
void tarjan(int x)
{
	dfn[x]=++dfn_Id;
	low[x]=dfn[x];
	sta[++tp]=x;
	ins[x]=1;
	for (auto u:G[x])
	{
		if (!dfn[u])
		{
			tarjan(u);
			low[x]=min(low[x],low[u]);
		}
		else
			if (ins[u]) low[x]=min(low[x],dfn[u]);
	}
	if (low[x]==dfn[x])
	{
		++SCC_tot;
		// cout<<"?"<<x<<" "<<SCC_tot<<endl;
		while (sta[tp+1]!=x)
		{
			int u=sta[tp];
			ins[u]=0;
			SCC[u]=SCC_tot;
			tp--;
		}
	}
}			
bool work(int yuz)
{
	nod=0;
	for (int i=1;i<=m;i++)
		id[i][0]=++nod,id[i][1]=++nod;
	for (int now=1;now<=n;now++)
	{
		for (auto j:E[now])
		{
			vector<edg>P=j.se;
			int m=P.size();
			vector<int>pre(m,0);
			vector<int>suf;
			suf=pre;
			for (int i=0;i<m;i++)
			{
				pre[i]=++nod;
				// cout<<"bg "<<pre[i]<<endl;
				if (i) ad(pre[i],pre[i-1]);
				ad(pre[i],id[P[i].id][0]);
				
			}
			for (int i=m-1;i>=0;i--)
			{
				suf[i]=++nod;
				if (i!=m-1) ad(suf[i],suf[i+1]);
				ad(suf[i],id[P[i].id][0]);
			}
			for (int i=0;i<m;i++)
			{
				if(i-1>=0)
					ad(id[P[i].id][1],pre[i-1]);
				if (i+1<m)
					ad(id[P[i].id][1],suf[i+1]);
			}
		}
		vector<edg>P=EE[now];
		if (P.empty()) continue;
		int m=P.size();
		vector<int>pre(m,0);
		vector<int>suf;
		suf=pre;
		for (int i=0;i<m;i++)
		{
			pre[i]=++nod;
			if (i) ad(pre[i],pre[i-1]);
			ad(pre[i],id[P[i].id][1]);
		}
		for (int i=m-1;i>=0;i--)
		{
			suf[i]=++nod;
			if (i!=m-1) ad(suf[i],suf[i+1]);
			ad(suf[i],id[P[i].id][1]);
		}
		for (int i=0;i<m;i++)
		{
			if(i-1>=0)
				ad(id[P[i].id][0],pre[i-1]);
			if (i+1<m)
				ad(id[P[i].id][0],suf[i+1]);
		}
	}
	for (int i=1;i<=m;i++)
		if (W[i]>yuz) ad(id[i][0],id[i][1]);
	for (int i=1;i<=nod;i++) SCC[i]=0;
	for (int i=1;i<=nod;i++)
		if (!dfn[i]) tarjan(i);
	int res=1;
	for (int i=1;i<=m;i++)
		if (SCC[id[i][0]]==SCC[id[i][1]]) res=0;
	SCC_tot=0;
	tp=0;
	dfn_Id=0;
	for (int i=1;i<=nod;i++) dfn[i]=low[i]=ins[i]=sta[i]=0;
	for (int i=1;i<=nod;i++) G[i].clear();
	return res;
}
void BellaKira()
{
	n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read(),cl=read(),w=read();
		Ed[i]=mp(x,y);
		W[i]=w;
		E[x][cl].push_back(edg(y,w,i));
		E[y][cl].push_back(edg(x,w,i));
		EE[x].push_back(edg(y,w,i));
		EE[y].push_back(edg(x,w,i));
	}
	int l=0,r=1e9;
	int ans=-1;
	// cout<<"?"<<work(750000000)<<endl;
	while (l<=r)
	{
		int mid=l+(r-l)/2;
		int now=work(mid);
		// cout<<mid<<"? "<<now<<endl;
		if (now)
		{
			ans=mid;
			r=mid-1;
		} else
		{
			l=mid+1;
		}
	}
	if (ans==-1) return puts("No"),void();
	work(ans);
	puts("Yes");
	// writeln(ans);
	writesp(ans);
	ans=0;
	for (int i=1;i<=m;i++)
		if (SCC[id[i][0]]<SCC[id[i][1]])
		{
			ans++;
		}
	writeln(ans);
	for (int i=1;i<=m;i++) 
		if (SCC[id[i][0]]<SCC[id[i][1]]) writesp(i);
	
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/