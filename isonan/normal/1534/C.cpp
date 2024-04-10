#include <cstdio>

int pos[2][400001],f[400001];
int t,n; 
int find(int x){
	return f[x]?f[x]=find(f[x]):x;
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)f[i]=0;
		for(int i=1,v;i<=n;++i)scanf("%d",&v),pos[0][v]=i;
		for(int i=1,v;i<=n;++i)scanf("%d",&v),pos[1][v]=i;
		for(int i=1;i<=n;++i){
			int u=find(pos[0][i]),v=find(pos[1][i]);
			if(u!=v)f[u]=v;
		}
		int ans=1;
		for(int i=1;i<=n;++i)
			if(!f[i])ans=(ans+ans)%1000000007;
		printf("%d\n",ans);
	}
}