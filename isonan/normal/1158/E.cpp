#include <cstdio>
#include <bitset>
#include <vector>
#include <cstdlib>
#include <windows.h>
#include <cassert>

int n,dep[1001],head[1001],nxt[2001],b[2001],k;
int dis[1001][1001],fa[1001];
bool vis[1001],set[1001];
std::bitset<1001>bef,aft,que;
std::vector<int>vec;
void query(std::bitset<1001> &a,int x,std::bitset<1001> &b){
	printf("? ");
	for(int i=1;i<=n;i++)printf("%d ",std::min(((int)a[i])?x:0,n-1));
	putchar('\n');
	fflush(stdout);
	b.reset();
#ifdef ISONAN
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
//			printf("%d %d %d %d\n",i,j,(int)a[j],dis[i][j]);
			if((int)a[i]&&dis[i][j]<=x&&i!=j)b.set(j);
		}
//	for(int i=1;i<=n;i++)printf("%d",(int)b[i]);putchar('\n');
	return;
#endif
	for(int i=1,tem;i<=n;i++){
		scanf("%1d",&tem);
		if(tem)b.set(i);
	}
}
int main(){
#ifdef ISONAN
	n=20;
	srand(GetTickCount());
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=n;
	for(int i=1,u,v;i<n;i++){
//		u=i+1;
//		v=rand()%i+1;
//		printf("%d %d\n",u,v);
		scanf("%d%d",&u,&v);
		dis[u][v]=dis[v][u]=1;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=std::min(dis[i][j],dis[i][k]+dis[k][j]);
#else
	scanf("%d",&n);
#endif
	vis[1]=1;
	for(int i=10;~i;--i){
		for(int bit=0;bit<2;bit++){
			que.reset();
			for(int j=1;j<=n;j++)
				if(vis[j]&&((dep[j]&(1<<(i+1)))!=0)!=bit)que.set(j);
			query(que,1<<i,bef);
			query(que,(1<<i)-1,aft);
			for(int j=1;j<=n;j++)if((!vis[j])&&(((dep[j]&(1<<(i+1)))!=0))!=bit&&(bef[j]^aft[j]))set[j]++;
			for(int j=1;j<=n;j++)if((!vis[j])&&!(dep[j]&(1<<i))&&(aft[j]^((dep[j]&(1<<(i+1)))!=0))!=bit)dep[j]|=1<<i;
		}
		for(int j=1;j<=n;j++){
			if(set[j])vis[j]=1,dep[j]|=1<<i;
			set[j]=0;
		}
//	for(int i=1;i<=n;i++)printf("(%d %d)",vis[i],dep[i]);putchar('\n');
	}
	for(int i=0;i<3;i++){
		for(int j=10;~j;--j){
			que.reset();
			for(int k=1;k<=n;k++)if(dep[k]%3==i&&(k&(1<<j)))que.set(k);
			query(que,1,aft);
			for(int k=1;k<=n;k++)if(dep[k]%3==(i+1)%3&&aft[k])fa[k]+=1<<j;
		}
	}
	printf("!\n");
	for(int k=2;k<=n;k++)printf("%d %d\n",k,fa[k]),assert(fa[k]);
	fflush(stdout);
}