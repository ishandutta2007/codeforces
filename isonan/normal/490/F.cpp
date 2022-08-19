#include <cstdio>
#include <algorithm>

int max(int a,int b){return a>b?a:b;}
short f[6001][6001],g[6001][6001];
int orig[6001],r[6001],n,head[6001],nxt[12001],b[12001],k,lim,ans;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
void dfs(int x,int F){
	for(int i=r[x];i<=lim;i++)f[x][i]=1;
	for(int i=1;i<=r[x];i++)g[x][i]=1;
	for(int i=head[x];i;i=nxt[i])
		if(b[i]!=F){
			dfs(b[i],x);
			for(int j=2;j<=lim;j++)ans=max(ans,max(f[x][j-1]+g[b[i]][j],g[x][j]+f[b[i]][j-1]));
			for(int j=r[x];j<=lim;j++)f[x][j]=max(f[x][j],f[b[i]][r[x]-1]+1);
			for(int j=1;j<=r[x];j++)g[x][j]=max(g[x][j],g[b[i]][r[x]+1]+1);
			for(int j=1;j<=lim;j++)f[x][j]=max(f[x][j],f[b[i]][j]),g[x][j]=max(g[x][j],g[b[i]][j]);
		}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",r+i),orig[i]=r[i];
	std::sort(orig+1,orig+n+1);
	lim=std::unique(orig+1,orig+n+1)-orig-1;
	for(int i=1;i<=n;i++)r[i]=std::lower_bound(orig+1,orig+lim+1,r[i])-orig;
	for(int i=1,s,t;i<n;i++){
		scanf("%d%d",&s,&t);
		push(s,t);
		push(t,s);
	}
	dfs(1,0);
	printf("%d",ans);
}