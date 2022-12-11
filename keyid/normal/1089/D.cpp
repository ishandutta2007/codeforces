#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long LL;

const int MAXN=100005;

int n,w[MAXN],kpid[MAXN],d[90][90];
set <int> G[MAXN];
vector <int> kp;
bool del[MAXN],deg3[MAXN];
LL ans;

struct Path
{
	int a,b;
	vector <int> v,sumw;
	vector <LL> sumw_pre,sumw_suf;

	void cal()
	{
		sumw.resize(v.size()+1);
		for (int i=1;i<=v.size();i++)
			sumw[i]=sumw[i-1]+w[v[i-1]];
		sumw_pre.resize(v.size()+1);
		for (int i=1;i<=v.size();i++)
			sumw_pre[i]=sumw_pre[i-1]+(LL)i*w[v[i-1]];
		sumw_suf.resize(v.size()+1);
		for (int i=(int)v.size()-1;i>=0;i--)
			sumw_suf[i]=sumw_suf[i+1]+((LL)v.size()-i)*w[v[i]];
	}
};

vector <Path> pa;

void del_1_deg(int u)
{
	del[u]=true;
	int v=*G[u].begin();
	G[v].erase(u);
	w[v]+=w[u];
	ans+=(LL)w[u]*(n-w[u]);
	if (G[v].size()==1)
	{
		assert(!del[v]);
		del_1_deg(v);
	}
}

int main()
{
	#ifdef KeyID
		freopen("read.txt","r",stdin);
	#endif // KeyID
	//The input should be connected and have no loops and no multi-edges
	int m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].insert(v);
		G[v].insert(u);
	}
	for (int i=1;i<=n;i++)
		w[i]=1;
	for (int i=1;i<=n;i++)
		if (!del[i]&&G[i].size()==1)
			del_1_deg(i);
	bool flag=false;
	for (int i=1;i<=n;i++)
		if (!del[i]&&G[i].size()>1)
		{
			flag=true;
			break;
		}
	if (!flag) // The input is a tree
	{
		printf("%lld\n",ans);
		return 0;
	}
	for (int i=1;i<=n;i++)
		if (!del[i]&&G[i].size()>2)
			kp.pb(i);
	if (kp.empty()) // The rest is a circle
		for (int i=1;i<=n;i++)
			if (!del[i])
			{
				assert(G[i].size()==2);
				kp.pb(i);
				break;
			}
	for (int i=1;i<=n;i++)
		kpid[i]=-1;
	//at most 2(m-n) vertices' deg > 2
	assert(kp.size()<=max(1,2*(m-n)));
	for (int i=0;i<kp.size();i++)
		kpid[kp[i]]=i;
	memset(d,0x3f,sizeof(d));
	for (int i=0;i<kp.size();i++)
		d[i][i]=0;
	for (int u:kp)
	{
		while (!G[u].empty())
		{
			int v=*G[u].begin();
			G[u].erase(v);
			G[v].erase(u);
			Path p;
			while (kpid[v]==-1)
			{
				assert(G[v].size()==1);
				p.v.pb(v);
				int nxt=*G[v].begin();
				G[nxt].erase(v);
				v=nxt;
			}
			p.a=u;
			p.b=v;
			int a=kpid[p.a],b=kpid[p.b];
			d[a][b]=d[b][a]=min(d[b][a],(int)p.v.size()+1);
			if (!p.v.empty())
				pa.pb(p);
		}
	}
	for (auto &p:pa)
		p.cal();
	for (int k=0;k<kp.size();k++)
		for (int i=0;i<kp.size();i++)
			for (int j=0;j<kp.size();j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	for (int i=0;i<kp.size();i++)
		for (int j=i+1;j<kp.size();j++)
			ans+=(LL)w[kp[i]]*w[kp[j]]*d[i][j];
	for (const auto &p:pa)
	{
		int a=kpid[p.a],b=kpid[p.b];
		for (int j=0;j<p.v.size();j++)
		{
			int v=p.v[j],da=j+1,db=p.v.size()-j;
			for (int i=0;i<kp.size();i++)
				ans+=(LL)w[v]*w[kp[i]]*min(da+d[a][i],db+d[b][i]);
		}
	}
	assert(pa.size()<=max(1,(int)kp.size()+m-n));
	for (const auto &p:pa)
	{
		int dab=d[kpid[p.a]][kpid[p.b]];
		for (int i=0;i<p.v.size();i++)
		{
			int x=(2*i+dab+p.v.size())/2+1;
			x=min(x,(int)p.v.size());
			//directly walk to (i,x) , back to a then [x,p.v.size())
			ans+=w[p.v[i]]*(p.sumw_pre[x]-p.sumw_pre[i+1]-(LL)(p.sumw[x]-p.sumw[i+1])*(i+1));
			ans+=w[p.v[i]]*((LL)(i+1+dab)*(p.sumw[p.v.size()]-p.sumw[x])+p.sumw_suf[x]);
		}
	}
	for (int i=0;i<pa.size();i++)
	{
		const auto &p1=pa[i];
		int a1=kpid[p1.a],b1=kpid[p1.b];
		for (int j=0;j<p1.v.size();j++)
		{
			int da1=j+1,db1=p1.v.size()-j;
			for (int k=i+1;k<pa.size();k++)
			{
				const auto &p2=pa[k];
				int a2=kpid[p2.a],b2=kpid[p2.b];
				int da2=min(da1+d[a1][a2],db1+d[b1][a2]),db2=min(da1+d[a1][b2],db1+d[b1][b2]);
				int x=(int)p2.v.size()+db2-da2-1;
				if (x<0)
					x=-1;
				else
					x=min(x/2,(int)p2.v.size()-1);
				//[0,x] to a2, (x,p2.v.size()) to b2
				ans+=w[p1.v[j]]*((LL)da2*p2.sumw[x+1]+p2.sumw_pre[x+1]);
				ans+=w[p1.v[j]]*((LL)db2*(p2.sumw[p2.v.size()]-p2.sumw[x+1])+p2.sumw_suf[x+1]);
			}
		}
	}
	printf("%lld",ans);
	return 0;
}