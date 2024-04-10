#include<bits/stdc++.h>
#define MAX   69
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define FORE(i,v) for (__typeof((v).rbegin()) i=(v).rbegin();i!=(v).rend();i++)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
int m,n,k;
int d[MAX][MAX];
ii tr[MAX][MAX];
vector<ii> chs;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
void init(void) {
	scanf("%d",&m);
	scanf("%d",&n);
	scanf("%d",&k);
}
bool inside(int x,int y) {
	if (x<1) return (false);
	if (y<1) return (false);
	if (x>m) return (false);
	if (y>n) return (false);
	return (true);
}
void BFS(void) {
	queue<ii> q;
	while (!q.empty()) q.pop();
	q.push(ii(1,1));
	d[1][1]=1;
	chs.push_back(ii(1,1));
	while (!q.empty()) {
		int ux=q.front().fi;
		int uy=q.front().se;
		q.pop();
		REP(i,4) if (inside(ux+dx[i],uy+dy[i])) {
			int vx=ux+dx[i];
			int vy=uy+dy[i];
			if (d[vx][vy]<1) {
				d[vx][vy]=d[ux][uy]+1;
				tr[vx][vy]=ii(ux,uy);
				q.push(ii(vx,vy));
				chs.push_back(ii(vx,vy));
			}
		}
	}
}
void writepath(int x,int y) {
	vector<ii> path;
	for (ii u=ii(x,y);u!=ii(1,1);u=tr[u.fi][u.se]) path.push_back(u);
	path.push_back(ii(1,1));
	FORE(it,path) printf("(%d,%d) ",it->fi,it->se);
	printf("\n");
}
void process(void) {
	int res=0;
	REP(i,k) res+=d[chs[i].fi][chs[i].se];
	printf("%d\n",res);
	FORD(i,k-1,0) writepath(chs[i].fi,chs[i].se);	
}
int main(void) {
	init();
	BFS();
	process();
	return 0;
}