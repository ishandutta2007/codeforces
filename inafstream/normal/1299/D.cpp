#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;
 
const int mod=1e9+7;
struct lb
{
	int a[5];
	
	bool ins(int x)
	{
		int i,j;
		for (i=4;i>=0;i--)
		{
			if ((x>>i)&1)
			{
				if (!a[i])
				{
					for (j=0;j<i;j++) if ((x>>j)&1) x^=a[j];
					a[i]=x;
					for (j=i+1;j<=4;j++) if ((a[j]>>i)&1) a[j]^=x;
					return 1;
				}
				x^=a[i];
			}
		}
		return 0;
	}
	
	int hsh()
	{
		int s=0,i;
		for (i=4;i>=0;i--)
		{
			s=((s<<5)|a[i]);
		}
		return s;
	}
	void init(int s)
	{
		int i;
		for (i=0;i<=4;i++)
		{
			a[i]=(s&31);
			s>>=5;
		}
	}
}t1,t2,t3;
lb merge(lb x,lb y,bool &ff)
{
	int i;ff=1;
	for (i=0;i<=4;i++) if (y.a[i]) ff&=x.ins(y.a[i]);
	return x;
}
 
unordered_map<int,int> hsh;///////////////////////////////////////////////////////////////////att
int cnt,fmp[100005],tra[1005][1005];
int gth(int x)
{
	if (hsh.count(x)) return hsh[x];
	fmp[++cnt]=x;
	return hsh[x]=cnt;
}
int dplst[100005],dpcur[100005],f[100005],g[100005],h[100005],vis[100005],con1[100005];
bool ff;
int val[100005],dis[100005],cc[32];
vector<pair<int,int> > e[100005];
int n,m;
 
void trs(int x,int y)
{
	if (x>cnt||y>cnt) exit(-1);
	
	if (tra[x][y])
	{
		if (tra[x][y]!=-1)
		{
			(f[tra[x][y]]+=dplst[x])%=mod; 
		}
		return;
	}
	ff=1;t2.init(fmp[x]);t3=merge(t1,t2,ff);
	if (ff) (f[tra[x][y]=gth(t3.hsh())]+=dplst[x])%=mod;
	else tra[x][y]=-1;
}
 
void dfs(int x,int fa,int typ)
{
	vis[x]=1;
	if (!con1[x]) typ=0;
	if (typ) cc[val[x]^=dis[x]]++;
	int i;
	rep(i,e[x].size())
	{
		int y=e[x][i-1].first,z=e[x][i-1].second;
		if (y==fa) continue;
		if (vis[y]==0)
		{
			dis[y]=dis[x]^z;
			dfs(y,x,typ);
		}
		else if (vis[y]==1)
		{
			if (!t1.ins(z^dis[y]^dis[x])) ff=0;
		}
	}
	vis[x]=2;
}
 
int main()
{
	int i,j,k,l;
	dpcur[gth(0)]=1;
	scanf("%d%d",&n,&m);
	rep(i,m)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if (x==1||y==1)
		{
			con1[x^y^1]=1;
			val[x^y^1]=z;
		}
		else
		{
			e[x].push_back(make_pair(y,z));
			e[y].push_back(make_pair(x,z));
		}
	}
	
	rep(i,n) if (con1[i]&&!vis[i])
	{
		rep(j,cnt)
		{
			dplst[j]=dpcur[j];
		}
		
		t1.init(0);
		ff=1;
		memset(cc,0,sizeof(cc));
		dfs(i,0,1);
		if (!ff) continue;
		int ht1=gth(t1.hsh());
		
		rep(j,cnt) f[j]=0;
		rep(j,cnt)
		{
			trs(j,ht1);
		}
		
		for (j=0;j<32;j++) if (cc[j])
		{
			rep(k,cnt) h[k]=1ll*f[k]*cc[j]%mod;
			for (k=j+1;k<32;k++) if (cc[k])
			{
				rep(l,cnt)
				{
					g[l]=h[l];
				}
				rep(l,cnt) if (g[l])
				{
					t2.init(fmp[l]);
					if (!t2.ins(j^k)) continue;
					(h[gth(t2.hsh())]+=1ll*g[l]*cc[k]%mod)%=mod;
				}
			}
			
			rep(k,cnt) (dpcur[k]+=h[k])%=mod;
		}
	}
	
	int ans=0;
	rep(i,cnt) (ans+=dpcur[i])%=mod;
	cout<<ans<<endl;
	return 0;
}