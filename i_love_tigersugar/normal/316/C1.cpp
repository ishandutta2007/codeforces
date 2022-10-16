#include<cstdio>
#include<queue>
#include<cstring>
#define MAX   3232
using namespace std;
const int INF=(int)1e6;
int a[88][88];
int id[88][88];
int c[MAX][MAX];
int fx[MAX],fy[MAX],matx[MAX],maty[MAX],t[MAX],d[MAX],argu[MAX];
int sta,fin;
int m,n,k;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
queue<int> q;
void minimize(int &x,const int &y) {
	if (x>y) x=y;
}
void init(void) {
	scanf("%d",&m);
	scanf("%d",&n);
	int i,j;
	for (i=1;i<=m;i=i+1)
		for (j=1;j<=n;j=j+1)
			scanf("%d",&a[i][j]);
	for (i=0;i<=m+1;i=i+1) {
		a[i][0]=-1;
		a[i][n+1]=-1;
	}
	for (i=0;i<=n+1;i=i+1) {
		a[0][i]=-1;
		a[m+1][i]=-1;
	}
}
void loadgraph(void) {
	int nb=0;
	int nw=0;
	int i,j,d;
	for (i=1;i<=m;i=i+1)
		for (j=1;j<=n;j=j+1) {
			if ((i+j)%2==0) {
				nb++;
				id[i][j]=nb;
			}
			if ((i+j)%2==1) {
				nw++;
				id[i][j]=nw;
			}
		}
	k=(m*n)/2;
	for (i=1;i<=k;i=i+1)
		for (j=1;j<=k;j=j+1)
			c[i][j]=INF;
	for (i=1;i<=m;i=i+1)
		for (j=1;j<=n;j=j+1)
			if ((i+j)%2==0)
				for (d=0;d<4;d=d+1)
					if (a[i+dx[d]][j+dy[d]]>0)
						c[id[i][j]][id[i+dx[d]][j+dy[d]]]=1-(a[i][j]==a[i+dx[d]][j+dy[d]]);
	memset(matx,0,sizeof matx);
	memset(maty,0,sizeof maty);
	/*for (i=1;i<=k;i=i+1)
		for (j=1;j<=k;j=j+1)
			if (c[i][j]<INF) printf("c(%d,%d)=%d\n",i,j,c[i][j]);*/
	for (i=1;i<=k;i=i+1) {
		fx[i]=INF;
		for (j=1;j<=k;j=j+1) minimize(fx[i],c[i][j]);
	}
	for (j=1;j<=k;j=j+1) {
		fy[j]=INF;
		for (i=1;i<=k;i=i+1) minimize(fy[j],c[i][j]-fx[i]);
	}
}
int cost(const int &x,const int &y) {
	return (c[x][y]-fx[x]-fy[y]);
}
void initBFS(void) {
	int j;
	while (!q.empty()) q.pop();
	q.push(sta);
	memset(t,0,sizeof t);
	for (j=1;j<=k;j=j+1) {
		d[j]=cost(sta,j);
		argu[j]=sta;
	}
	fin=0;
}
void findway(void) {
	int i,j,w;
	while (!q.empty()) {
		i=q.front();q.pop();
		for (j=1;j<=k;j=j+1)
			if (t[j]==0) {
				w=cost(i,j);
				if (w==0) {
					t[j]=i;
					if (maty[j]==0) {
						fin=j;
						return;
					}
					else q.push(maty[j]);					
				}
				if (d[j]>w) {
					d[j]=w;
					argu[j]=i;
				}
			}
	}
}
void subx_addy(void) {
	int i,j,delta;
	delta=INF;
	for (j=1;j<=k;j=j+1)
		if (t[j]==0) minimize(delta,d[j]);
	fx[sta]+=delta;
	for (j=1;j<=k;j=j+1) {
		if (t[j]!=0) {
			i=maty[j];
			fx[i]+=delta;
			fy[j]-=delta;
		}
		else d[j]-=delta;
	}
	for (j=1;j<=k;j=j+1)
		if (t[j]==0 && d[j]==0) {
			t[j]=argu[j];
			if (maty[j]==0) {
				fin=j;
				return;
			}
			else q.push(maty[j]);
		}
}
void enlarge(void) {
	int next,cur;
	cur=fin;
	do {
		next=matx[t[cur]];
		matx[t[cur]]=cur;
		maty[cur]=t[cur];
		cur=next;
	}
	while (cur>0);
}
void maxmatching(void) {
	int i;
	for (i=1;i<=k;i=i+1) {
		sta=i;
		initBFS();
		do {
			findway();
			if (fin==0) subx_addy();
		}
		while (fin==0);
		enlarge();
	}
	int res=0;
	for (i=1;i<=k;i=i+1)
		if (matx[i]>0 && c[i][matx[i]]<INF) res+=c[i][matx[i]];
	printf("%d",res);
}
int main(void) {
	init();
	loadgraph();
	maxmatching();
	return 0;
}