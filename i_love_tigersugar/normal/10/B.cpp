#include<bits/stdc++.h>
#define MAX   111
const int INF=(int)1e9;
int n,k,xc,yc;
int dis[MAX][MAX];
int use[MAX][MAX];
int tot[MAX][MAX];
int iabs(const int &x) {
	if (x<0) return (-x); else return (x);
}
int mahattan(const int &x,const int &y) {
	return (iabs(x-xc)+iabs(y-yc));
}
void init(void) {
	scanf("%d",&n);
	scanf("%d",&k);
	int i,j;
	xc=(k+1)/2;
	yc=(k+1)/2;
	for (i=1;i<=k;i=i+1) {
		tot[i][0]=0;		
		dis[i][0]=0;
		for (j=1;j<=k;j=j+1) {
			use[i][j]=0;
			tot[i][j]=0;
			dis[i][j]=dis[i][j-1]+mahattan(i,j);
		}
	}
}
void choose(const int &m) {
	int minv=INF;
	int i,j,x,y;
	for (i=1;i<=k;i=i+1)
		for (j=1;j+m-1<=k;j=j+1)
			if (tot[i][j+m-1]==tot[i][j-1] && (dis[i][j+m-1]-dis[i][j-1]<minv)) {
				x=i;
				y=j;
				minv=dis[i][j+m-1]-dis[i][j-1];
			}
	if (minv>=INF) {
		printf("-1\n");
		return;
	}
	printf("%d %d %d\n",x,y,y+m-1);
	for (i=y;i<=y+m-1;i=i+1) use[x][i]=1;
	for (i=1;i<=k;i=i+1) tot[x][i]=tot[x][i-1]+use[x][i];
	/*for (i=1;i<=k;i=i+1) {
		for (j=1;j<=k;j=j+1) printf("%d ",tot[i][j]);
		printf("\n");
	}*/
}
void process(void) {
	int i,m;
	for (i=1;i<=n;i=i+1) {
		scanf("%d",&m);
		choose(m);
	}
}
int main(void) {
	init();
	process();
	return 0;
}