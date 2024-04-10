#include<cstdio>
#include<vector>
#define MAX   555
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
vector<int> g[MAX*MAX];
bool vst[MAX*MAX];
char a[MAX][MAX];
int id[MAX][MAX];
ii pos[MAX*MAX];
int n,m,k;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
void minimize(int &x,const int &y) {
	if (x>y) x=y;
}
void readinp(void) {
	scanf("%d",&m);
	scanf("%d",&n);
	scanf("%d",&k);
	FOR(i,1,m) scanf("%s",a[i]+1);
	int cnt=0;
	FOR(i,1,m) FOR(j,1,n) {
		cnt++;
		id[i][j]=cnt;
		pos[cnt]=ii(i,j);
	}
}
bool inside(int x,int y) {
	if (x<1) return (false);
	if (y<1) return (false);
	if (x>m) return (false);
	if (y>n) return (false);
	return (true);
}
void loadgraph(void) {
	FOR(i,1,m) FOR(j,1,n) if (a[i][j]=='.')
		REP(d,4) if (inside(i+dx[d],j+dy[d]) && a[i+dx[d]][j+dy[d]]=='.')
			g[id[i][j]].push_back(id[i+dx[d]][j+dy[d]]);
}
void visit(int u) {	
	FORE(it,g[u]) if (!vst[*it]) {
		vst[*it]=true;
		visit(*it);
	}
	if (k>0) {
		k--;
		a[pos[u].fi][pos[u].se]='X';
	}
}
void process(void) {
	FOR(i,1,m) FOR(j,1,n) if (a[i][j]=='.') visit(id[i][j]);
	FOR(i,1,m) {
		FOR(j,1,n) printf("%c",a[i][j]);
		printf("\n");
	}
}
int main(void) {
	readinp();
	loadgraph();
	process();
	return 0;
}