#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=2e5+5,L=20;
int n;
int deep[N];
int dfn[N],tot;
namespace TREE
{
int t[N],to[N*2],nex[N*2];
int fa[N],sz[N],son[N],top[N];
int q[N];
void dfs(int x,int fr)
{
	dfn[x]=++tot;
	q[tot]=x;
	fa[x]=fr;sz[x]=1;deep[x]=deep[fr]+1;
	for(int i=t[x];i;i=nex[i])
	{
		int y=to[i];
		if(y==fr)continue;
		dfs(y,x);
		sz[x]+=sz[y];
		if(sz[y]>sz[son[x]])son[x]=y;
	}
}
void init()
{
	rep(i,2,n)
	{
		int x=i,y;
		scanf("%d",&y);
		to[i*2]=y;nex[i*2]=t[x];t[x]=i*2;
		to[i*2+1]=x;nex[i*2+1]=t[y];t[y]=i*2+1;
	}
	dfs(1,0);
	rep(x,1,n)
	if(x!=son[fa[x]])
		for(int y=x;y;y=son[y])top[y]=x;
}
#define fx top[x]
#define fy top[y]
int qiu_lca(int x,int y)
{
	while(fx!=fy)
	if(deep[fx]>deep[fy])x=fa[fx];
	else y=fa[fy];
	return deep[x]<deep[y]?x:y;
}
#undef fx
#undef fy
};
namespace TREE2
{
struct Query
{
	int x,y,lca;
};
Query query[N];
int cnt[N],q[N];
int fa[N];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int f[N][L],mxj[N];
void mark(int x,int y)
{
	while(x=find(x),deep[x]>deep[y])
	{
		fa[x]=TREE::fa[x];
		f[x][0]=y;
	}
}
int t[N],nex[N];
void init(int m)
{
	rep(i,1,m)
	{
		scanf("%d%d",&query[i].x,&query[i].y);
		if(dfn[query[i].x]>dfn[query[i].y])swap(query[i].x,query[i].y);
		nex[i]=t[dfn[query[i].x]];
		t[dfn[query[i].x]]=i;
		++cnt[deep[query[i].lca=TREE::qiu_lca(query[i].x,query[i].y)]];
	}
	rep(i,1,n)cnt[i]+=cnt[i-1];
	rep(i,1,m)q[cnt[deep[query[i].lca]]--]=i;
	rep(i,1,n)fa[i]=i;
	rep(h,1,m)
	{
		int i=q[h];
		mark(query[i].x,query[i].lca);
		mark(query[i].y,query[i].lca);
	}
	rep(i,1,n)
	{
		int x=TREE::q[i];
		for(int j=0;f[x][j];++j)
		{
			mxj[x]=j;
			if(j==L-1)break;
			f[x][j+1]=f[f[x][j]][j];
		}
	}
}	
};
int ans[N];
int t1[N],nex1[N],t2[N],nex2[N],ql[N],qr[N];
int c[N],ans1[N];
void add(int i)
{
	for(;i<=n;i+=i&-i)++c[i];
}
int qiu(int i)
{
	int ans=0;
	for(;i;i-=i&-i)ans+=c[i];
	return ans;
}

int main()
{
//	freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int T,m;
	cin>>n;
	TREE::init();
	cin>>T;
	TREE2::init(T);
	cin>>m;
	rep(i,1,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x==y)continue;
		if(dfn[x]>dfn[y])swap(x,y);
		int lca=TREE::qiu_lca(x,y),dlca=deep[lca];
		if(deep[TREE2::find(x)]>dlca||deep[TREE2::find(y)]>dlca)
		{
			ans[i]=-1;
			continue;
		}
		int fy=y;
		per(j,TREE2::mxj[y],0)
		if(deep[TREE2::f[fy][j]]>dlca)
		{
			ans[i]+=1<<j;
			fy=TREE2::f[fy][j];
		}
		if(x==lca)continue;
		int fx=x;
		per(j,TREE2::mxj[x],0)
		if(deep[TREE2::f[fx][j]]>dlca)
		{
			ans[i]+=1<<j;
			fx=TREE2::f[fx][j];
		}
		++ans[i];
		ql[i]=dfn[fy]-1;qr[i]=ql[i]+TREE::sz[fy];
		int l=dfn[fx]-1,r=l+TREE::sz[fx];
		nex1[i]=t1[l];
		t1[l]=i;
		nex2[i]=t2[r];
		t2[r]=i;
	}
	rep(x,1,n)
	{
		for(int i=TREE2::t[x];i;i=TREE2::nex[i])
			add(dfn[TREE2::query[i].y]);
		for(int i=t1[x];i;i=nex1[i])ans1[i]=qiu(qr[i])-qiu(ql[i]);
		for(int i=t2[x];i;i=nex2[i])ans[i]-=ans1[i]!=(qiu(qr[i])-qiu(ql[i]));
	}
	rep(i,1,m)printf("%d\n",ans[i]+(ans[i]!=-1));
}