#include <cstdio>
#include <cstring>
#include <algorithm>
#pragma GCC optimize("unroll-loops")

int n,k,p[200001][10],head[1001],nxt[2001],b[2001],v[2001],K,q[2001],cnt;
int f[1001];
long long ans;
void push(int s,int t,int val){
	nxt[++K]=head[s];
	head[s]=K;
	b[K]=t;
	v[K]=val;
}
void dfs(int x,int f,int r){
	ans+=n-r+1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)dfs(b[i],x,(r>v[i])?r:v[i]);
}
struct edge{
	int u,v,w;
};
struct graph{
	edge num[1001];
	int size;
};
int find(int x){return f[x]?f[x]=find(f[x]):x;}
edge num[2001];
graph merge(graph a,graph b,int l){
	return a;
}
int vec[1001];
int ord[100001],Q[100001][11];
int main(){
	int num[11];
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k;j++)
			scanf("%d",&p[i][j]);
	graph a;
	a.size=0;
	for(int i=1;i<=k;i++)num[i]=i;
	cnt=1;
	do{
		int tem=0;
		for(int i=1;i<=k;i++)tem=tem*10+num[i];
		for(int i=1;i<=k;i++)Q[cnt][i]=num[i];
		ord[tem]=cnt;
		++cnt;
	}while(std::next_permutation(num+1,num+k+1));
	graph b;
	b.size=cnt;
	for(int i=n;i;--i){
		for(int l=1;l<=cnt;l++){
			int tem1=0,tem2=0;
			for(int j=1;j<=k;++j)tem1=tem1*10+Q[l][j],tem2=tem2*10+Q[l][p[i][j]];
			b.num[l]=(edge){ord[tem1],ord[tem2],i};
		}
		for(int i=1;i<=b.size;++i)::num[i]=b.num[i];
		for(int i=1;i<=a.size;++i)::num[i+cnt]=a.num[i];
		memset(f,0,(cnt+1)<<2);
		memset(head,0,(cnt+1)<<2);
		K=0;
		int size=a.size+b.size;
		a.size=0;
		for(int i=1;i<=size;++i){
			int u=find(::num[i].u),v=find(::num[i].v);
			if(u==v)continue;
			else{
				f[u]=v;
				a.num[++a.size]=::num[i];
				push(::num[i].u,::num[i].v,::num[i].w);
				push(::num[i].v,::num[i].u,::num[i].w);
			}
		}
		dfs(1,0,i);
	}
	printf("%I64d\n",ans);
}