#include <cstdio>
#include <bitset>
#include <cstring>

std::bitset<1001>neigh[1001],tem,con[1001];
int n,head[1001],nxt[2001],b[2001],k,cnt,edg[1001][2],top;
bool vis[1001];
void push(int s,int t){
	if(con[s][t])return;
	++cnt;
	con[s][t]=con[t][s]=vis[s]=vis[t]=1;
	++top;
	edg[top][0]=s,edg[top][1]=t;
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
}
int main(){
	scanf("%d",&n);
	for(int i=1,k,tem;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
			scanf("%d",&tem),neigh[i].set(tem);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if((tem=neigh[i]&neigh[j]).count()==2)
				push(tem._Find_first(),tem._Find_next(tem._Find_first()));
	if(!cnt){for(int i=2;i<=n;i++)printf("1 %d\n",i);return 0;}
	if(cnt==1){
		for(int i=1;i<=n;i++)
			if(!vis[i]){
				tem.set();
				for(int j=1;j<=n;j++)
					if(neigh[j][i])tem&=neigh[j];
				for(int j=1;j<=n;j++)if(!vis[j]&&tem[j])printf("%d %d\n",edg[1][0],j);
				for(int j=1;j<=n;j++)if(!vis[j]&&!tem[j])printf("%d %d\n",edg[1][1],j);
				printf("%d %d\n",edg[1][0],edg[1][1]);
				return 0;
			}
	}
	for(int i=1;i<=n;i++)con[i].set(i);
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			tem.reset();
			for(int j=1;j<=n;j++)if(vis[j])tem[j]=1;
			for(int j=1;j<=n;j++)
				if(neigh[j][i])tem&=neigh[j];
			for(int j=1;j<=n;j++)
				if(vis[j]&&tem==con[j]){
					printf("%d %d\n",i,j);
					break;
				}
		}
	for(int i=1;i<=top;i++)printf("%d %d\n",edg[i][0],edg[i][1]);
}