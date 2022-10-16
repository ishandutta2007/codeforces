#include<cstdio>
#include<cstring>
#define MAX   2020
char s[MAX];
int n,l;
int r,i;
int main(void) {
	scanf("%d",&n);
	scanf("%s",s);
	l=strlen(s);
	r=0;
	for (i=0;i<l;i=i+1)
		if (i%n==0 && i>2) r=r+(s[i-1]==s[i-2] && s[i-2]==s[i-3]);
	printf("%d",r);
	return 0;
}