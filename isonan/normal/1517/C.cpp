#include <cstdio>

int n,p[501],ans[501][501];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",p+i);
		int x=i,y=i;
		for(int j=1;j<=p[i];++j){
			ans[x][y]=p[i];
			if(y>1&&!ans[x][y-1])--y;
			else ++x;
		}
	}
	for(int i=1;i<=n;++i,putchar('\n'))
		for(int j=1;j<=i;++j)
			printf("%d ",ans[i][j]);
}