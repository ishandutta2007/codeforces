#include<bits/stdc++.h>
#define MAX   100100
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
int c[MAX];
int n;
void process(void) {
	scanf("%d",&n);
	int maxv=0;
	REP(i,n) {
		int v;
		scanf("%d",&v);
		c[v]++;
		if (maxv<v) maxv=v;
	}
	int res=0;
	REP(i,MAX) if (c[i]>0) res++;
	FORD(i,maxv-1,1) if (c[i]>1) res++;
	printf("%d\n",res);
	bool prev=false;
	REP(i,MAX) if (c[i]>0) {
		if (prev) printf(" "); else prev=true;
		printf("%d",i);
	}
	FORD(i,maxv-1,1) if (c[i]>1) printf(" %d",i);
}
int main(void) {
	process();
	return 0;
}