#include<bits/stdc++.h>
#define MAXN   300300
#define MAXS   60
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
typedef pair<int,int> ii;
typedef set<int>::iterator sit;
set<int> s;
int a[MAXN];
ii b[MAXN];
int n;
bool cmp(const ii &a,const ii &b) {
	if (a.fi>b.fi) return (true);
	if (a.fi<b.fi) return (false);
	return (a.se<b.se);
}
void init(void) {
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",&a[i]);
	FOR(i,1,n) b[i]=ii(a[i],i);
	sort(b+1,b+n+1,cmp);	
}
void process(void) {
	double S=0.0;
	s.insert(0);
	s.insert(n+1);
	FOR(i,1,n) {
		double L=0.0;
		double R=0.0;
		sit it=s.insert(b[i].se).fi;
		sit jt=it;
		int prev=*it;
		REP(j,MAXS) {
			jt--;
			L=L+1.0*(prev-*jt)/(1LL<<j);
			if (*jt<1) break;
			prev=*jt;
		}
		jt=it;
		prev=*it;
		REP(j,MAXS) {
			jt++;
			R=R+1.0*(*jt-prev)/(1LL<<j);
			if (*jt>n) break;
			prev=*jt;
		}		
		S=S+b[i].fi*L*R/2.0;
	}
	printf("%.9lf",S/n/n);
}
int main(void) {
	init();
	process();
	return 0;
}