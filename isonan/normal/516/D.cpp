#include <cstdio>
#include <algorithm>

int head[100001],nxt[200001],b[200001],v[200001],k,n,q,fa[100001][21],add[100001];
long long V[100001],l,dis[100001];
void push(int s,int t,int val){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	v[k]=val;
}
void getdis(int x,int f,long long dis){
	::dis[x]=dis;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)getdis(b[i],x,dis+v[i]);
}
void dfs(int x,int f){
	fa[x][0]=f;
	for(int i=1;i<=20;i++)fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)dfs(b[i],x);
}
void getval(int x,int f){
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)getval(b[i],x),add[x]+=add[b[i]];
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v,w;i<n;i++){
		scanf("%d%d%d",&u,&v,&w);
		push(u,v,w);
		push(v,u,w);
	}
	getdis(1,0,0);
	int p1=1,p2=1;
	for(int i=2;i<=n;i++)if(dis[i]>dis[p1])p1=i;
	getdis(p1,0,0);
	for(int i=2;i<=n;i++)if(dis[i]>dis[p2])p2=i;
	for(int i=1;i<=n;i++)V[i]=dis[i];
	getdis(p2,0,0);
	for(int i=1;i<=n;i++)V[i]=std::max(V[i],dis[i]);
//	for(int i=1;i<=n;i++)printf("%lld ",V[i]);putchar('\n');
	p1=1;
	for(int i=2;i<=n;i++)if(V[i]<V[p1])p1=i;
	dfs(p1,0);
	scanf("%d",&q);
	V[0]=-100000000000000ll;
	for(int i=1;i<=q;i++){
		scanf("%lld",&l);
		for(int i=0;i<=n;i++)add[i]=0;
		for(int i=1;i<=n;i++){
			int tem=i;
			for(int j=20;~j;--j)
				if(V[i]-V[fa[tem][j]]<=l)tem=fa[tem][j];
//			printf("%d %d\n",i,tem);
			++add[i],--add[fa[tem][0]];
		}
		getval(p1,0);
//		for(int i=1;i<=n;i++)printf("%d ",add[i]);putchar('\n');
		int ans=0;
		for(int i=1;i<=n;i++)ans=std::max(ans,add[i]);
		printf("%d\n",ans);
	}
}