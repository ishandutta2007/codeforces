#include<algorithm>
#include<cassert>
#include<cstdio>
#include<cstring>
#include<queue>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
struct job {
	int cpl,id;
	job() {
		cpl=0;
		id=0;
	}
	void input(int i) {
		scanf("%d",&cpl);
		id=i;
	}
	bool operator < (const job &x) const {
		return (cpl>x.cpl);
	}
};
struct stu {
	int abi,cst,id;
	stu() {
		abi=0;
		cst=0;
		id=0;
	}
	bool operator < (const stu &x) const {
		return (abi>x.abi);
	}
};
job a[MAX];
stu b[MAX];
int m,n,s;
int fix[MAX];
void init(void) {
	scanf("%d",&n);
	scanf("%d",&m);
	scanf("%d",&s);
	FOR(i,1,m) a[i].input(i);
	FOR(i,1,n) b[i].id=i;
	FOR(i,1,n) scanf("%d",&b[i].abi);
	FOR(i,1,n) scanf("%d",&b[i].cst);
	sort(a+1,a+m+1);
	sort(b+1,b+n+1);
	/*printf("JOBS\n");
	FOR(i,1,m) printf("%d %d\n",a[i].cpl,a[i].id);
	printf("STUS\n");
	FOR(i,1,n) printf("%d %d %d\n",b[i].abi,b[i].cst,b[i].id);*/
}
class comp {
	public:
	bool operator () (const stu &a,const stu &b) const {
		return (a.cst>b.cst);
	}
};
bool ok(int x) {
	//printf("CHECKING %d\n",x);
	priority_queue<stu,vector<stu>,comp> q;
	while (!q.empty()) q.pop();
	int st=1;
	long long all=0LL;
	memset(fix,-1,sizeof fix);
	FOR(i,1,m) if (fix[a[i].id]<0) {
		while (st<=n && b[st].abi>=a[i].cpl) {
			q.push(b[st]);
			st++;
		}
		if (q.empty()) return (false);
		stu tmp=q.top();q.pop();
		all+=tmp.cst;
		if (all>s) return (false);
		REP(j,x) if (i+j<=m) fix[a[i+j].id]=tmp.id;
	}
	return (all<=s);
}
void process(void) {
	int l=1;
	int r=n+7;
	if (!ok(r)) {
		printf("NO\n");
		return;
	}
	int M;
	while (true) {
		if (l==r) {
			M=r;
			break;
		}
		if (r-l==1) {
			if (ok(l)) M=l;
			else M=r;
			break;
		}
		M=(l+r)>>1;
		if (ok(M)) r=M;
		else l=M+1;
	}
	assert(ok(M));	
	printf("YES\n");
	FOR(i,1,m) {
		if (i>1) printf(" ");
		printf("%d",fix[i]);
	}
}
int main(void) {
#ifndef ONLINE_JUDGE
	freopen("tmp.txt","r",stdin);
#endif
	init();
	process();
	return 0;
}