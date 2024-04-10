#include <cstdio>

int t,n;
bool f[101][101][2];
int main(){
	for(int i=0;i<=100;++i)
		for(int j=0;j<=100;++j)
			for(int k=0;k<2;++k){
				if(i==0&&j==0){
					f[i][j][k]=(k==0);
					continue;
				}
				if(i&&!f[i-1][j][(j^(k^1))&1])f[i][j][k]=1;
				if(j&&!f[i][j-1][(j^(k^1))&1])f[i][j][k]=1;
			}
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		int c[2]={0};
		for(int i=1;i<=n;++i){
			int tem;
			scanf("%d",&tem);
			++c[tem&1];
		}
		if(f[c[0]][c[1]][0])puts("Alice");
		else puts("Bob");
	}
}