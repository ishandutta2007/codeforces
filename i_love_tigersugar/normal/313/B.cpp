#include<stdio.h>
#include<string.h>
#define MAX   100100
int m,n;
char s[MAX];
int c[MAX];
void init(void) {
	scanf("%s",s);
	n=strlen(s);
	int i;
	c[0]=0;
	for (i=1;i<n;i=i+1) c[i]=c[i-1]+(s[i-1]==s[i]);	
}
void process(void) {
	int l,r,i;
	scanf("%d",&m);
	for (i=1;i<=m;i=i+1) {
		scanf("%d",&l);	
		scanf("%d",&r);
		printf("%d\n",c[r-1]-c[l-1]);
	}
}
int main(void) {
	init();
	process();
	return 0;
}