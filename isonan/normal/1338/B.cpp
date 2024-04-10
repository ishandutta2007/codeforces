#include <cstdio>

int n,head[100001],nxt[200001],b[200001],k,d[100001],cnt[2];
int v;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs1(int x,int f,int dis=0){
	int ch=0;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f)++ch,dfs1(b[i],x,dis+1);
	if(!ch)++cnt[dis&1];
}
void dfs2(int x,int f){
	int ch=0;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=f){
			dfs2(b[i],x);
			if(d[b[i]]==1)ch=1;
			else ++v;
		}
	if(ch)++v;
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		push(u,v);
		push(v,u);
		++d[u];++d[v];
	}
	int p;
	for(int i=1;i<=n;i++)if(d[i]>1)p=i;
	dfs1(p,0);
	if(cnt[0]==0||cnt[1]==0)printf("1 ");
	else printf("3 ");
	dfs2(p,0);
	printf("%d\n",v);
}