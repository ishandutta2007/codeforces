#include<cstdio>
#include<cassert>
#define MAX   2013
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
int n,k,l,r,sall,sk;
int ans[MAX];
void init(void) {
	scanf("%d",&n);
	scanf("%d",&k);
	scanf("%d",&l);
	scanf("%d",&r);	
	scanf("%d",&sall);	
	scanf("%d",&sk);
}
void choose1(void) {
	int tmp=sk/k;
	int cur=sk%k;
	FOR(i,1,k) ans[i]=tmp;
	FOR(i,1,cur) ans[i]++;	
}
void choose2(void) {
	int lim=ans[k];
	int cur;
	int rest=sall-sk;
	if (k==n) return;
	FOR(i,k+1,n-1) {
		cur=lim;
		while (rest-cur<l*(n-i)) cur--;
		lim=cur;
		ans[i]=cur;
		rest-=cur;
	}
	ans[n]=rest;
}
void print(void) {
	FOR(i,1,n) {
		assert(ans[i]>=l && ans[i]<=r);		
		if (i>1) printf(" ");
		printf("%d",ans[i]);
	}
}
int main(void) {
	init();
	choose1();
	choose2();
	print();
	return 0;
}