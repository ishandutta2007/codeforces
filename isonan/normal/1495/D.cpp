#include <cstdio>
#include <cstring>
#include <algorithm>

int n,m,dis[401][401];
int ans[401][401];
bool vis[401][401];
int head[401],nxt[100001],b[100001],k;
void push(int s,int t){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int main(){
	scanf("%d%d",&n,&m);
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;++i)dis[i][i]=0;
	for(int i=1,u,v;i<=m;++i)scanf("%d%d",&u,&v),dis[u][v]=dis[v][u]=1,push(u,v),push(v,u);
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				dis[i][j]=std::min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j){
//			printf("%d %d %d\n",i,j,dis[i][j]);
			int x=0;
			for(int k=1;k<=n;++k)if(dis[i][k]+dis[k][j]==dis[i][j])++x;
			if(x!=dis[i][j]+1)ans[i][j]=ans[j][i]=0;
			else{
				int tem=1;
				for(int k=1;k<=n;++k)
					if(dis[i][k]+dis[k][j]>dis[i][j]){
						int v=0;
						for(int l=head[k];l;l=nxt[l])
							if(dis[i][b[l]]==dis[i][k]-1&&dis[j][b[l]]==dis[j][k]-1)
								++v;
						tem=1ll*tem*v%998244353;
					}
				ans[i][j]=ans[j][i]=tem;
			}
		}
	for(int i=1;i<=n;++i,putchar('\n'))
		for(int j=1;j<=n;++j)
		printf("%d ",ans[i][j]);
}