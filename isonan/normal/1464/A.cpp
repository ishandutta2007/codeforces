#include <cstdio>
#include <cstring>

int t;
int n,m,f[100001],con[100001][2],g[100001][2];
int find(int x){
	return f[x]?f[x]=find(f[x]):x; 
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)f[i]=g[i][0]=g[i][1]=0;
		for(int i=1,u,v;i<=m;i++){
			scanf("%d%d",&con[i][0],&con[i][1]);
			u=find(con[i][0]),v=find(con[i][1]);
			if(u!=v){
				f[u]=v;
			}
		}
		int ans=m;
		for(int i=1;i<=n;i++){
			++g[find(i)][0];
		}
		for(int i=1;i<=m;i++)++g[find(con[i][0])][1];
//		printf("%d\n",n);
		for(int i=1;i<=n;i++){
//			printf("%d %d %d\n",f[i],g[i][0],g[i][1]);
			if(!f[i]&&g[i][0]==g[i][1]&&g[i][0]>1)++ans;
			if(!f[i]&&g[i][0]==g[i][1]&&g[i][0]==1)--ans;
		}
		printf("%d\n",ans);
	}
}