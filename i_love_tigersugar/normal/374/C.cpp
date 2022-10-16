#include<cassert>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<stack>
#include<vector>
#define MAX   1000100
#define MAXN   1010
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
const char name[]="DIMA";
const char none[]="Poor Dima!";
const char infi[]="Poor Inna!";
int m,n,cnt;
vector<int> g[MAX];
char a[MAXN][MAXN];
int id[MAXN][MAXN];
bool fre[MAX];
int low[MAX];
int num[MAX];
int f[MAX];
int dx[]={0,-1,1,0};
int dy[]={1,0,0,-1};
stack<int> st;
void minimize(int &x,const int &y) {
	if (x>y) x=y;
}
void maximize(int &x,const int &y) {
	if (x<y) x=y;
}
void init(void) {
	scanf("%d",&m);
	scanf("%d",&n);
	int cnt=0;
	FOR(i,1,m) {
		scanf("%s",a[i]+1);
		FOR(j,1,n) {
			cnt++;
			id[i][j]=cnt;
		}
	}
}
bool inside(int x,int y) {
	if (x<1) return (false);
	if (y<1) return (false);
	if (x>m) return (false);
	if (y>n) return (false);
	return (true);
}
bool canmove(int x,int y,int d) {
	int tx=x+dx[d];
	int ty=y+dy[d];
	if (!inside(tx,ty)) return (false);
	REP(k,4) if (a[x][y]==name[k] && a[tx][ty]==name[(k+1)%4]) return (true);
	return (false);
}
void loadgraph(void) {
	FOR(i,1,m) FOR(j,1,n) REP(k,4) 
		if (canmove(i,j,k)) {
			int tx=i+dx[k];
			int ty=j+dy[k];
			g[id[i][j]].push_back(id[tx][ty]);
		}
	FOR(i,1,m*n) fre[i]=true;
}
void visit(int u) {
	cnt++;
	low[u]=cnt;
	num[u]=cnt;
	st.push(u);
	FORE(it,g[u]) if (fre[*it]){
		int v=*it;
		if (num[v]==0) {
			visit(v);
			minimize(low[u],low[v]);
		}
		else minimize(low[u],num[v]);
	}
	if (low[u]==num[u]) {
		int v;
		int sz=0;
		do {
			v=st.top();st.pop();
			fre[v]=false;
			sz++;
			if (sz>1) {
				printf("%s",infi);
				exit(0);
			}
		}
		while (v!=u);
	}
}
void tarjan(void) {
	FOR(i,1,m*n) if (num[i]==0) visit(i);
	memset(f,-1,sizeof f);
}
int dp(int u) {
	if (f[u]>=0) return (f[u]);	
	int &res=f[u];
	res=0;
	FORE(it,g[u]) if (dp(*it)>0) maximize(res,dp(*it)+1);
	if (a[(u-1)/n+1][(u-1)%n+1]=='A') maximize(res,1);
	return (res);
}
void process(void) {
	int res=0;
	FOR(i,1,m) FOR(j,1,n) if (a[i][j]=='D') maximize(res,dp(id[i][j]));
	assert(res%4==0);
	if (res<=0) printf("%s",none);
	else printf("%d",res>>2);
}
int main(void) {
	init();
	loadgraph();
	tarjan();
	process();
	return 0;
}