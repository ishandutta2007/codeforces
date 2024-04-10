#include <cstring>
#include <cstdio>

int n,m,k;
int v1[501][501],v2[501][501];
int dis[11][501][501];
int q[10000001][3],h,t;
bool inq[11][501][501];
void add(int len,int i,int j,int d){
	if(dis[len][i][j]>d){
		dis[len][i][j]=d;
		if(!inq[len][i][j]){
			inq[len][i][j]=1;
			++t;
			q[t][0]=len;
			q[t][1]=i;
			q[t][2]=j;
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	if(k&1){
		for(int i=1;i<=n;++i,putchar('\n'))
			for(int j=1;j<=m;++j)
				printf("-1 ");
		return 0;
	}
	k>>=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<m;++j)
			scanf("%d",&v1[i][j]);
	for(int i=1;i<n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&v2[i][j]);
	memset(dis,0x7f7f7f7f,sizeof dis);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			add(0,i,j,0);
	while(h<t){
		++h;
		int l=q[h][0],x=q[h][1],y=q[h][2],Len=dis[l][x][y];
		inq[l][x][y]=0;
		if(l==k)continue;
		if(x>1)add(l+1,x-1,y,Len+v2[x-1][y]);
		if(x<n)add(l+1,x+1,y,Len+v2[x][y]);
		if(y>1)add(l+1,x,y-1,Len+v1[x][y-1]);
		if(y<m)add(l+1,x,y+1,Len+v1[x][y]);
	}
	for(int i=1;i<=n;++i,putchar('\n'))
		for(int j=1;j<=m;++j)
			printf("%d ",dis[k][i][j]<<1);
}