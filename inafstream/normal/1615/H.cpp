#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

namespace mf
{
	int dis[1005],vis[1005],inq[1005],cnt,s,t;
	vector<int> g[1005];
	struct edg
	{
		int y;
		long long z;
	}e[1000005];
	void init(int n,int ss,int ed)
	{
		s=ss;t=ed;
		int i;
		rep(i,n)
		{
			g[i].clear();
		}
		cnt=0;
	}
	void add(int x,int y,long long z)
	{
//		cerr<<x<<' '<<y<<' '<<z<<endl;
		cnt++;
		g[x].push_back(cnt*2-2);
		g[y].push_back(cnt*2-1);
		e[cnt*2-2]=(edg){y,z};
		e[cnt*2-1]=(edg){x,0};
	}
	bool bfs(int s,int t)
	{
		memset(dis,0x1f,sizeof(dis));
		dis[s]=0;inq[s]=1;
		queue<int> qx;qx.push(s);
		while(!qx.empty())
		{
			int x=qx.front();
			inq[x]=0;qx.pop();
			for(int u:g[x])
			{
				if(e[u].z&&dis[e[u].y]>dis[x]+1)
				{
					dis[e[u].y]=dis[x]+1;
					if(!inq[e[u].y])
					{
						qx.push(e[u].y);
						inq[e[u].y]=1;
					}
				}
			}
		}
		return dis[t]<0x1f1f1f1f;
	}
	long long dfs(int x,int ed,long long flw)
	{
		if(x==ed||!flw) return flw;
		long long ans=0;
		for(int u:g[x])
		{
			if(dis[e[u].y]==dis[x]+1&&e[u].z)
			{
				int t=dfs(e[u].y,ed,min(flw,e[u].z));
				ans+=t;flw-=t;
				e[u].z-=t;e[(u)^1].z+=t;
			}
		}
		if(flw)dis[x]=-1;
		return ans; 
	}
	void dinic()
	{
		while(bfs(s,t)) dfs(s,t,0x7fffffffffffffffll);
	}
};

int n,m;
int a[1005],f[1005];
vector<int> lsh;
long long ans;
vector<int> g[1005];
 
int p[1005],tmp[1005],id[1005];

void solve(int l,int r,int vl,int vr)
{
	int i;
	if(l>r) return;
	if(vl+1==vr)
	{
		mf::init(r-l+3,r-l+2,r-l+3);
		for(i=l;i<=r;i++) id[p[i]]=i-l+1;
		for(i=l;i<=r;i++)
		{
			int x=p[i],cst=a[x]<=vl?lsh[vl]-lsh[vr]:lsh[vr]-lsh[vl];
			if(cst>0) mf::add(mf::s,id[x],cst);
			else mf::add(id[x],mf::t,-cst);
			for(int u:g[x]) if(id[u]) mf::add(id[x],id[u],0x1fffffffffffffffll);
		}
		mf::dinic();
		for(i=l;i<=r;i++) if(mf::dis[id[p[i]]]==0x1f1f1f1f) f[p[i]]=vl; else f[p[i]]=vr;
		for(i=l;i<=r;i++) id[p[i]]=0;
		return;
	}
	
	int vmid=(vl+vr)/2;
	mf::init(r-l+3,r-l+2,r-l+3);
	for(i=l;i<=r;i++) id[p[i]]=i-l+1;
	for(i=l;i<=r;i++)
	{
		int x=p[i],cst=a[x]<=vmid?lsh[vmid]-lsh[vmid+1]:lsh[vmid+1]-lsh[vmid];
		if(cst>0) mf::add(mf::s,id[x],cst);
		else mf::add(id[x],mf::t,-cst);
		for(int u:g[x]) if(id[u]) mf::add(id[x],id[u],0x1fffffffffffffffll);
	}
	mf::dinic();
	int cl=l,cr=r;
	for(i=l;i<=r;i++) if(mf::dis[id[p[i]]]==0x1f1f1f1f) tmp[cl++]=p[i]; else tmp[cr--]=p[i];
	for(i=l;i<=r;i++) id[p[i]]=0;
	for(i=l;i<=r;i++) p[i]=tmp[i];
	solve(l,cr,vl,vmid);
	solve(cl,r,vmid,vr);
}

int main()
{
	int i;
	scanf("%d%d",&n,&m);
	rep(i,n) scanf("%d",&a[i]),lsh.push_back(a[i]);
	rep(i,n) p[i]=i;
	sort(lsh.begin(),lsh.end());
	lsh.resize(unique(lsh.begin(),lsh.end())-lsh.begin());
	rep(i,n) a[i]=lower_bound(lsh.begin(),lsh.end(),a[i])-lsh.begin();
	
	rep(i,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
	}
	solve(1,n,0,lsh.size()-1);
	
//	rep(i,n) ans+=abs(lsh[a[i]]-lsh[f[i]]);
//	cout<<ans<<endl;

	rep(i,n) printf("%d ",lsh[f[i]]);
	return 0;
}