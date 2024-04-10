#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define fi    first
#define se    second
using namespace std;
typedef pair<int,int> ii;
ii a[MAX];
vector<int> hor[MAX],ver[MAX],diag[MAX];
int n;
void init(void) {
	scanf("%d",&n);
	FOR(i,1,n) {
		scanf("%d%d",&a[i].fi,&a[i].se);
		hor[a[i].se].push_back(a[i].fi);
		ver[a[i].fi].push_back(a[i].se);
		diag[a[i].fi+a[i].se].push_back(a[i].se);
	}
	sort(a+1,a+n+1);
	REP(i,MAX) {
		sort(hor[i].begin(),hor[i].end(),greater<int>());
		sort(ver[i].begin(),ver[i].end());
		sort(diag[i].begin(),diag[i].end());
	}
}
inline bool found(int x,int y) {
	return (binary_search(a+1,a+n+1,ii(x,y)));
}
int count(int x,int y) {
	int ih=lower_bound(hor[y].begin(),hor[y].end(),x,greater<int>())-hor[y].begin();
	int iv=lower_bound(ver[x].begin(),ver[x].end(),y)-ver[x].begin();
	int id=lower_bound(diag[x+y].begin(),diag[x+y].end(),y)-diag[x+y].begin();
	int sh=hor[y].size()-ih;
	int sv=ver[x].size()-iv;
	int sd=diag[x+y].size()-id;
	int ret=0;
	if (sh<=sv && sh<=sd) {
		FOR(i,ih+1,hor[y].size()-1) {
			int d=x-hor[y][i];
			if (found(x,y+d) && found(x-d,y+d)) ret++;			
		}
		return (ret);
	}
	if (sv<=sh && sv<=sd) {
		FOR(i,iv+1,ver[x].size()-1) {
			int d=ver[x][i]-y;
			if (found(x-d,y) && found(x-d,y+d)) ret++;
		}
		return (ret);
	}
	if (sd<=sh && sd<=sv) {
		FOR(i,id+1,diag[x+y].size()-1) {
			int d=diag[x+y][i]-y;
			if (found(x-d,y) && found(x,y+d)) ret++;
		}
		return (ret);
	}	
}
void process(void) {
	int res=0;
	FOR(i,1,n) res+=count(a[i].fi,a[i].se);
	printf("%d",res);
}
int main(void) {
	init();
	process();
	return 0;
}