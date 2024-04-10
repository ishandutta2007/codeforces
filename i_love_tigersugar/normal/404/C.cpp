#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
vector<int> d[MAX];
int n,k;
vector<ii> res;
void init(void) {
	scanf("%d%d",&n,&k);
	FOR(i,1,n) {
		int v;
		scanf("%d",&v);
		d[v].push_back(i);
	}
}
void process(void) {
	if (d[0].size()!=1) {
		printf("-1");
		return;
	}
	FOR(i,1,n-1) {
		int t=k;
		if (i>1) t--;
		if (d[i].size()>1LL*d[i-1].size()*t) {
			printf("-1");
			return;
		}
		int id=-1;
		REP(j,d[i].size()) {
			if (j%t==0) id++;
			assert(id<d[i-1].size());
			res.push_back(ii(d[i-1][id],d[i][j]));
			if (res.size()>1000000) {
				printf("-1");
				return;
			}
		}
	}
	printf("%d\n",res.size());
	FORE(it,res) printf("%d %d\n",it->fi,it->se);
}
int main(void) {
	init();
	process();
	return 0;
}