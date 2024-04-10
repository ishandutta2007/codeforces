#include <cstdio>
#include <bitset>
#include <algorithm>

std::bitset<2001>con[2001],set[2001];
int sz[2001],t,n,m,num[2001],tm[2001],ans[2001][2];
bool vis[2001];
bool cmp(int a,int b){return tm[a]<tm[b];}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			con[i].reset(),vis[i]=0;
		for(int i=1;i<=m;i++)set[i].reset(),sz[i]=0;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				int tem;
				scanf("%1d",&tem);
				if(tem)set[i].set(j),++sz[i];
			}
		}
		for(int i=1;i<=n;i++){
			con[i].reset();
			for(int j=1;j<=n;j++)con[i][j]=1;
			for(int j=1;j<=m;j++)
				if(set[j][i]&&sz[j]>=2)con[i]&=set[j];
		}
		bool right=1;
		for(int i=1;i<n;i++){
			int p=-1;
			for(int j=1;j<=n;j++)
				if(!vis[j]&&con[j].count()>1){
					for(int k=1;k<=n;k++)
						if(con[j][k]&&j!=k&&!vis[k]){
							ans[i][0]=j;
							ans[i][1]=k;
							break;
						}
					p=j;
					break;
				}
			if(!~p){
				right=0;
				break;
			}
			vis[p]=1;
			for(int j=1;j<=m;j++)
				if(set[j][p]){
					--sz[j];
					if(sz[j]==1){
						for(int k=1;k<=n;k++)
							if(set[j][k]&&k!=p&&!vis[k]){
								con[k].reset();
								for(int j=1;j<=n;j++)if(!vis[j])con[k].set(j);
								for(int j=1;j<=m;j++)
									if(set[j][k]&&sz[j]>=2)con[k]&=set[j];
							}
					}
				}
			for(int j=1;j<=n;j++)con[j].reset(p);
			for(int j=1;j<=m;j++)set[j].reset(p);
		}
		if(!right)puts("NO");
		else{
			puts("YES");
			for(int i=1;i<n;i++)printf("%d %d\n",ans[i][0],ans[i][1]);
		}
	}
}