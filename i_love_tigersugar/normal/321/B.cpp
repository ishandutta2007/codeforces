#include<set>
#include<cstdio>
#include<algorithm>
#define MAX   111
#define fi   first
#define se   second
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,a,b) for (int i=(a);i>=(b);i=i-1)
#define REP(i,n) for (int=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
typedef pair<int,int> ii;
multiset<int> ciel;
int fox[MAX];
ii jiro[MAX];
int m,n;
template<class T>
	void maximize(T &x,const T &y) {
		if (x<y) x=y;
	}
void init(void) {
	scanf("%d",&m);
	scanf("%d",&n);
	char type[13];	
	FOR(i,1,m) {
		scanf("%s",type);
		if (type[0]=='A') jiro[i].fi=-1;
		else jiro[i].fi=1;
		scanf("%d",&jiro[i].se);
	}
	FOR(i,1,n) {
		scanf("%d",&fox[i]);
		ciel.insert(fox[i]);
	}
	sort(jiro+1,jiro+m+1);
	sort(fox+1,fox+n+1,greater<int>());
}
int killall(void) {
	int ret=0;
	multiset<int>::iterator it;
	FORD(i,m,1) {
		if (ciel.empty()) return (-1);
		if (jiro[i].fi<0) it=ciel.lower_bound(jiro[i].se);
		else it=ciel.upper_bound(jiro[i].se);
		if (it==ciel.end()) return (-1);
		if (jiro[i].fi<0) ret+=*it-jiro[i].se;			
		ciel.erase(it);
		//printf("Set info:\n");
		//FORE(it,ciel) printf("%d ",*it);
		//printf("\n");
	}
	FORE(it,ciel) ret+=*it;
	return (ret);
}
int killsub(const int &k) {
	if (k>m || k>n) return (-1);
	FOR(i,1,k) if (jiro[i].fi>0) return (-1);
	FOR(i,1,k) if (jiro[i].se>fox[k+1-i]) return (-1);
	int ret=0;
	FOR(i,1,k) ret+=fox[i]-jiro[i].se;
	return (ret);
}
void process(void) {
	int res=0;
	maximize(res,killall());
	FOR(i,1,m) maximize(res,killsub(i));
	printf("%d",res);
}
int main(void) {
	init();
	process();
	return 0;
}