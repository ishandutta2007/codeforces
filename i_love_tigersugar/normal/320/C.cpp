#include<cstdio>
#include<cstring>
#define MAX   222
typedef long long ll;
const ll mod=1e9+7;
int n;
char x[MAX];
ll p[MAX];
ll res;
void process(void) {
	scanf("%s",x);
	n=strlen(x);
	int i;
	p[0]=1;
	for (i=1;i<=207;i=i+1) p[i]=(p[i-1]*2)%mod;
	res=0;
	for (i=1;i<=n;i=i+1)
		if (x[i-1]=='1') res=(res+p[i-1]*p[2*(n-i)])%mod;
	printf("%I64d",res);
}
int main(void) {
	process();
	return 0;
}