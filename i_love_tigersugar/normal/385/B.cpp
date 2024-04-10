#include<cstdio>
#include<cstring>
#define MAX   5050
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
const char w[]="bear";
char a[MAX];
int c[MAX];
int n;
void process(void) {
	scanf("%s",a+1);
	n=strlen(a+1);
	FOR(i,1,n) {
		bool ok=true;
		if (i<4) ok=false;
		REP(j,4) if (a[i-3+j]!=w[j]) ok=false;
		c[i]=c[i-1]+ok;
	}
	int res=0;
	FOR(i,1,n) FOR(j,i,n) if (j-i+1>3 && c[j]>c[i+2]) res++;
	printf("%d",res);
}
int main(void) {
	process();
	return 0;
}