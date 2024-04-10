// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=2010;
int i,j,k,ke;
int n,a[maxn];
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int main(){
	n=read();
	for (i=1;i<=n;i++){
		a[i]=read();
	}
	ke=10000;
	printf("%d\n",n+1);
	for (i=n;i>=1;i--){
		k=(ke-(n-i)-1)-(a[i]%ke);
		if (k<0) k=k+ke;
		for (j=1;j<=i;j++){
			a[j]=a[j]+k;
		}
		printf("1 %d %d\n",i,k);
	}
	printf("2 %d %d\n",n,ke);
	return 0;
}