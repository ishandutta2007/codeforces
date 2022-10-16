#include<cstdio>
#include<cstdlib>
#include<iostream>
#define MAX   222
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
typedef long long ll;
const char none[]="Happy new year!";
struct info {
	ll ex;
	int ea,sc;
	info() {
		ex=0LL;
		ea=0;sc=0;
	}
	info(ll e,int a,int c) {
		ex=e;ea=a;sc=c;
	}
	info operator + (const info &x) const {
		return (info(ex+x.ex+(ea && x.sc),x.ea,sc));
	}
};
info f[MAX];
char s1[MAX];
char s2[MAX];
int k,n,m;
ll x;
void init(void) {
	cin >> k >> x >> n >> m;
}
bool ok(const info &x1,const info &x2) {
	f[1]=x1;
	f[2]=x2;
	FOR(i,3,k) {
		f[i]=f[i-2]+f[i-1];
		if (f[i].ex>x) return (false);
	}
	return (f[k].ex==x);
}
bool build(const info &x,char s[],int n) {
	int req=2*x.ex;
	if (x.sc) req++;
	if (x.ea) req++;
	if (req>n) return (false);
	int id=1;
	if (x.sc) {
		s[id]='C';
		id++;
	}
	REP(i,x.ex) {
		s[id]='A';
		id++;
		s[id]='C';
		id++;
	}
	FOR(i,id,n) s[i]='B';
	if (x.ea) s[n]='A';
	return (true);
}
void process(void) {
	REP(e1,n/2+7) REP(e2,m/2+7) REP(a1,2) REP(c1,2) REP(a2,2) REP(c2,2) {
		info x1=info(e1,a1,c1);
		info x2=info(e2,a2,c2);
		if (ok(x1,x2) && build(x1,s1,n) && build(x2,s2,m)) {
			FOR(j,1,n) printf("%c",s1[j]); printf("\n");
			FOR(j,1,m) printf("%c",s2[j]); printf("\n");
			return;
		}
	}	
	printf("%s",none);
}
int main(void) {
	init();
	process();
	return 0;
}