#include <cstdio>
#include <algorithm>
#define int long long

int q,n,K,head[500001],nxt[1000001],b[1000001],k,f[500001][2];
long long tem[500001],top;
long long v[1000001];
void push(int s,int t,long long val){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	v[k]=val;
}
void dfs(int x,int F){
	long long sum=0;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=F){
			dfs(b[i],x);
			sum+=std::max(1ll*f[b[i]][0],f[b[i]][1]+v[i]);
		}
	top=0;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=F){
			tem[++top]=f[b[i]][0]-std::max(1ll*f[b[i]][0],f[b[i]][1]+v[i]);
		}
	std::sort(tem+1,tem+top+1);
	if(top<K){
		f[x][0]=f[x][1]=sum;
	}
	else{
		f[x][1]=f[x][0]=sum;
		for(int i=top;i>K;i--)f[x][0]+=tem[i];
		for(int i=top;i>=K;i--)f[x][1]+=tem[i];
	}
}
signed main(){
	scanf("%I64d",&q);
	for(int fd=1;fd<=q;fd++){
		scanf("%I64d%I64d",&n,&K);
		for(int i=1;i<=n;i++)head[i]=0;
		k=0;
		for(int i=1;i<n;i++){
			int u,v;
			long long w;
			scanf("%I64d%I64d%I64d",&u,&v,&w);
			push(u,v,w);
			push(v,u,w);
		}
		dfs(1,0);
		printf("%I64d\n",f[1][0]);
	}
}