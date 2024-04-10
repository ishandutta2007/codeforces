// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=300010;
long long i,j,k;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int T,opt;
long long n,a[maxn];
long long tot,x;
int main(){
	
	T=read();
	for (opt=1;opt<=T;opt++){
		n=read(); tot=0;
		for (i=1;i<=n;i++) a[i]=read();
		for (i=1;i<=n;i++){
			tot=tot+a[i];
		}
		if (tot%n!=0){
			printf("-1\n");
			continue;
		}
		printf("%lld\n",n*3-3);
		for (i=2;i<=n;i++){
			if (i-(a[i]%i)!=i) x=i-(a[i]%i); else x=0;
			printf("1 %lld %lld\n",i,x);
			a[i]=a[i]+x; a[1]=a[1]-x;
			printf("%lld 1 %lld\n",i,a[i]/i);
			a[1]=a[1]+a[i]; a[i]=0;
		}
		for (i=2;i<=n;i++){
			printf("1 %lld %lld\n",i,tot/n);
		}
	}
	
	return 0;
}