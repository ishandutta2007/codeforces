#include <cstdio>

int map[101][101],n,tem;
bool vis[101][101];
int query(int x1,int y1,int x2,int y2){
	printf("? %d %d %d %d\n",x1,y1,x2,y2);
	fflush(stdout);
	scanf("%d",&tem);
	return tem;
}
void get(int x,int y){
	if(x>2)map[x][y]=query(x-2,y,x,y)^map[x-2][y]^1;
	else if(y>2)map[x][y]=query(x,y-2,x,y)^map[x][y-2]^1;
	else if(x>1&&y>1)map[x][y]=query(x-1,y-1,x,y)^map[x-1][y-1]^1;
	else if(x>1)map[x][y]=query(x-1,y+1,x,y)^map[x-1][y+1]^1;
}
int main(){
	scanf("%d",&n);
	map[1][1]=1,map[n][n]=0;
	vis[1][1]=vis[n][n]=vis[1][2]=vis[3][2]=vis[2][1]=1;
	map[3][2]=query(1,2,3,2)^1;
	map[2][1]=query(2,1,3,2)^map[3][2]^1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(!vis[i][j])vis[i][j]=1,get(i,j);
	for(int i=2;i<=n;i++)
		for(int j=1;j<n;j++)
			if(map[i][j]!=map[i-1][j+1]){
				int tem;
				if(i<n)tem=query(i-1,j,i+1,j+1)^map[i-1][j]^map[i+1][j+1]^1;
				else tem=query(i-2,j,i,j+1)^map[i-2][j]^map[i][j+1]^1;
				for(int k=1;k<=n;k++)
					for(int l=(k&1)?2:1;l<=n;l+=2)
						map[k][l]^=tem;
				printf("!\n");
				for(int k=1;k<=n;k++,putchar('\n'))
					for(int l=1;l<=n;l++)
						printf("%d",map[k][l]);
				fflush(stdout);
				return 0;
			}
	for(int i=3;i<=n;i++)
		for(int j=1;j<n;j++)
			if((map[i-2][j]^map[i-1][j]^map[i][j]^map[i][j+1])==0){
				int tem=query(i-2,j,i,j+1)^map[i-2][j]^map[i][j+1]^1;
				for(int k=1;k<=n;k++)
					for(int l=(k&1)?2:1;l<=n;l+=2)
						map[k][l]^=tem;
				printf("!\n");
				for(int k=1;k<=n;k++,putchar('\n'))
					for(int l=1;l<=n;l++)
						printf("%d",map[k][l]);
				fflush(stdout);
				return 0;
			}
}