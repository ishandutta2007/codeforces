#include <cstdio>
#include <algorithm>

int f[51][51][51][51];
int n;
int mat[51][51];
char get(){
	char ch=getchar();
	while(ch!='.'&&ch!='#')ch=getchar();
	return (ch=='#');
}
int getmat(int x2,int y2,int x1,int y1){
	return mat[x2][y2]-mat[x1-1][y2]-mat[x2][y1-1]+mat[x1-1][y1-1];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			mat[i][j]=get()+mat[i][j-1]+mat[i-1][j]-mat[i-1][j-1];
	for(int x=1;x<=n;x++)
		for(int y=1;y<=n;y++)
			for(int i=1;i+x-1<=n;i++)
				for(int j=1;j+y-1<=n;j++){
					if(!getmat(i+x-1,j+y-1,i,j)){
						continue;
					}
					f[i][j][i+x-1][j+y-1]=std::max(x,y);
					for(int k=i;k<i+x-1;k++)f[i][j][i+x-1][j+y-1]=std::min(f[i][j][i+x-1][j+y-1],f[i][j][k][j+y-1]+f[k+1][j][i+x-1][j+y-1]);
					for(int k=j;k<j+y-1;k++)f[i][j][i+x-1][j+y-1]=std::min(f[i][j][i+x-1][j+y-1],f[i][j][i+x-1][k]+f[i][k+1][i+x-1][j+y-1]);
				}
	printf("%d",f[1][1][n][n]);
}