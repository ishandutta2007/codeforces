#include<cstdio>
#include<cstring>
#include<queue>
#define fi   first
#define se   second
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typedef((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,ii> pii;
const int n=8;
char a[13][13];
bool vst[13][13][13][13];
ii s[43];
int dx[]={2,-2,2,-2};
int dy[]={2,-2,-2,2};
void init(void) {
	FOR(i,1,n) scanf("%s",a[i]+1);
	memset(vst,false,sizeof vst);
}
bool inside(const int &x,const int &y) {
	if (x<1) return (false);
	if (y<1) return (false);
	if (x>n) return (false);
	if (y>n) return (false);
	return (true);
}
void BFS(void) {
	queue<pii> q;
	while (!q.empty()) q.pop();
	q.push(pii(s[1],s[2]));
	vst[s[1].fi][s[1].se][s[2].fi][s[2].se]=true;
	int px1,py1,px2,py2;
	int vx1,vy1,vx2,vy2;
	while (!q.empty()) {
		px1=q.front().fi.fi;
		py1=q.front().fi.se;
		px2=q.front().se.fi;
		py2=q.front().se.se;
		q.pop();
		if (px1==px2 && py1==py2) {
			printf("YES\n");
			return;
		}
		REP(i,4) REP(j,4) {
			vx1=px1+dx[i];
			vy1=py1+dy[i];
			vx2=px2+dx[j];
			vy2=py2+dy[j];
			if (inside(vx1,vy1) && inside(vx2,vy2) && (!vst[vx1][vy1][vx2][vy2])) {
				vst[vx1][vy1][vx2][vy2]=true;
				q.push(pii(ii(vx1,vy1),ii(vx2,vy2)));
			}
		}
	}
	printf("NO\n");
}
void process(void) {
	int cnt=0;
	FOR(i,1,n) FOR(j,1,n) if (a[i][j]=='K') {
		cnt++;
		s[cnt]=ii(i,j);
	}
	BFS();	
}
int main(void) {
#ifndef ONLINE_JUDGE
	freopen("tmp.txt","r",stdin);
#endif
	int t;
	scanf("%d",&t);
	REP(i,t) {
		init();
		process();
	}
	return 0;
}