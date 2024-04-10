#include<cstdio>
#define MAX   500500
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
int h[MAX];
int n,k;
void process(void) {
	scanf("%d",&n);
	scanf("%d",&k);
	FOR(i,1,n) scanf("%d",&h[i]);	
	int s=0;
	FOR(i,1,k) s+=h[i];
	int min=s;
	int id=1;
	FOR(i,2,n-k+1) {
		s+=h[i+k-1]-h[i-1];
		if (min>s) {
			min=s;
			id=i;
		}
	}
	printf("%d",id);
}
int main(void) {
	process();
	return 0;
}