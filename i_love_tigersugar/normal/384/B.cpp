#include<bits/stdc++.h>
#define MAXN   1010
#define MAXM   111
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
vector<ii> sw;
int m,n,k;
int a[MAXN][MAXM];
void init(void) {
	scanf("%d",&n);
	scanf("%d",&m);
	scanf("%d",&k);
	FOR(i,1,n) FOR(j,1,m) scanf("%d",&a[i][j]);
	if (k>0) FOR(i,1,n) reverse(a[i]+1,a[i]+m+1);
}
void process(void) {
	FOR(i,1,m) {
		vector<int> pos;
		FOR(j,1,n) {
			int mid=i;
			FOR(k,i,m) if (a[j][mid]>a[j][k]) mid=k;
			if (mid>i) pos.push_back(mid);
		}
		sort(pos.begin(),pos.end());
		pos.resize(unique(pos.begin(),pos.end())-pos.begin());
		FORE(it,pos) {
			sw.push_back(ii(i,*it));
			FOR(j,1,n) if (a[j][i]>a[j][*it]) swap(a[j][i],a[j][*it]);			
		}
	}
	if (k>0) FORE(it,sw) {
		it->fi=m+1-it->fi;
		it->se=m+1-it->se;
	}
	assert(sw.size()<=m*(m-1)/2);
	printf("%d\n",sw.size());
	FORE(it,sw) printf("%d %d\n",it->fi,it->se);
}
int main(void) {
	init();
	process();
	return 0;
}