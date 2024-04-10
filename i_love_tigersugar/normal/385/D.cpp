#include<cmath>
#include<cstdio>
#define MAX   20
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
const double INF=1e9;
const double eps=1e-9;
const double PI=acos(-1.0);
struct light {
	int x,y,d;
	double deg;
	light(){
		x=0;y=0;deg=0;d=0;
	}
	void input(void) {
		scanf("%d",&x);
		scanf("%d",&y);
		scanf("%d",&d);
		deg=d*PI/180;
	}
	double next(const double &cur) const {
		double cd=atan(fabs(cur-x)/y);
		if (cur<x) cd=-cd;
		double nd=cd+deg;
		if (nd>PI/2.0) return (INF);
		if (nd<0.0) return (x-tan(-nd)*y);
		else return (x+tan(nd)*y);
	}
};
double f[(1<<MAX)+7];
void maximize(double &x,const double &y) {
	if (x+eps<y) x=y;
}
int bit(int x,int i) {
	return ((x|(1<<i))==x);
}
light a[MAX+7];
int n,l,r;
void process(void) {
	scanf("%d",&n);
	scanf("%d",&l);
	scanf("%d",&r);
	REP(i,n) a[i].input();
	f[0]=l;	
	FOR(i,1,(1<<n)-1) {
		f[i]=-INF;
		REP(j,n) if (bit(i,j)) {
			maximize(f[i],a[j].next(f[i-(1<<j)]));
			if (f[i]>r+eps) {
				printf("%d",r-l);
				return;
			}
		}		
	}
	printf("%.9lf",f[(1<<n)-1]-l);
}
int main(void) {
	process();
	return 0;	
}