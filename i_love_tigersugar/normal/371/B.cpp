#include<cstdio>
#include<queue>
#include<map>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
const int div[]={2,3,5};
const int INF=(int)1e9+7;
map<int,int> da,db;
int a,b;
void minimize(int &x,const int &y) {
	if (x>y) x=y;
}
void init(void) {
	scanf("%d",&a);
	scanf("%d",&b);
}
void divide(int x,map<int,int> &d) {
	queue<int> q;
	while (!q.empty()) q.pop();
	q.push(x);
	d[x]=0;
	while (!q.empty()) {
		int u=q.front();q.pop();
		int v=d[u];
		REP(i,3) if (u%div[i]==0) 
			if (d.find(u/div[i])==d.end()) {
				d[u/div[i]]=v+1;
				q.push(u/div[i]);
			}		
	}	
}
void process(void) {
	int res=INF;
	divide(a,da);
	divide(b,db);
	FORE(it,da) if (db.find(it->fi)!=db.end())
		minimize(res,it->se+db[it->fi]);
	if (res>=INF) printf("-1");
	else printf("%d",res);
}
int main(void) {
	init();
	process();
	return 0;
}