#include<cstdio>
#include<vector>
#define MAX   1000100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
const int maxc=(int)1e6+7;
vector<ii> query[MAX];
vector<int> inter[MAX];
int t[MAX];
int res[MAX];
int n,q;
void update(int x) {
	while (1<=x && x<=maxc) {
		t[x]++;
		x+=x&(-x);
	}
}
int get(int x) {
	int ret=0;
	while (1<=x && x<=maxc) {
		ret+=t[x];
		x=x&(x-1);
	}
	return (ret);
}
int sum(const int &x,const int &y) {
	if (x>y) return (0);
	return (get(y)-get(x-1));
}
void readinp(void) {
	scanf("%d",&n);
	scanf("%d",&q);
	int t,l,r;
	REP(i,n) {
		scanf("%d",&l);
		scanf("%d",&r);
		inter[r].push_back(l);		
	}
	REP(i,q) {
		l=0;
		scanf("%d",&t);
		REP(j,t) {
			scanf("%d",&r);
			if (l+1<=r-1) query[r-1].push_back(ii(l+1,i));
			l=r;
		}
		query[maxc].push_back(ii(l+1,i));
	}	
}
void answer(void) {
	REP(i,maxc+1) {
		FORE(j,inter[i]) update(*j);
		FORE(j,query[i]) res[j->se]+=sum(j->fi,i);
	}	
	REP(i,q) printf("%d\n",n-res[i]);
}
int main(void) {
#ifndef ONLINE_JUDGE
	freopen("tmp.txt","r",stdin);
#endif
	readinp();
	answer();
	return 0;
}