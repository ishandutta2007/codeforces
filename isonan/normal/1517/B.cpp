#include <cstdio>
#include <algorithm>

int T,b[101][101];
int ans[101][101];
int n,m;
int main(){
	scanf("%d",&T);
	for(int fd=1;fd<=T;++fd){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				scanf("%d",&b[i][j]);
		for(int i=1;i<=n;++i){
			std::sort(b[i]+1,b[i]+m+1);
		}
		for(int i=1;i<=m;++i){
			int p=0;
			for(int j=1;j<=n;++j)
				if(!p||b[p][1]>b[j][1])p=j;
			for(int j=1;j<=n;++j){
				if(p==j)::ans[i][j]=b[p][1];
				else ans[i][j]=b[j][m-i+1];
			}
			for(int j=1;j<m;++j)b[p][j]=b[p][j+1];
		}
		for(int i=1;i<=n;++i,putchar('\n'))
			for(int j=1;j<=m;++j)
				printf("%d ",ans[j][i]);
//		printf("%lld\n",ans);
	}
}