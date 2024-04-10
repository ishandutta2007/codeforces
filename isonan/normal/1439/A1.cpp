#include <cstdio>

int t,n,m,con[20001][6],top;
int map[101][101];
void rev(int x1,int y1,int x2,int y2,int x3,int y3){
	++top;
	con[top][0]=x1;
	con[top][1]=y1;
	con[top][2]=x2;
	con[top][3]=y2;
	con[top][4]=x3;
	con[top][5]=y3;
	map[x1][y1]^=1;
	map[x2][y2]^=1;
	map[x3][y3]^=1;
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d%d",&n,&m); 
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%1d",&map[i][j]);
		top=0;
		for(int i=1;i<n;i++)
			for(int j=1;j<=m;j++){
				if(map[i][j]){
					if(j<m)rev(i,j,i+1,j,i,j+1);
					else rev(i,j,i+1,j,i+1,j-1);
				}
			}
		for(int j=1;j<m;j++)
			if(map[n][j]){
				rev(n-1,j,n,j,n-1,j+1);
				rev(n-1,j,n,j+1,n-1,j+1);
			}
		if(map[n][m]){
			rev(n,m,n-1,m,n-1,m-1);
			rev(n,m-1,n-1,m-1,n,m);
			rev(n,m,n-1,m,n,m-1);
		}
		printf("%d\n",top);
		for(int i=1;i<=top;i++,putchar('\n'))
			for(int j=0;j<6;j++)
				printf("%d ",con[i][j]);
	}
}