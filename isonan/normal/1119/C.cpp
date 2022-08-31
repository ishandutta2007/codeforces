#include <cstdio>

int mat1[501][501],mat2[501][501];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&mat1[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&mat2[i][j]);
	for(int i=1;i<=n;i++){
		int tem=0;
		for(int j=1;j<=m;j++)tem^=mat1[i][j];
		for(int j=1;j<=m;j++)tem^=mat2[i][j];
		if(tem){
			puts("No");
			return 0;
		}
	}
	for(int i=1;i<=m;i++){
		int tem=0;
		for(int j=1;j<=n;j++)tem^=mat1[j][i];
		for(int j=1;j<=n;j++)tem^=mat2[j][i];
		if(tem){
			puts("No");
			return 0;
		}
	}
	puts("Yes");
}