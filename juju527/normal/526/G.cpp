//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=1e5+5;
int n;
struct Edge{int to,w,nxt;}e[2*maxn];
int cnt,head[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
void add(int u,int v,int w){
	e[cnt]=(Edge){v,w,head[u]};
	head[u]=cnt++;
	return ;
}
ll dis;
int p;
void dfs(int x,int fa,ll d){
	if(d>dis)dis=d,p=x;
	for(int i=head[x];i!=-1;i=e[i].nxt){
		int tmp=e[i].to;
		if(tmp==fa)continue;
		dfs(tmp,x,d+e[i].w);
	}
	return ;
}
struct Tree{
	ll s[maxn],mxd[maxn];
	int f[maxn][17],hson[maxn];
	bool leaf[maxn];
	void dfs1(int x,int fa){
		f[x][0]=fa;
		for(int i=1;i<17;i++)f[x][i]=f[f[x][i-1]][i-1];
		ll d=0;int h=0;
		for(int i=head[x];i!=-1;i=e[i].nxt){
			int tmp=e[i].to;
			if(tmp==fa)continue;
			s[tmp]=s[x]+e[i].w;
			dfs1(tmp,x);
			ll w=mxd[tmp]+e[i].w;
			if(d<w)d=w,h=tmp;
		}
		mxd[x]=d;hson[x]=h;
		if(!h)leaf[x]=1;
		return ;
	}
	int tp[maxn],bt[maxn];
	void dfs2(int x,int tpfa){
		tp[x]=tpfa;bt[x]=x;
		if(hson[x])dfs2(hson[x],tpfa),bt[x]=bt[hson[x]];
		for(int i=head[x];i!=-1;i=e[i].nxt){
			int tmp=e[i].to;
			if(tmp==f[x][0]||tmp==hson[x])continue;
			dfs2(tmp,tmp);
		}
		return ;
	}
	ll val[maxn],c[maxn];
	int len;
	ll a[maxn],pre[maxn];
	void init(int rt){
		dfs1(rt,0);dfs2(rt,rt);
		for(int i=1;i<=n;i++)if(leaf[i])a[++len]=val[i]=s[i]-s[f[tp[i]][0]];
		for(int i=1;i<=n;i++){
			ll mx=0,cx=0;
			for(int j=head[i];j!=-1;j=e[j].nxt){
				int tmp=e[j].to;
				if(tmp==f[i][0])continue;
				if(val[bt[tmp]]>mx)cx=mx,mx=val[bt[tmp]];
				else cx=max(cx,val[bt[tmp]]);
			}
			c[i]=cx;
		}
		sort(a+1,a+len+1);reverse(a+1,a+len+1);
		for(int i=1;i<=len;i++)pre[i]=pre[i-1]+a[i];
		return ;
	}
	ll calc(int x,int lim){
		ll res=0;
		if(val[bt[x]]>=a[lim])return pre[lim];
		int u=x;
		for(int j=16;j>=0;j--)if(f[u][j]&&val[bt[f[u][j]]]<a[lim])u=f[u][j];
		u=f[u][0];
		res=max(res,pre[lim]+s[bt[x]]-s[u]-a[lim]);
		if(c[u]<=a[lim+1])res=max(res,pre[lim]+s[bt[x]]-s[u]-mxd[u]);
		return res;
	}
}T1,T2;
int main(){
    int q;
	n=read();q=read();
	memset(head,-1,sizeof(head));
	for(int i=1;i<n;i++){
		int u,v,w;
		u=read();v=read();w=read();
		add(u,v,w),add(v,u,w);
	}
	int x=0,y=0;
	dfs(1,0,0);x=p,dis=0;dfs(x,0,0);y=p;
	T1.init(x);T2.init(y);
	ll lst=0;
	for(int i=1;i<=q;i++){
		int x,y,lim;
		x=(lst+read()-1)%n+1,y=(lst+read()-1)%n+1;
		lim=2*y-1;
		if(lim>=T1.len){printf("%lld\n",lst=T1.pre[T1.len]);continue;}
		lst=T1.calc(x,lim);
		lst=max(lst,T2.calc(x,lim));
		printf("%lld\n",lst);
	}
	return 0;
}