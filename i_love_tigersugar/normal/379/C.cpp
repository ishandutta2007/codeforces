#include<algorithm>
#include<cstdio>
#define MAX   300300
#define FOR(i,a,b) for(int i=(a);i<=(b);i=i+1)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
ii a[MAX];
ii b[MAX];
int n;
bool cmp(const ii &a,const ii &b) {
	return (a.se<b.se);
}
void init(void) {
	scanf("%d",&n);
	FOR(i,1,n) {
		scanf("%d",&a[i].fi);
		a[i].se=i;
	}
	sort(a+1,a+n+1);
}
void optimize(void) {
	FOR(i,1,n) {
		b[i].se=a[i].se;
		b[i].fi=max(b[i-1].fi+1,a[i].fi);
	}
	sort(b+1,b+n+1,cmp);
	FOR(i,1,n) {
		if (i>1) printf(" ");
		printf("%d",b[i].fi);
	}
}
int main(void) {
	init();
	optimize();
	return 0;
}