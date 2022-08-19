#include <cstdio>

int n,m;
int c[601][601];
long long dis[601];
bool vis[601];
void update(int x,long long d){
//	printf("update %d %lld\n",x,d);
	if(!vis[x]&&dis[x]>d)dis[x]=d;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,a,b,c;i<=m;++i){
		scanf("%d%d%d",&a,&b,&c);
		::c[a][b]=c;
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j)dis[j]=1e18,vis[j]=0;
		for(int j=0;j<n;++j)
			if(c[i][j])
				update(j,c[i][j]);
		for(int j=0;j<n;++j){
			int p=-1;
			for(int k=0;k<n;++k)
				if(!vis[k]&&((p==-1)||dis[p]>dis[k]))p=k;
			vis[p]=1;
//			printf("%d %lld\n",p,dis[p]);
			update((p+1)%n,dis[p]+1);
			for(int l=0;l<n;++l)
				if(c[p][l]){
					update((dis[p]+l)%n,dis[p]+c[p][l]);
				}
		}
		for(int j=0;j<n;++j)printf("%lld ",(i==j)?0:dis[j]);putchar('\n');
	}
}