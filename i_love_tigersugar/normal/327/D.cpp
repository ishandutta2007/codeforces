#include<bits/stdc++.h>
#define MAX   505
#define fi   first
#define se   second
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
typedef pair<int,int> ii;
char a[MAX][MAX];
bool vst[MAX][MAX];
vector<ii> ch[MAX][MAX];
struct oper {
	char type;
	int x,y;
	oper(){}
	oper(const int &t,const int &_x,const int &_y) {
		type=t;x=_x;y=_y;
	}
	void print(void) const {
		printf("%c %d %d\n",type,x,y);
	}
};
vector<oper> res;
int m,n;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
void add_oper(const oper &x) {
	res.push_back(x);
}
bool canbuild(const int &x,const int &y) {
	if (x<1) return (false);
	if (y<1) return (false);
	if (x>m) return (false);
	if (y>n) return (false);
	return (a[x][y]=='.' && (!vst[x][y]));
}
void init(void) {
	scanf("%d",&m);
	scanf("%d",&n);
	FOR(i,1,m) scanf("%s",a[i]+1);	
}
void BFS(const ii &s) {
	queue<ii> q;
	while (!q.empty()) q.pop();
	vst[s.fi][s.se]=true;
	q.push(s);
	ii p;
	int vx,vy;
	while (!q.empty()) {
		p=q.front();q.pop();
		add_oper(oper('B',p.fi,p.se));
		REP(i,4) {
			vx=p.fi+dx[i];
			vy=p.se+dy[i];
			if (canbuild(vx,vy)) {				
				vst[vx][vy]=true;								
				ch[p.fi][p.se].push_back(ii(vx,vy));
				q.push(ii(vx,vy));
			}
		}
	}
}
void visit(const int &x,const int &y,const bool &b) {
	int vx,vy;
	FORE(it,ch[x][y]) {
		vx=it->fi;
		vy=it->se;
		visit(vx,vy,true);
	}
	if (b) {
		add_oper(oper('D',x,y));
		add_oper(oper('R',x,y));
	}
}
void process(void) {
	FOR(i,1,m) FOR(j,1,n)
		if (canbuild(i,j)) {
			BFS(ii(i,j));
			visit(i,j,false);
		}
	printf("%d\n",res.size());
	FORE(it,res) it->print();
}
int main(void) {
	init();
	process();
	return 0;
}