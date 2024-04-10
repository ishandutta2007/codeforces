#include <cstdio>

int t,n,m,map[310][310],ans[310][310];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&map[i][j]),ans[i][j]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				++ans[i-1][j];
				++ans[i][j-1];
				++ans[i+1][j];
				++ans[i][j+1];
			}
			bool cando=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(map[i][j]>ans[i][j])cando=0;
		if(!cando)puts("NO");
		else{
			puts("YES");
			for(int i=1;i<=n;i++,putchar('\n'))
				for(int j=1;j<=m;j++)
					printf("%d ",ans[i][j]);
		}
	} 
}