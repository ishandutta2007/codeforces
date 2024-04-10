#include<cstdio>
#define MAX   333
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
int a[MAX];
int n,s;
void process(void) {
	int dir=1;
	int cur=1;
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",&a[i]);
	FOR(i,1,n) s+=a[i];
	while (s>0) {
		if (a[cur]>0) {
			a[cur]--;
			s--;
			printf("P");			
		}
		if (dir==-1) {
			if (cur>1) {
				printf("L");
				cur--;
			}
			else {
				dir=1;
				printf("R");
				cur++;
			}
		}
		else {
			if (cur<n) {
				printf("R");
				cur++;
			}
			else {
				dir=-1;
				printf("L");
				cur--;
			}
		}
	}
}
int main(void) {
	process();
	return 0;
}