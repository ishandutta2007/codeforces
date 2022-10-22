#include<cstdio>
int dp[2][5000][5001];
int tmp[2][5001];
int n,b,c[5000],d[5000];
int head[5000],nxt[5000],to[5000],tot;
int sz[5000];
void add(int u,int v){
	nxt[tot]=head[u],head[u]=tot;
	to[tot]=v,++tot;
}
void chkmin(int &x,int y){if(y<x)x=y;}
void dfs(int u){
	dp[0][u][0]=0;dp[1][u][0]=0x3f3f3f3f;
	dp[0][u][1]=c[u];dp[1][u][1]=c[u]-d[u];
	sz[u]=1;
	for(int e=head[u];~e;e=nxt[e]){
		int v=to[e];
		dfs(v);
		for(int k=0;k<2;++k)for(int i=0;i<=sz[u]+sz[v];++i)
			tmp[k][i]=0x3f3f3f3f;
		for(int i=0;i<=sz[u];++i){
			for(int j=0;j<=sz[v]&&i+j<=sz[u]+sz[v];++j){
				for(int k=0;k<2;++k){
					chkmin(tmp[k][i+j],dp[k][u][i]+dp[k][v][j]);
				}
			}
		}
		sz[u]+=sz[v];
		for(int k=0;k<2;++k)for(int i=0;i<=sz[u];++i)dp[k][u][i]=tmp[k][i];
	}
	for(int i=0;i<=sz[u];++i)chkmin(dp[1][u][i],dp[0][u][i]);
}
int main(){
	scanf("%d%d",&n,&b);
	for(int i=0;i<n;++i)head[i]=~0;
	for(int i=0;i<n;++i){
		scanf("%d%d",c+i,d+i);
		if(i){
			int fa;scanf("%d",&fa);
			--fa;add(fa,i);
		}
	}
	dfs(0);
	int ans=0;
	for(int j=1;j<=n;++j){
		if(dp[1][0][j]<=b)ans=j;
	}
	printf("%d\n",ans);
	return 0;
}