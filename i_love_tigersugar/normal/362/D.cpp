#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
const int INF=(int)1e9;
int s[MAX];
int up[MAX];
int m,n,p,r,cnt;
vector<ii> res;
int min(const int &x,const int &y) {
	if (x<y) return (x); else return (y);
}
class compare {
	public:
	bool operator () (const int &x,const int &y) const {
		return (s[x]>s[y]);
	}
};
void add(int &x,const int &y) {
	x=x+y;
	if (x>INF) x=INF;
}
int find(const int &x) {
	if (up[x]<0) return (x);
	up[x]=find(up[x]);
	return (up[x]);
}
void join(const int &u,const int &v,const int &w) {
	int x=find(u);
	int y=find(v);
	add(s[x],w);	
	if (x==y) return;
	add(s[x],s[y]);
	up[y]=x;
}
void exit_no(void) {
	printf("NO");
	exit(0);
}
void loadgraph(void) {
	scanf("%d",&n);
	scanf("%d",&m);
	scanf("%d",&p);
	scanf("%d",&r);
	int u,v,w;
	FOR(i,1,n) up[i]=-1;
	REP(i,m) {
		scanf("%d",&u);
		scanf("%d",&v);
		scanf("%d",&w);
		join(u,v,w);
	}	
}
void check_exist(void) {
	if (n==1) {
		if (p>0) printf("NO");
		else {
			if (r==1) printf("YES");
			else printf("NO");			
		}
		exit(0);
	}
	cnt=0;
	FOR(i,1,n) if (up[i]<0) cnt++;
	if (cnt<r || p<cnt-r) exit_no();
}
void add_edge(const int &x,const int &y) {
	res.push_back(ii(x,y));
}
void add_to_join(void) {
	priority_queue<int,vector<int>,compare> q;
	while (!q.empty()) q.pop();
	FOR(i,1,n) if (up[i]<0) q.push(i);
	int u,v;
	REP(i,cnt-r) {
		p--;
		if (p<0 || q.size()<2) exit_no();
		u=q.top();q.pop();
		v=q.top();q.pop();
		add_edge(u,v);
		join(u,v,min(INF,s[u]+s[v]+1));
		q.push(find(u));
	}
}
void add_no_join(void) {
	int u,v;
	if (p<=0) return;
	FOR(i,1,n) if (up[i]>0) {
		u=up[i];
		v=i;
		REP(j,p) add_edge(u,v);
		return;
	}
	exit_no();	
}
void print(void) {
	printf("YES\n");
	FORE(it,res) printf("%d %d\n",it->fi,it->se);
}
int main(void) {
	loadgraph();
	check_exist();
	add_to_join();
	add_no_join();
	print();
	return 0;
}