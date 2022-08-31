#include <cstdio>
#include <algorithm>

long long Abs(long long x){
	return x<0?-x:x;
}

int t;
int n;
int head[100001],nxt[200001],b[200001],k;
int l[100001],r[100001];
long long f[100001][2];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs(int x,int F){
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=F){
			dfs(b[i],x);
			f[x][0]+=std::max(f[b[i]][1]+Abs(r[b[i]]-l[x]),f[b[i]][0]+Abs(l[b[i]]-l[x]));
			f[x][1]+=std::max(f[b[i]][1]+Abs(r[b[i]]-r[x]),f[b[i]][0]+Abs(l[b[i]]-r[x]));
		}
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d%d",l+i,r+i),head[i]=0;
		k=0;
		for(int i=1;i<=n;++i)f[i][0]=f[i][1]=0;
		for(int i=1,u,v;i<n;++i){
			scanf("%d%d",&u,&v);
			push(u,v);
			push(v,u);
		}
		dfs(1,0);
		printf("%lld\n",std::max(f[1][0],f[1][1]));
	}
}