#include<cstdio>
#define REP(i,n) for (int i=0;i<(n);i=i+1)
int n,p,q;
int main(void) {
	scanf("%d",&n);
	scanf("%d",&p);
	scanf("%d",&q);
	int res=0;
	int t;
	REP(i,n) {
		scanf("%d",&t);
		if (t==1) {
			if (p==0) res++;
			else p--;
		}
		else {
			if (q>0) q--;
			else {
				if (p>0) p--;
				else res++;
			}
		}
	}
	printf("%d",res);
	return 0;
}