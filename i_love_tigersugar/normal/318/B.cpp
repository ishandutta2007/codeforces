#include<cstdio>
#include<cstring>
#include<cstdlib>
#define MAX   1001001
typedef long long ll;
const char f[]="heavy";
const char l[]="metal";
int n;
ll r;
char s[MAX];
ll c[MAX];
ll fst(int i) {
	int j;
	for (j=0;j<5;j=j+1)
		if (s[i+j]!=f[j]) return (0);
	return (1);
}
ll lst(int i) {
	int j;
	for (j=0;j<5;j=j+1)
		if (s[i+j]!=l[j]) return (0);		
	return (1);
}
void process(void) {
	r=0;
	scanf("%s",s);
	n=strlen(s);	
	if (n<10) {
		printf("0");
		exit(0);
	}
	int i;	
	for (i=1;i<5;i=i+1) c[n-i]=0;
	for (i=n-5;i>=0;i=i-1)
		c[i]=c[i+1]+lst(i);
	r=0;
	for (i=0;i<=n-10;i=i+1)
		if (fst(i)>0) r=r+c[i+5];	
	printf("%I64d",r);
}
int main(void) {	
	//freopen("tmp.txt","r",stdin);
	process();
	return 0;
}