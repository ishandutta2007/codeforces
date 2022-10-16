#include<cstdio>
#include<queue>
#define MAX   1010
#define x   first
#define y   second
using namespace std;
typedef pair<int,int> ii;
queue<ii> q;
char a[MAX][MAX];
int c[MAX][MAX];
int l[MAX][MAX];
int n,m,res;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ii s,e;
void init(void) {
	scanf("%d",&m);
	scanf("%d",&n);
	int i,j;
	for (i=1;i<=m;i=i+1)
		for (j=1;j<=n;j=j+1) {
			c[i][j]=0;
			l[i][j]=1e7;
		}				
	for (i=1;i<=m;i=i+1) {
		scanf("%s",&a[i][1]);
		for (j=1;j<=n;j=j+1) {
			if (a[i][j]=='S') s=ii(i,j);
			if (a[i][j]=='E') e=ii(i,j);
			if (a[i][j]=='T') c[i][j]=1;
		}
	}
	for (i=0;i<=m+1;i=i+1) {
		c[i][0]=1;
		c[i][n+1]=1;
	}
	for (i=0;i<=n+1;i=i+1) {
		c[0][i]=1;
		c[m+1][i]=1;
	}
	res=0;
}
void BFS(void) {
	while (!q.empty()) q.pop();
	int i,px,py;
	ii p;
	q.push(e);
	c[e.x][e.y]=1;
	l[e.x][e.y]=0;
	while (!q.empty()) {
		p=q.front();q.pop();
		px=p.x;py=p.y;
		if ('0'<=a[px][py] && a[px][py]<='9')
			if (l[px][py]<=l[s.x][s.y]) res+=a[px][py]-48;
		for (i=0;i<4;i=i+1)
			if (c[px+dx[i]][py+dy[i]]==0) {
				c[px+dx[i]][py+dy[i]]=1;
				l[px+dx[i]][py+dy[i]]=l[px][py]+1;
				q.push(ii(px+dx[i],py+dy[i]));
			}
	}
	printf("%d",res);
}
int main(void) {	
	init();
	BFS();
	return 0;
}