#include <cstdio>

int n,k,con[100001][2],head[100001],nxt[200001],b[200001],K,size;
bool vis[100001];
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs(int x){
	if(vis[x])return;
	vis[x]=1;
	++size;
	for(int i=head[x];i;i=nxt[i])
		dfs(b[i]);
}
int main(){
	scanf("%d%d",&n,&K);
	for(int i=1;i<=K;i++)scanf("%d%d",&con[i][0],&con[i][1]),push(con[i][0],con[i][1]),push(con[i][1],con[i][0]);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			size=0;
			dfs(i);
			ans+=size-1;
		}
	}
	printf("%d\n",K-ans);
}