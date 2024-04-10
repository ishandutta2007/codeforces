// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
long long i,j,k;
long long read(){
	long long tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
long long a[maxn],n;
int main(){
	
	n=read();
	for (i=1;i<=n;i++){
		a[i]=read();
	}
	if (n==1){
		printf("1 1\n");
		printf("1\n");
		printf("1 1\n");
		printf("1\n");
		a[1]=a[1]+2;
		printf("1 1\n");
		printf("%lld\n",-a[1]);
		return 0;
	}
	printf("1 %lld\n",n);
	for (i=1;i<=n;i++){
		printf("%lld ",n*((n-1)-((a[i]+(n-1)*((long long)1e9))%(n-1))));
		a[i]=a[i]+n*((n-1)-((a[i]+(n-1)*((long long)1e9))%(n-1)));
	}
	printf("\n");
	printf("1 1\n");
	printf("%lld\n",-a[1]);
	printf("2 %lld\n",n);
	for (i=2;i<=n;i++){
		printf("%lld ",-a[i]);
	}
	printf("\n");
	
	return 0;
}